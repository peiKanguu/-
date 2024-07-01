#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Knapsack(vector<int>& w, vector<int>& v, int C) {
    vector<vector<int>> dp(v.size() + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= v.size(); i++) {
        for (int j = 1; j <= C; j++) {
            if (w[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i-1]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[v.size()][C];
}

int main() {
	vector<int> s = { 2, 3, 4, 5 }; // 添加一个 0 作为占位符，方便索引
    vector<int> v = { 1, 2, 5, 6 }; // 添加一个 0 作为占位符，方便索引
    int C = 8;

    cout << "Maximum value in Knapsack = " << Knapsack(s, v, C) << endl;

	return 0;
}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// 函数声明
//int knapsack(const std::vector<int>& values, const std::vector<int>& weights, int W);
//
//int main() {
//    // 物品的价值
//    std::vector<int> values = { 60, 100, 120 };
//    // 物品的重量
//    std::vector<int> weights = { 10, 20, 30 };
//    // 背包的最大容量
//    int W = 50;
//
//    // 计算背包能装下的最大价值
//    int max_value = knapsack(values, weights, W);
//
//    // 输出结果
//    std::cout << "最大价值: " << max_value << std::endl;
//
//    return 0;
//}
//
//// knapsack函数实现
//int knapsack(const std::vector<int>& values, const std::vector<int>& weights, int W) {
//    // 物品的数量
//    int n = values.size();
//
//    // 创建二维数组dp，dp[i][j]表示前i个物品在容量为j的背包中的最大价值
//    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));
//
//    // 填充dp数组
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= W; ++j) {
//            // 若第i个物品的重量小于等于背包重量
//            if (weights[i - 1] <= j) { // 重量index是从0开始的
//                // 如果当前物品可以放入背包，则考虑放入或不放入的最大价值
//                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
//            }
//            else {
//                // 当前物品不能放入背包，最大价值等于不放入当前物品的情况
//                dp[i][j] = dp[i - 1][j];
//            }
//        }
//    }
//
//    // 返回背包的最大价值
//    return dp[n][W];
//}