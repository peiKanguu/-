#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// ������������㷨
void bfs(const unordered_map<int, vector<int>>& graph, int root) {
    // ����һ�����ϣ����ڼ�¼�Ѿ����ʹ��Ķ���
    unordered_set<int> visited;

    // ����һ�����У����ڰ�˳��洢�����ʵĶ���
    queue<int> q;

    // �����ʼ����Ϊ�ѷ��ʣ�������������
    visited.insert(root);
    q.push(root);

    // �����в�Ϊ��ʱ
    while (!q.empty()) {
        // �Ӷ�����ȡ��һ������
        int vertex = q.front();
        q.pop();

        // ��ӡ��ǰ����
        cout << vertex << " ";

        // ������ǰ����������ڽӶ���
        for (int neighbour : graph.at(vertex)) {
            // ����ڽӶ���δ�����ʹ�
            if (visited.find(neighbour) == visited.end()) {
                // ����ڽӶ���Ϊ�ѷ���
                visited.insert(neighbour);
                // ���ڽӶ���������
                q.push(neighbour);
            }
        }
    }
}

int main() {
    // ����ͼ���ڽӱ�ʹ�� unordered_map ��ʾ
    unordered_map<int, vector<int>> graph = {
        {0, {1, 2}},  // ����0���ڽӶ�����1��2
        {1, {2}},     // ����1���ڽӶ�����2
        {2, {3}},     // ����2���ڽӶ�����3
        {3, {1, 2}}   // ����3���ڽӶ�����1��2
    };

    // ��ӡBFS�����Ŀ�ʼ��Ϣ
    cout << "Following is Breadth First Traversal:" << endl;

    // ����BFS�������Ӷ���0��ʼ����
    bfs(graph, 0);

    return 0;
}
