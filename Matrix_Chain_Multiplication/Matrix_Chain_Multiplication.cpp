#include <iostream>
#include <vector>
#include <climits> // 用于 INT_MAX

using namespace std;

// 函数声明
void MatrixChainOrder(const vector<int>& p, vector<vector<int>>& m, vector<vector<int>>& s);

int main() {
    // 示例输入：矩阵的维度数组
    vector<int> d = { 5, 4, 6, 2, 7 };

    // 矩阵数量
    int n = d.size() - 1;

    // 初始化 m 和 s 矩阵为 5x5 大小，第一排和第一列都初始化为 0
    vector<vector<int>> m(5, vector<int>(5, 0));
    vector<vector<int>> s(5, vector<int>(5, 0));

    // 计算最小乘法次数和分割点
    MatrixChainOrder(d, m, s);

    // 输出 m 矩阵
    cout << "m 矩阵:" << endl;
    for (const auto& row : m) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // 输出 s 矩阵
    cout << "s 矩阵:" << endl;
    for (const auto& row : s) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

void MatrixChainOrder(const vector<int>& d, vector<vector<int>>& m, vector<vector<int>>& s) {
    int n = d.size() - 1;

    // l 是链的长度
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX; // 初始化为无穷大
            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; // 记录分割点
                }
            }
        }
    }
}





//#include <iostream>
//#include <vector>
//#include <climits> // 用于 INT_MAX
//
//using namespace std;
//
//// 函数声明
//void MatrixChainOrder(const vector<int>& p, vector<vector<int>>& m, vector<vector<int>>& s);
//
//int main() {
//    // 示例输入：矩阵的维度数组
//    vector<int> d = { 5, 4, 6, 2, 7 };
//
//    // 矩阵数量
//    int n = d.size() - 1;
//
//    // 初始化 m 和 s 矩阵
//    vector<vector<int>> m(n, vector<int>(n, 0));
//    vector<vector<int>> s(n, vector<int>(n, 0));
//
//    // 计算最小乘法次数和分割点
//    MatrixChainOrder(d, m, s);
//
//    // 输出 m 矩阵
//    cout << "m 矩阵:" << endl;
//    for (const auto& row : m) {
//        for (int val : row) {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
//
//    // 输出 s 矩阵
//    cout << "s 矩阵:" << endl;
//    for (const auto& row : s) {
//        for (int val : row) {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
//
//void MatrixChainOrder(const vector<int>& d, vector<vector<int>>& m, vector<vector<int>>& s) {
//    int n = d.size() - 1; // 矩阵数量
//
//    // 初始化 m[i][i] 为 0
//    for (int i = 0; i < n; ++i) {
//        m[i][i] = 0;
//    }
//
//    // l 是链的长度
//    for (int l = 2; l <= n; ++l) {
//        // i是矩阵链开始的位置
//        for (int i = 0; i <= n - l; ++i) {
//            int j = i + l - 1; // j是矩阵链结束的位置
//            m[i][j] = INT_MAX; // 初始化为无穷大
//
//            // 选择最佳分割点k
//            for (int k = i; k < j; ++k) {
//                // 计算在位置k分割时的乘法次数
//                int q = m[i][k] + m[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
//                 // 如果当前的乘法次数更小，则更新数据                
//                 if (q < m[i][j]) {
//                    m[i][j] = q;
//                    s[i][j] = k+1; // 记录分割点
//                }
//            }
//        }
//    }
//}

