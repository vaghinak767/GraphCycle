// #include <iostream>
// #include <vector>
// #include <fstream>

// using namespace std;

// const int MAX_NODES = 100;
// vector<int> adj[MAX_NODES];
// bool visited[MAX_NODES];
// vector<int> path, longestCycle;
// int maxCycleLength = 0;

// void readGraph(const string& filename) {
//     ifstream infile(filename);
//     if (!infile) {
//         cerr << "Unable to open file";
//         exit(1);
//     }
//     int u, v;
//     while (infile >> u) {
//         while (infile.peek() != '\n' && infile >> v) {
//             adj[u].push_back(v);
//         }
//     }
//     infile.close();
// }

// void dfs(int start, int current, int count) {
//     visited[current] = true;
//     path.push_back(current);

//     for (int neighbor : adj[current]) {
//         if (!visited[neighbor]) {
//             dfs(start, neighbor, count + 1);
//         } else if (neighbor == start && count > 2) { // Found a cycle
//             if (count > maxCycleLength) {
//                 maxCycleLength = count;
//                 longestCycle = path;
//             }
//         }
//     }

//     visited[current] = false;
//     path.pop_back();
// }

// int main() {
//     readGraph("input.txt");

//     for (int i = 0; i < MAX_NODES; i++) {
//         if (!adj[i].empty()) {
//             dfs(i, i, 1);
//         }
//     }

//     if (maxCycleLength > 0) {
//         cout << "Maximum length simple cycle: ";
//         for (int node : longestCycle) {
//             cout << node << " ";
//         }
//         cout << longestCycle[0] << endl; // To show it as a cycle
//         cout << "Length: " << maxCycleLength << endl;
//     } else {
//         cout << "No cycle found" << endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <fstream>


// const int MAX_NODES = 100;
// std::vector<int> adj[MAX_NODES];
// bool visited[MAX_NODES];
// std::vector<int> path, longestCycle;
// int maxCycleLength = 0;
// int numNodes, numEdges;

// void readGraph(const std::string& filename) {
//     std::ifstream infile(filename);
//     if (!infile) {
//         std::cerr << "Unable to open file";
//         exit(1);
//     }

//     infile >> numNodes >> numEdges;
//     int u, v;
//     while (infile >> u >> v) {
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     infile.close();
// }

// void dfs(int start, int cur, int count) {
//     visited[cur] = true;
//     path.push_back(cur);

//     for (int har : adj[cur]) {
//         if (!visited[har]) {
//             dfs(start, har, count + 1);
//         } else if (har == start && count > 2) {
//             if (count > maxCycleLength) {
//                 maxCycleLength = count;
//                 longestCycle = path;
//             }
//         }
//     }

//     visited[cur] = false;
//     path.pop_back();
// }

// int main() {
//     readGraph("input.txt");

//     for (int i = 0; i < numNodes; i++) {
//         if (!adj[i].empty()) {
//             std::fill(visited, visited + numNodes, false);
//             path.clear();
//             dfs(i, i, 1);
//         }
//     }

//     if (maxCycleLength > 0) {
//         std::cout << "Maximum length simple cycle: ";
//         for (int node : longestCycle) {
//             std::cout << node << " ";
//         }
//         std::cout << longestCycle[0] << std::endl;
//         std::cout << "Length: " << maxCycleLength << std::endl;
//     } else {
//         std::cout << "No cycle found" << std::endl;
//     }
// }


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

