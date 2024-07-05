#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 广度优先搜索算法
void bfs(const unordered_map<int, vector<int>>& graph, int root) {
    // 创建一个集合，用于记录已经访问过的顶点
    unordered_set<int> visited;

    // 创建一个队列，用于按顺序存储待访问的顶点
    queue<int> q;

    // 标记起始顶点为已访问，并将其加入队列
    visited.insert(root);
    q.push(root);

    // 当队列不为空时
    while (!q.empty()) {
        // 从队列中取出一个顶点
        int vertex = q.front();
        q.pop();

        // 打印当前顶点
        cout << vertex << " ";

        // 遍历当前顶点的所有邻接顶点
        for (int neighbour : graph.at(vertex)) {
            // 如果邻接顶点未被访问过
            if (visited.find(neighbour) == visited.end()) {
                // 标记邻接顶点为已访问
                visited.insert(neighbour);
                // 将邻接顶点加入队列
                q.push(neighbour);
            }
        }
    }
}

int main() {
    // 定义图的邻接表，使用 unordered_map 表示
    unordered_map<int, vector<int>> graph = {
        {0, {1, 2}},  // 顶点0的邻接顶点是1和2
        {1, {2}},     // 顶点1的邻接顶点是2
        {2, {3}},     // 顶点2的邻接顶点是3
        {3, {1, 2}}   // 顶点3的邻接顶点是1和2
    };

    // 打印BFS遍历的开始信息
    cout << "Following is Breadth First Traversal:" << endl;

    // 调用BFS函数，从顶点0开始遍历
    bfs(graph, 0);

    return 0;
}
