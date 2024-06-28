#include <iostream>
#include <vector>

using namespace std;

void assemblyLineScheduling(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x, int n) {
	vector<int> f1(n), f2(n), l1(n), l2(n);
	f1[0] = e[0] + a[0][0];
	f2[0] = e[1] + a[1][0];
	l1[0] = 1;
	l2[0] = 2;

	for (int j = 1; j < n; j++) {
		if (f1[j - 1] + a[0][j] <= f2[j - 1] + t[1][j - 1] + a[0][j]) {
			f1[j] = f1[j - 1] + a[0][j];
			l1[j] = 1;
		}
		else {
			f1[j] = f2[j - 1] + t[1][j - 1] + a[0][j];
			l1[j] = 2;
		}

		if (f2[j - 1] + a[1][j] <= f1[j - 1] + t[0][j - 1] + a[1][j]) {
			f2[j] = f2[j - 1] + a[1][j];
			l2[j] = 2;
		}
		else {
			f2[j] = f1[j - 1] + t[0][j - 1] + a[1][j];
			l2[j] = 1;
		}
	}

	cout << "×î¶ÌÊ±¼ä£º";
	if (f1[n - 1] + x[0] <= f2[n - 1] + x[1]) {
		cout << f1[n - 1] + x[0];
		cout << "\nLine: " << l1[n-1];
	}
	else {
		cout <<  f2[n - 1] + x[1];
		cout << "\nLine: " << l2[n-1];
	}
}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//// Function to find the minimum time to complete the job on assembly line
//int assemblyLineScheduling(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x, int n) {
//    // Time taken to leave station j on both lines
//    vector<int> T1(n), T2(n);
//
//    // Initializing the time taken for the first station
//    T1[0] = e[0] + a[0][0];
//    T2[0] = e[1] + a[1][0];
//
//    // Filling up the DP tables T1[] and T2[]
//    for (int j = 1; j < n; ++j) {
//        T1[j] = min(T1[j - 1] + a[0][j], T2[j - 1] + t[1][j - 1] + a[0][j]);
//        T2[j] = min(T2[j - 1] + a[1][j], T1[j - 1] + t[0][j - 1] + a[1][j]);
//    }
//
//    // Returning the minimum time required to complete the job
//    return min(T1[n - 1] + x[0], T2[n - 1] + x[1]);
//}

int main() {
    // Number of stations
    int n = 4;

    // Processing time on both lines
    vector<vector<int>> a = { {4, 5, 3, 2}, {2, 10, 1, 4} };

    // Transition time between the lines
    vector<vector<int>> t = { {0, 7, 4, 5}, {0, 9, 2, 8} };

    // Entry time for both lines
    vector<int> e = { 10, 12 };

    // Exit time for both lines
    vector<int> x = { 18, 7 };

    assemblyLineScheduling(a, t, e, x, n);

    return 0;
}

//
//
//int main(){
//	vector<vector<int>> a = { {7,9,3,4,8,4},{8,5,6,4,5,7} };
//	vector<vector<int>> t = { {0,2,3,1,3,4},{0,2,1,2,2,1} };
//	vector<int> e = { 2,4 };
//	vector<int> x = { 3,2 };
//	int n = 6;
//
//	cout << assemblyLineScheduling(a, t, e, x, n);
//
//	return 0;
//}