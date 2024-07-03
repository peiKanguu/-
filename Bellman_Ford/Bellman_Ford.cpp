#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int V = 6;
    vector<vector<int>> edges(V, vector<int>(V, INT_MAX));
    edges[0][1] = 9;
    edges[0][2] = 7;
    edges[1][4] = 3;
    edges[1][5] = -1;
    edges[1][3] = 1;
    edges[2][1] = -2;
    edges[2][3] = 2;
    edges[3][5] = 1;
    edges[5][4] = 1;

    vector<int> D(V, INT_MAX);
    D[0] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (edges[u][v] != INT_MAX && D[u] != INT_MAX && D[u] + edges[u][v] < D[v]) {
                    D[v] = D[u] + edges[u][v];
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (edges[u][v] != INT_MAX && D[u] != INT_MAX && D[u] + edges[u][v] < D[v]) {
                cout << "Negative cycle detected" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (D[i] == INT_MAX) {
            cout << "INF ";
        }
        else {
            cout << D[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
