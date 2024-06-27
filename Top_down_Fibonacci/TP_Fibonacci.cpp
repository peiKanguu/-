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
    std::cout << "输入你想计算的Fibonacci数列的项数: ";
    std::cin >> n;

    // 初始化memo数组，并将所有元素设置为-1，表示未计算
    memo = std::vector<long long>(n + 1, -1);

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}
