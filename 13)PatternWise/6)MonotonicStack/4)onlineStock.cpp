// Online Stock Span
// https://leetcode.com/problems/online-stock-span
#include <iostream>
#include <stack>
using namespace std;

class StockSpanner
{
private:
    // Stack to store pairs of (price, span)
    // The stack will maintain prices in decreasing order (monotonic stack)
    stack<pair<int, int>> s;

public:
    StockSpanner()
    {
        // Initialize the stack as empty
    }

    int next(int price)
    {
        int span = 1; // At minimum, today's span is 1 (today itself)

        /*
         * Intuition:
         * We want to find how many consecutive previous days (including today)
         * had a price less than or equal to today’s price.
         * Instead of scanning all previous prices, we use a stack to keep track
         * of only "useful" previous prices in decreasing order.
         *
         * Each item in the stack is a pair (prev_price, span_of_that_price).
         * When we see a price <= today's price, we can "merge" its span into
         * today's span and pop it — because it won't help future prices anymore.
         */

        // While there are prices on the stack <= today's price
        while (!s.empty() && s.top().first <= price)
        {
            /*
             * If the previous price is less than or equal to current,
             * it means the span of that previous price can be added to today's span.
             * So we add its span to current, and remove it from the stack.
             */
            span += s.top().second;
            s.pop();
        }

        // Push current price and its total span onto the stack
        s.push({price, span});

        // Return the computed span for today
        return span;
    }
};
