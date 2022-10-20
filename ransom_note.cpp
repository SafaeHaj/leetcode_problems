#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, pair<int, int>> compare;

    // map contains the elements and a pair of the number of their occurrences in each string
    for (int i = 0; i < magazine.size(); i++)
    {
        compare[magazine[i]].second++;
    }

    for (int i = 0; i < ransomNote.size(); i++)
    {
        compare[ransomNote[i]].first++;

        if (compare[ransomNote[i]].first > compare[ransomNote[i]].second)
            return false;
    }

    return true;
}