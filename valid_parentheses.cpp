#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool match(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
        return true;

    return false;
}

bool isValid(string s)
{
   stack<char> open;
    int i = 0;

    while (s[i] != '\0')
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

        i++;
    }

    if (open.empty())
        return true;

    return false;
}