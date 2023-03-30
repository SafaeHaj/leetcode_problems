#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool match(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

bool isValid(string s)
{
    stack<char> open;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            open.push(s[i]);

        else
        {
            if (open.empty() || !match(open.top(), s[i]))
                return false;
            else
                open.pop();
        }
    }

    return open.empty();
}
