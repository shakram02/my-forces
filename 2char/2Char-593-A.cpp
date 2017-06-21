#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef set<char> CharSet;
typedef map<string, int> StrMap;

bool get_valid_charset(const string &, string &);
int max_of_doubles(StrMap &);
int max_of_charset(string, StrMap &);
int max_of_singles(const CharSet &, StrMap &, char &);

int main()
{
    int word_count = 0;
    cin >> word_count;

    string words[word_count];
    CharSet singles;
    StrMap chosen_words;

    for (int i = 0; i < word_count; i++)
    {
        cin >> words[i];
    }

    for (const string &st : words)
    {
        string charset = "";

        if (!get_valid_charset(st, charset))
        {
            continue;
        }

        sort(charset.begin(), charset.end());

        if (charset.length() == 1)
        {
            singles.insert(charset[0]);
        }

        if (!chosen_words.count(charset))
        {
            chosen_words[charset] = st.length();
        }
        else
        {
            chosen_words[charset] = chosen_words[charset] + st.length();
        }
    }

#ifndef ONLINE_JUDGE
    for (const auto &p : chosen_words)
    {
        std::cout << "[" << p.first << "] = " << p.second << '\n';
    }
#endif
    char max_ch;

    // Knapsack like
    int max_singles = max_of_singles(singles, chosen_words, max_ch);
    singles.erase(max_ch);
    max_singles += max_of_singles(singles, chosen_words, max_ch);

    cout << max(max_singles, max_of_doubles(chosen_words)) << endl;
    return 0;
}

int max_of_doubles(StrMap &str_map)
{
    int max = 0;

    for (const auto &p : str_map)
    {
        if (p.first.length() == 1)
        {
            continue;
        }

        int sing_val = max_of_charset(p.first, str_map);

#ifndef ONLINE_JUDGE
        cout << "Charset:" << p.first << " Count:" << sing_val << endl;
#endif

        if (sing_val > max)
        {
            max = sing_val;
        }
    }

    return max;
}

int max_of_singles(const CharSet &cset, StrMap &strings_map, char &max_c)
{
    int max = 0;
    for (const auto &p : cset)
    {
        int sing_val = strings_map[{p}];
        if (sing_val > max)
        {
            max_c = p;
            max = sing_val;
        }
    }

    return max;
}

int max_of_charset(string chset, StrMap &m)
{
    int result = 0;

    for (const char &p : chset)
    {
        result += m[{p}];
    }
    return result + m[chset];
}

bool get_valid_charset(const string &s, string &charset)
{
    CharSet head = {s[0]};
    int count = 1;

    for (const char &c : s)
    {
        if (!head.count(c))
        {
            count++;
            head.insert(c);
            if (count > 2)
            {
                return false;
            }
        }
    }
    charset = string(head.begin(), head.end());
    return true;
}
