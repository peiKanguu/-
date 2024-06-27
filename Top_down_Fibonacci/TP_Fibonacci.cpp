#include <iostream>
#include <vector>

std::vector<long long> memo;

long long fibonacci(int n) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n <= 1) {
        return n;
    }
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n;
    std::cout << "������������Fibonacci���е�����: ";
    std::cin >> n;

    // ��ʼ��memo���飬��������Ԫ������Ϊ-1����ʾδ����
    memo = std::vector<long long>(n + 1, -1);

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}
