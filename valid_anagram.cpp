#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    tuple<int, int> compare[26];

    for (int i = 0; i < s.size(); i++)
    {
        get<0>(compare[s[i] - 'a'])++;
        get<1>(compare[t[i] - 'a'])++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (get<0>(compare[i]) != get<1>(compare[i]))
            return false;
    }

    return true;
}