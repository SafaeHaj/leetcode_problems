#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> char_table;

    for (int i = 0; i < s.size(); i++) {
        char_table[s[i]]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " " << char_table[s[i]] << endl;
        if (char_table[s[i]] == 1)
            return i;
    }

    return -1;
}