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
	vector<int> s = { 2, 3, 4, 5 }; // ���һ�� 0 ��Ϊռλ������������
    vector<int> v = { 1, 2, 5, 6 }; // ���һ�� 0 ��Ϊռλ������������
    int C = 8;

    cout << "Maximum value in Knapsack = " << Knapsack(s, v, C) << endl;

	return 0;
}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// ��������
//int knapsack(const std::vector<int>& values, const std::vector<int>& weights, int W);
//
//int main() {
//    // ��Ʒ�ļ�ֵ
//    std::vector<int> values = { 60, 100, 120 };
//    // ��Ʒ������
//    std::vector<int> weights = { 10, 20, 30 };
//    // �������������
//    int W = 50;
//
//    // ���㱳����װ�µ�����ֵ
//    int max_value = knapsack(values, weights, W);
//
//    // ������
//    std::cout << "����ֵ: " << max_value << std::endl;
//
//    return 0;
//}
//
//// knapsack����ʵ��
//int knapsack(const std::vector<int>& values, const std::vector<int>& weights, int W) {
//    // ��Ʒ������
//    int n = values.size();
//
//    // ������ά����dp��dp[i][j]��ʾǰi����Ʒ������Ϊj�ı����е�����ֵ
//    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));
//
//    // ���dp����
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= W; ++j) {
//            // ����i����Ʒ������С�ڵ��ڱ�������
//            if (weights[i - 1] <= j) { // ����index�Ǵ�0��ʼ��
//                // �����ǰ��Ʒ���Է��뱳�������Ƿ���򲻷��������ֵ
//                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
//            }
//            else {
//                // ��ǰ��Ʒ���ܷ��뱳��������ֵ���ڲ����뵱ǰ��Ʒ�����
//                dp[i][j] = dp[i - 1][j];
//            }
//        }
//    }
//
//    // ���ر���������ֵ
//    return dp[n][W];
//}