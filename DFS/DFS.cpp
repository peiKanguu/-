#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

// �������������DFS������
void DFS(unordered_map<string, unordered_set<string>>& graph, string node, unordered_set<string>& visited)
{
    // �����ǰ�ڵ��Ѿ����ʹ����򷵻�
    if (visited.find(node) != visited.end())
    {
        return;
    }

    // �����ǰ���ʵĽڵ�
    cout << node << endl;

    // ����ǰ�ڵ���Ϊ�ѷ���
    visited.insert(node);

    // �ݹ�����������ڵ�δ���ʽڵ�
    for (auto neighbor : graph[node])
    {
        DFS(graph, neighbor, visited);
    }
}

int main()
{
    // ����ͼ���ڽӱ��ʾ
    unordered_map<string, unordered_set<string>> graph = {
        {"0", {"1", "2"}},
        {"1", {"0", "3", "4"}},
        {"2", {"0"}},
        {"3", {"1"}},
        {"4", {"1", "2", "3"}},
    };

    // ��ʼ���ѷ��ʽڵ㼯��
    unordered_set<string> visited;

    // �ӽڵ� "0" ��ʼ����DFS
    DFS(graph, "0", visited);

    return 0;
}


