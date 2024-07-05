#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

// 深度优先搜索（DFS）函数
void DFS(unordered_map<string, unordered_set<string>>& graph, string node, unordered_set<string>& visited)
{
    // 如果当前节点已经访问过，则返回
    if (visited.find(node) != visited.end())
    {
        return;
    }

    // 输出当前访问的节点
    cout << node << endl;

    // 将当前节点标记为已访问
    visited.insert(node);

    // 递归访问所有相邻的未访问节点
    for (auto neighbor : graph[node])
    {
        DFS(graph, neighbor, visited);
    }
}

int main()
{
    // 定义图的邻接表表示
    unordered_map<string, unordered_set<string>> graph = {
        {"0", {"1", "2"}},
        {"1", {"0", "3", "4"}},
        {"2", {"0"}},
        {"3", {"1"}},
        {"4", {"1", "2", "3"}},
    };

    // 初始化已访问节点集合
    unordered_set<string> visited;

    // 从节点 "0" 开始进行DFS
    DFS(graph, "0", visited);

    return 0;
}


