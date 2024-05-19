#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> path, longestCycle;
int maxCycleLength = 0;
int Nodes, Edges;

void read(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Unable to open file";
        exit(1);
    }

    infile >> Nodes >> Edges;
    adj.resize(Nodes);
    visited.resize(Nodes);

    int u, v;
    while (infile >> u >> v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    infile.close();
}

void search(int start, int curr, int count) {
    visited[curr] = true;
    path.push_back(curr);

    for (int har : adj[curr]) {
        if (!visited[har]) {
            search(start, har, count + 1);
        } else if (har == start && count > 2) {
            if (count > maxCycleLength) {
                maxCycleLength = count;
                longestCycle = path;
            }
        }
    }

    visited[curr] = false;
    path.pop_back();
}

int main() {
    read("input.txt");

    for (int i = 0; i < Nodes; i++) {
        if (!adj[i].empty()) {
            fill(visited.begin(), visited.end(), false);
            path.clear();
            search(i, i, 1);
        }
    }

    if (maxCycleLength > 0) {
        std::cout << "Maximum length simple cycle: ";
        for (int node : longestCycle) {
            std::cout << node << " ";
        }
        std::cout << longestCycle[0] << std::endl;
        std::cout << "Length: " << maxCycleLength << std::endl;
    } else {
        std::cout << "No cycle found" << std::endl;
    }
}

