#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// 定义一个表示无穷大的常量
const int INF = numeric_limits<int>::max();

int main()
{
    // 初始化带权有向图的距离矩阵
    vector<vector<int>> A = {
        {0, 5, -3, INF},   // 从节点 0 到其他节点的初始距离
        {9, 0, INF, 3},    // 从节点 1 到其他节点的初始距离
        {4, 5, 0, INF},    // 从节点 2 到其他节点的初始距离
        {INF, INF, 1, 0}   // 从节点 3 到其他节点的初始距离
    };

    // 获取图中节点的数量
    int n = A.size();

    // 弗洛伊德-沃肖尔算法的三重循环
    // 外层循环 k 表示中间节点
    for (int k = 0; k < n; k++) {
        // 中层循环 i 表示起点
        for (int i = 0; i < n; i++) {
            // 内层循环 j 表示终点
            for (int j = 0; j < n; j++) {
                // 检查是否存在通过中间节点 k 的路径
                // 防止溢出：仅在 A[i][k] 和 A[k][j] 都不是无穷大时更新距离
                if (A[i][k] < INF && A[k][j] < INF) {
                    // 更新 A[i][j] 为经过 k 的更短路径
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
    }

    // 输出所有节点对之间的最短路径
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 如果 A[i][j] 仍然是无穷大，说明 i 和 j 之间没有路径
            if (A[i][j] == INF) {
                cout << "INF ";
            }
            else {
                // 否则输出最短路径长度
                cout << A[i][j] << " ";
            }
        }
        cout << endl; // 换行，输出下一行结果
    }

    return 0;
}
