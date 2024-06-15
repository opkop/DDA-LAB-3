#include <iostream>
#include <algorithm>
using namespace std;

int a, b, u, v, n, i, j, ne = 1;
int parent[10] = {0};
int mincost = 0;
int cost[10][10];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    int step_count = 0;

    cout << endl;
    while (ne < n) {
        int min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            cout << "Step " << ++step_count << ": Edge " << ne << ": (" << a << " " << b << ") cost: " << min << endl;
            ne++;
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout << endl;
    cout << "Minimum cost = " << mincost << endl;

    return 0;
}

