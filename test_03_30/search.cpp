#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 定义图的结构
unordered_map<string, vector<string>> graph = {
    {"A", {"B", "C"}},
    {"B", {"D", "E"}},
    {"C", {"F"}},
    {"D", {}},
    {"E", {}},
    {"F", {}}
};

// 定义 BFS 函数
vector<string> bfs(const string& start, const string& end) {
    unordered_map<string, bool> visited;
    queue<pair<string, vector<string>>> q;
    q.push({start, {start}});

    while (!q.empty()) {
        string node = q.front().first;
        vector<string> path = q.front().second;
        q.pop();

        if (node == end) {
            return path;
        }

        visited[node] = true;

        for (const string& neighbor : graph[node]) {
            if (!visited[neighbor]) {
                vector<string> new_path = path;
                new_path.push_back(neighbor);
                q.push({neighbor, new_path});
            }
        }
    }

    return {};
}

int main() {
    string start_node = "A";
    string end_node = "F";
    vector<string> path = bfs(start_node, end_node);

    if (!path.empty()) {
        cout << "从节点 " << start_node << " 到节点 " << end_node << " 的最短路径为: ";
        for (const string& node : path) {
            cout << node << " -> ";
        }
        cout << endl;
    } else {
        cout << "从节点 " << start_node << " 到节点 " << end_node << " 没有路径存在" << endl;
    }

    return 0;
}
