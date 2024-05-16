// Cheapest Fare with K Stops
//  Problem statement
//  Ninja likes to travel a lot, but at the same time, he wants to save as much money as possible.

// There are ‘N’ Stations connected by ‘M’ Trains. Each train that he boards starts from station ‘A’
// and reaches destination station ‘B’ with a ticket price ‘P’.

// Your task is to return the cheapest price from the given ‘source’ to ‘destination’ with up to ‘K’ stops.
// If there is no such route, return ‘-1’.

// Link : https://www.naukri.com/code360/problems/saving-money_1171195

// Intuition:
// We will find the shortest path from the source to the destination with at most K stops by using the BFS traversal.
// We will keep track of the number of stops while finding the shortest path and increment it by 1 for each stop(breadth).
// If we exceed the number of stops then we will not consider that path.

// Time complexity: O(ElogV)
// Space complexity: O(V)

// Code:
int savingMoney(int n, int source, int destination, int K,
                vector<vector<int>> &trains)
{
    // Create adjacency list
    vector<vector<pair<int, int>>> adj_list(n);
    for (auto trainRoute : trains)
    {
        int st1 = trainRoute[0];
        int st2 = trainRoute[1];
        int cost = trainRoute[2];
        adj_list[st1].push_back({cost, st2});
    }

    vector<int> costs(n, INT_MAX);
    costs[source] = 0;
    //   {stops,{currCost,currNode}}
    queue<pair<int, pair<int, int>>> q;

    q.push({0, {0, source}});

    while (!q.empty())
    {

        auto it = q.front();
        q.pop();
        int currStop = it.first;
        int currCost = it.second.first;
        int currNode = it.second.second;

        if (currStop > K)
            continue; // Skip if number of stops exceeds K

        for (auto adjIT : adj_list[currNode])
        {
            int cost = adjIT.first;
            int adjNode = adjIT.second;
            if (currCost + cost < costs[adjNode])
            {
                costs[adjNode] = currCost + cost;
                q.push({currStop + 1, {currCost + cost, adjNode}});
            }
        }
    }

    return costs[destination] != INT_MAX ? costs[destination] : -1;
}
