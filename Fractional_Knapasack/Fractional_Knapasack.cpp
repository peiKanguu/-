#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

// �ȽϺ�����������Ʒ�ļ�ֵ-�����Ƚ�������
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

    // ����ֵ-������������Ʒ
    std::sort(items.begin(), items.end(), compare);

    std::vector<double> x(n, 0.0); // ��¼ÿ����Ʒ���뱳���ı���
    int currentWeight = 0;  // ��ǰ����������

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
    int W = 50; // ��������
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