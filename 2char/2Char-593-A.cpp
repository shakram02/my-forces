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
int expand_charset_score(string &charset, StrMap &str_map);
int max_val(string &key, StrMap &str_map, int chst_len);

int main()
{
    int word_count = 0;
    cin >> word_count;

    string words[word_count];
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
#ifndef ONLINE_JUDGE
        std::cout << "[" << key << "] = " << p.second << '\n';
#endif
    }

    string max_key = "";

    int max_two = max_val(max_key, chosen_words, 2);

    int max_one = max_val(max_key, chosen_words, 1);
    chosen_words.erase(max_key);
    max_one += max_val(max_key, chosen_words, 1);

    cout << max(max_two, max_one) << endl;

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

int max_val(string &key, StrMap &str_map, int chst_len)
{
    int max = 0;
    for (const auto &p : str_map)
    {
        if ((int)p.first.length() != chst_len)
        {
            continue;
        }
        if (p.second > max)
        {
            key = p.first;
            max = p.second;
        }
    }

    return max;
}

bool get_valid_charset(const string &s, string &charset)
{
    CharSet head = {s[0]};
    int count = 1;

    for (const char &c : s)
    {
        if (head.count(c))
        {
            continue;
        }

        count++;
        head.insert(c);
        if (count > 2)
        {
            return false;
        }
    }
    charset = string(head.begin(), head.end());
    return true;
}
