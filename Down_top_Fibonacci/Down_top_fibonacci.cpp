#include <iostream>
#include <vector>

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    // ����һ���������洢Fibonacci��
    std::vector<long long> table(n + 1, 0);

    // ��ʼ���������
    table[0] = 0;
    table[1] = 1;

    // �����
    for (int i = 2; i <= n; ++i) {
        table[i] = table[i - 1] + table[i - 2];
    }

    // ���ս��
    return table[n];
}

int main() {
    int n;
    std::cout << "������������Fibonacci���е�����: ";
    std::cin >> n;

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}
