#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int V; // 顶点的数量
    list<int> *adj; // 邻接表

public:
    Graph(int V); // 构造函数
    void addEdge(int v, int w); // 添加边
    void BFS(int s); // BFS遍历，从顶点s开始
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // 将w加入到v的邻接表中
}

void Graph::BFS(int s) {
    // 创建一个标记数组来跟踪顶点是否已经被访问过
    vector<bool> visited(V, false);

    // 创建一个队列用于BFS
    queue<int> queue;

    // 标记起始顶点s为已访问，并将其加入队列
    visited[s] = true;
    queue.push(s);

    // 当队列非空时继续执行BFS
    while (!queue.empty()) {
        // 从队列中取出一个顶点，并输出
        s = queue.front();
        cout << s << " ";
        queue.pop();

        // 获取与当前顶点相邻的顶点
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            // 如果相邻顶点未被访问过，则将其标记为已访问并加入队列
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
}

int main() {
    // 创建一个图实例
    Graph g(4);
    // 添加边
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS遍历结果：" << endl;
    g.BFS(2); // 从顶点2开始遍历

    return 0;
}
