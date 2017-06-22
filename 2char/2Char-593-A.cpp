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
int expand_charset_score(string &charset, StrMap &str_map);
int max_val(string &key, StrMap &str_map);

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

    for (const auto &p : chosen_words)
    {
        string key = p.first;
        chosen_words[key] = expand_charset_score(key, chosen_words);
    }

#ifndef ONLINE_JUDGE
    for (const auto &p : chosen_words)
    {
        string key = p.first;
        std::cout << "[" << key << "] = " << p.second << '\n';
    }
#endif

    string max_key = "";
    // char max_ch;
    // Knapsack like
    // int max_singles = max_of_singles(singles, chosen_words, max_ch);
    // singles.erase(max_ch);
    // max_singles += max_of_singles(singles, chosen_words, max_ch);

    int max = max_val(max_key, chosen_words);

    if (max_key.length() != 2)
    {
        chosen_words.erase(max_key);
        int temp_max = 0;

        // Find the 2nd highest char
        for (const auto &p : chosen_words)
        {
            if (p.first.length() > 1)
            {
                continue;
            }
            if (p.second > temp_max)
            {
                temp_max = p.second;
            }
        }

        max += temp_max;
    }

    cout << max << endl;

    return 0;
}

int expand_charset_score(string &charset, StrMap &str_map)
{
    int score = 0;

    if (charset.length() > 1)
    {
        score += str_map[charset];
    }

    for (const char &c : charset)
    {
        string ch = {c};
        if (str_map.count(ch))
        {
            score += str_map[ch];
        }
    }

    return score;
}

int max_val(string &key, StrMap &str_map)
{
    int max = 0;
    for (const auto &p : str_map)
    {
        if (p.second > max)
        {
            key = p.first;
            max = p.second;
        }
    }

    return max;
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
