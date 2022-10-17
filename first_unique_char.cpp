#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> char_table;

    for (int i = 0; i < s.size(); i++)
    {
        if (char_table[s[i]] != 1)
            char_table[s[i]] = 1;

        else
            cout << s[i] << " " << i << endl;
            char_table[s[i]] = 2;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (char_table[s[i]] == 1)
            return i;
    }

    return -1;
}

int main()
{
    string s = "aadadaad";

    cout << firstUniqChar(s) << endl;
}