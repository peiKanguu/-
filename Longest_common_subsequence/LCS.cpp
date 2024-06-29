#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LCS(string X, string Y, int n, int m, vector<vector<int>>& dp) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (X[i-1] == Y[j-1]) { // dp[i][j]可以直接用ij,这是因为数组增加了行列数。但是字符串不可以，因为index从0开始
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[n][m];
}

//string constructLCS(const string& X, const string& Y, const vector<vector<int>>& dp) {
//	string lcs;
//	int i = X.size();
//	int j = Y.size();
//
//	while (i > 0 && j > 0) {
//		if (X[i - 1] == Y[j - 1]) {
//			lcs.push_back(X[i - 1]);
//			--i;
//			--j;
//		}
//		else if (dp[i - 1][j] < dp[i][j - 1]) {
//			--j;
//		}
//		else {
//			--i;
//		}
//	}
//
//	reverse(lcs.begin(), lcs.end());
//
//	return lcs;
//}

// 递归构造 LCS
string constructLCS(const string& X, const string& Y, const vector<vector<int>>& dp) {
	int i = X.length();
	int j = Y.length();
	string lcs;

	while (i > 0 && j > 0) {
		if (X[i - 1] == Y[j - 1]) {
			lcs.push_back(X[i - 1]);
			--i;
			--j;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) { //要选择较大的值
			--i;
		}
		else {
			--j;
		}
	}

	reverse(lcs.begin(), lcs.end());
	return lcs;
}

int main() {
	string X = "Stone";
	string Y = "Longest";

	int n = X.size();
	int m = Y.size();

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	cout << X << endl;
	cout << Y << endl;
	cout << constructLCS(X, Y, dp) << endl;
	cout << LCS(X, Y, n, m, dp);
}