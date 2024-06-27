#include <iostream>
#include <vector>

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    // 创建一个数组来存储Fibonacci数
    std::vector<long long> table(n + 1, 0);

    // 初始化基本情况
    table[0] = 0;
    table[1] = 1;

    // 填充表格
    for (int i = 2; i <= n; ++i) {
        table[i] = table[i - 1] + table[i - 2];
    }

    // 最终结果
    return table[n];
}

int main() {
    int n;
    std::cout << "输入你想计算的Fibonacci数列的项数: ";
    std::cin >> n;

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}
