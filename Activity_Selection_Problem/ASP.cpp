#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	// ���밴�ս���ʱ��ķǼ�������
	// û����Ļ��������Ȱ��ս���ʱ������Ȼ���ٰ���̰���㷨���
	vector<string> a = { "a1","a2","a3","a4","a5","a6","a7","a8","a9","a10", "a11" };
	vector<int> s = { 1,3,0,5,3,5,6,8,8,2,12 };
	vector<int> f = { 4,5,6,7,9,9,10,11,12,14,16 };

	vector<string> A;

	int n = s.size();
	A.push_back(a[0]);
	int k = 0;
	for (int m = 1; m < n; m++) {
		if (s[m] >= f[k]) { // ��һ����Ŀ�ʼʱ����ڵ���ǰһ����Ľ���ʱ��
			A.push_back(a[m]);
			k = m;
		}
	}

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}

	return 0;
}