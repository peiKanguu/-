#include <iostream>
#include <vector>
#include <climits> // ���� INT_MAX

using namespace std;

// ��������
void MatrixChainOrder(const vector<int>& p, vector<vector<int>>& m, vector<vector<int>>& s);

int main() {
    // ʾ�����룺�����ά������
    vector<int> d = { 5, 4, 6, 2, 7 };

    // ��������
    int n = d.size() - 1;

    // ��ʼ�� m �� s ����Ϊ 5x5 ��С����һ�ź͵�һ�ж���ʼ��Ϊ 0
    vector<vector<int>> m(5, vector<int>(5, 0));
    vector<vector<int>> s(5, vector<int>(5, 0));

    // ������С�˷������ͷָ��
    MatrixChainOrder(d, m, s);

    // ��� m ����
    cout << "m ����:" << endl;
    for (const auto& row : m) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // ��� s ����
    cout << "s ����:" << endl;
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

    // l �����ĳ���
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX; // ��ʼ��Ϊ�����
            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; // ��¼�ָ��
                }
            }
        }
    }
}





//#include <iostream>
//#include <vector>
//#include <climits> // ���� INT_MAX
//
//using namespace std;
//
//// ��������
//void MatrixChainOrder(const vector<int>& p, vector<vector<int>>& m, vector<vector<int>>& s);
//
//int main() {
//    // ʾ�����룺�����ά������
//    vector<int> d = { 5, 4, 6, 2, 7 };
//
//    // ��������
//    int n = d.size() - 1;
//
//    // ��ʼ�� m �� s ����
//    vector<vector<int>> m(n, vector<int>(n, 0));
//    vector<vector<int>> s(n, vector<int>(n, 0));
//
//    // ������С�˷������ͷָ��
//    MatrixChainOrder(d, m, s);
//
//    // ��� m ����
//    cout << "m ����:" << endl;
//    for (const auto& row : m) {
//        for (int val : row) {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
//
//    // ��� s ����
//    cout << "s ����:" << endl;
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
//    int n = d.size() - 1; // ��������
//
//    // ��ʼ�� m[i][i] Ϊ 0
//    for (int i = 0; i < n; ++i) {
//        m[i][i] = 0;
//    }
//
//    // l �����ĳ���
//    for (int l = 2; l <= n; ++l) {
//        for (int i = 0; i <= n - l; ++i) {
//            int j = i + l - 1;
//            m[i][j] = INT_MAX; // ��ʼ��Ϊ�����
//            for (int k = i; k < j; ++k) {
//                int q = m[i][k] + m[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
//                if (q < m[i][j]) {
//                    m[i][j] = q;
//                    s[i][j] = k+1; // ��¼�ָ��
//                }
//            }
//        }
//    }
//}

