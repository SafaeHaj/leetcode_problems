#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int min = INT_MAX, profit = 0, i = 0;

    while (i < prices.size())
    {
        if (min > prices.at(i))
        {
            min = prices.at(i++);
        }
        else
        {
            profit = max(profit, prices.at(i++) - min);
        }
    }

    return profit;
}