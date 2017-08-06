#include <iostream>
#include <string>
#include <vector>

using namespace std;

// TODO: check RGB
bool rgb_check[3] = {false};

bool update_colors(char new_color, char old_color, int i) {
  // Check rgb
#ifndef ONLINE_JUDGE
  cout << "check " << new_color << " , " << old_color << endl;
#endif

  if (new_color == old_color && i != 0) {
    return true;
  }

  switch (new_color) {
    case 'R':
      if(rgb_check[0]){return false;}
      rgb_check[0] = true;
      break;
    case 'G':
      if(rgb_check[1]){return false;}
      rgb_check[1] = true;
      break;
    case 'B':
      if(rgb_check[2]){return false;}
      rgb_check[2] = true;
      break;
  }

  return true;
}

void fail() {
  cout << "NO" << endl;
  exit(0);
}

vector<int> stripes;

void add_stripe(unsigned int& stripe_width, char& old_color,
                char stripe_color) {
#ifndef ONLINE_JUDGE
  cout << "old: " << old_color << " new:" << stripe_color
       << " width:" << stripe_width << endl;
#endif

  old_color = stripe_color;

  stripes.push_back(stripe_width);
  stripe_width = 1;  // Stripe starts at width 1
}

void reset(unsigned int& local_width) {
  for (unsigned int i = 0; i < 3; i++) {
    rgb_check[i] = false;
  }
  local_width = 0;
  stripes.clear();
}

int main() {
  unsigned int rows, cols;
  cin >> rows;
  cin >> cols;
  string flag[rows];

  // Read end of line in first row
  string dummy;
  getline(cin, dummy);

  for (unsigned int i = 0; i < rows; i++) {
    string s;
    getline(cin, s);
    flag[i] = s;

#ifndef ONLINE_JUDGE
    cout << flag[i] << endl;
#endif
  }

  //----------------------------------------------------

  // Scan horizontal stripes
  bool flawed_horizontal_stripe = false;

  char stripe_color = flag[0][0];
  char old_color = flag[0][0];

  unsigned int local_stripe_width = 0;
  for (unsigned int i = 0; i < rows; i++) {
    stripe_color = flag[i][0];

    if (!update_colors(stripe_color, old_color,i)) {
#ifndef ONLINE_JUDGE
      cout << "Color already visisted" << endl;
#endif
      fail();
    }

    for (unsigned int j = 0; j < flag[i].length(); j++) {
      char c = flag[i][j];

      if (stripe_color != c) {
        flawed_horizontal_stripe = true;
        break;  // Skip
      }
    }

    // Break out of checking horizontally
    if (flawed_horizontal_stripe) {
// Since stripes should be parallel, no horizontal stripes will count
#ifndef ONLINE_JUDGE
      cout << "Flawed horizontal stripe" << endl;
#endif
      reset(local_stripe_width);
      break;
    }

    if (stripe_color != old_color) {
      add_stripe(local_stripe_width, old_color, stripe_color);
    } else {
      local_stripe_width++;
    }
  }

  if (!flawed_horizontal_stripe) {
    stripes.push_back(local_stripe_width);
  }

  // -------------------Vertical---------------------
  bool flawed_vertical_stripe = false;

  if (stripes.size() == 0) {
    stripe_color = flag[0][0];
    old_color = flag[0][0];

    // Vertical check
    for (unsigned int i = 0; i < flag[0].length(); i++) {
      // Vertical stripe start at row 0 and ith col
      stripe_color = flag[0][i];
      // TODO: check stripe width and rgb

      if (!update_colors(stripe_color, old_color,i)) {
#ifndef ONLINE_JUDGE
        cout << "Color already visisted" << endl;
#endif
        fail();
      }

      for (unsigned int j = 0; j < rows; j++) {
        char c = flag[j][i];
#ifndef ONLINE_JUDGE
        cout << c << ","<< rows << endl;
#endif
        if (stripe_color != c) {
          flawed_vertical_stripe = true;
          break;
        }
      }

      if (flawed_vertical_stripe) {
#ifndef ONLINE_JUDGE
        cout << "Flawed verical stripe" << endl;
#endif
        reset(local_stripe_width);
        break;
      }

      if (stripe_color != old_color) {
        add_stripe(local_stripe_width, old_color, stripe_color);
      } else {
        local_stripe_width++;
      }
    }

    if (!flawed_vertical_stripe) {
      stripes.push_back(local_stripe_width);
    }
    
  }

  //--------------------------End------------------------------

  if (flawed_horizontal_stripe && flawed_vertical_stripe) {
    fail();
  }

  if (stripes.size() > 1) {
    for (unsigned int i = 0; i <= stripes.size() - 2; i++) {
      if (stripes[i] != stripes[i + 1]) {
        fail();
      }
    }
  }

  for(unsigned int i=0; i < 3; i++)
  {
    if(!rgb_check[i]){
      fail();
    }
  }

  cout << "YES" << endl;
  return 0;
}
