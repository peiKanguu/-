#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

// 比较函数，根据物品的价值-重量比进行排序
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

std::vector<double> greedyFractionalKnapsack(const std::vector<int>& weights, const std::vector<int>& values, int W) {
    int n = weights.size();
    std::vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        items[i] = { weights[i], values[i] };
    }

    // 按价值-重量比排序物品
    std::sort(items.begin(), items.end(), compare);

    std::vector<double> x(n, 0.0); // 记录每个物品放入背包的比例
    int currentWeight = 0;  // 当前背包的重量

    for (int i = 0; i < n; ++i) {
        if (currentWeight + items[i].weight <= W) {
            x[i] = 1.0;
            currentWeight += items[i].weight;
        }
        else {
            x[i] = (double)(W - currentWeight) / items[i].weight;
            currentWeight = W;
            break;
        }
    }

    return x;
}

int main() {
    int W = 50; // 背包容量
    std::vector<int> weights = { 10, 20, 30 };
    std::vector<int> values = { 60, 100, 120 };

    std::vector<double> x = greedyFractionalKnapsack(weights, values, W);

    double totalValue = 0.0;
    for (int i = 0; i < weights.size(); ++i) {
        totalValue += x[i] * values[i];
    }

    std::cout << "Maximum value in Knapsack = " << totalValue << std::endl;

    return 0;
}