#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// ����һ����ʾ�����ĳ���
const int INF = numeric_limits<int>::max();

int main()
{
    // ��ʼ����Ȩ����ͼ�ľ������
    vector<vector<int>> A = {
        {0, 5, -3, INF},   // �ӽڵ� 0 �������ڵ�ĳ�ʼ����
        {9, 0, INF, 3},    // �ӽڵ� 1 �������ڵ�ĳ�ʼ����
        {4, 5, 0, INF},    // �ӽڵ� 2 �������ڵ�ĳ�ʼ����
        {INF, INF, 1, 0}   // �ӽڵ� 3 �������ڵ�ĳ�ʼ����
    };

    // ��ȡͼ�нڵ������
    int n = A.size();

    // ��������-��Ф���㷨������ѭ��
    // ���ѭ�� k ��ʾ�м�ڵ�
    for (int k = 0; k < n; k++) {
        // �в�ѭ�� i ��ʾ���
        for (int i = 0; i < n; i++) {
            // �ڲ�ѭ�� j ��ʾ�յ�
            for (int j = 0; j < n; j++) {
                // ����Ƿ����ͨ���м�ڵ� k ��·��
                // ��ֹ��������� A[i][k] �� A[k][j] �����������ʱ���¾���
                if (A[i][k] < INF && A[k][j] < INF) {
                    // ���� A[i][j] Ϊ���� k �ĸ���·��
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
    }

    // ������нڵ��֮������·��
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // ��� A[i][j] ��Ȼ�������˵�� i �� j ֮��û��·��
            if (A[i][j] == INF) {
                cout << "INF ";
            }
            else {
                // ����������·������
                cout << A[i][j] << " ";
            }
        }
        cout << endl; // ���У������һ�н��
    }

    return 0;
}
