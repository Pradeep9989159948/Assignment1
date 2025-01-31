#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <string>

using namespace std;


struct Vertex {
    string id;
    int cost;

    Vertex(string i, int c) : id(i), cost(c) {}

   
    bool operator>(const Vertex& other) const {
        return cost > other.cost;
    }
};


pair<int, vector<string>> dijkstraAlgorithm(const unordered_map<string, unordered_map<string, int>>& graph, const string& source, const string& destination) {
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> minHeap;
    unordered_map<string, int> minCost;
    unordered_map<string, string> pathTrace;

    
    for (const auto& entry : graph) {
        minCost[entry.first] = numeric_limits<int>::max();
    }
    minCost[source] = 0;

    minHeap.push(Vertex(source, 0));

    while (!minHeap.empty()) {
        Vertex current = minHeap.top();
        minHeap.pop();

        if (current.id == destination) {
            
            vector<string> path;
            for (string at = destination; !at.empty(); at = pathTrace[at]) {
                path.insert(path.begin(), at);
            }
            return {minCost[destination], path};
        }

        for (const auto& neighbor : graph.at(current.id)) {
            int newCost = minCost[current.id] + neighbor.second;
            if (newCost < minCost[neighbor.first]) {
                minCost[neighbor.first] = newCost;
                pathTrace[neighbor.first] = current.id;
                minHeap.push(Vertex(neighbor.first, newCost));
            }
        }
    }

    
    return {numeric_limits<int>::max(), {}};
}

int main() {
    
    unordered_map<string, unordered_map<string, int>> graph = {
        {"A", {{"B", 10}, {"E", 3}}},
        {"B", {{"E", 4}, {"C", 2}}},
        {"C", {{"D", 9}}},
        {"D", {{"C", 7}}},
        {"E", {{"B", 1}, {"D", 2}, {"C", 8}}}
    };

    
    string start, end;
    cout << "Enter the starting node: ";
    cin >> start;
    cout << "Enter the ending node: ";
    cin >> end;

    
    auto result = dijkstraAlgorithm(graph, start, end);

    
    if (result.first == numeric_limits<int>::max()) {
        cout << "There is no path from " << start << " to " << end << "." << endl;
    } else {
        cout << "The cost of the shortest path from " << start << " to " << end << " is " << result.first << "." << endl;
        cout << "The shortest path is: ";
        for (const auto& node : result.second) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
