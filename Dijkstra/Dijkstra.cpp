#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm> // For std::min_element

using namespace std;

int main() {
    vector<int> V = { 0, 1, 2, 3, 4, 5, 6 };
    vector<vector<int>> edge(7, vector<int>(7, INT_MAX));
    edge[0][1] = 4;
    edge[1][0] = 4;

    edge[0][2] = 2;
    edge[2][0] = 2;

    edge[1][4] = 1;
    edge[4][1] = 1;

    edge[2][5] = 8;
    edge[5][2] = 8;

    edge[3][4] = 3;
    edge[4][3] = 3;

    edge[0][3] = 9;
    edge[3][0] = 9;

    edge[3][5] = 6;
    edge[5][3] = 6;

    edge[3][6] = 1;
    edge[6][3] = 1;

    edge[4][6] = 8;
    edge[6][4] = 8;

    edge[5][6] = 5;
    edge[6][5] = 5;

    vector<int> X = { 0 };
    vector<int> Y = { 1, 2, 3, 4, 5, 6 };
    vector<int> D(V.size(), INT_MAX);
    D[0] = 0;

    for (int y = 1; y < V.size(); y++) {
        if (edge[0][y] != INT_MAX) {
			D[y] = edge[0][y]; // D[y]就是初始点到y点的距离
        }
    }

    for (int j = 1; j < V.size(); j++) {
        int minDist = INT_MAX;
        int y = -1;

		// Find the vertex y in Y that minimizes D[y]
		// 也就是找到Y中D[y]最小的点 y=D[y]
        for (int i = 0; i < Y.size(); i++) {
            if (D[Y[i]] < minDist) {
                minDist = D[Y[i]];
                y = Y[i];
            }
        }

        if (y == -1) break; // If no vertex is found, break out of the loop

        X.push_back(y);
		// Remove y from Y
        Y.erase(remove(Y.begin(), Y.end(), y), Y.end());

        for (int w = 0; w < V.size(); w++) {
            if (find(Y.begin(), Y.end(), w) != Y.end() && edge[y][w] != INT_MAX && D[y] + edge[y][w] < D[w]) {
                D[w] = D[y] + edge[y][w];
            }
        }
    }

    for (int i = 0; i < D.size(); i++) {
        if (D[i] == INT_MAX) {
            cout << "Distance from 0 to " << i << ": Infinity" << endl;
        }
        else {
            cout << "Distance from 0 to " << i << ": " << D[i] << endl;
        }
    }

    return 0;
}

