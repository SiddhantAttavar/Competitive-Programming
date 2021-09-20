#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    input(int, n);
    input(int, m);

    int distance[n][n];
    range(i, 0, n) {
        range(j, 0, n) {
            distance[i][j] = numeric_limits<int>::max();
        }
        distance[i][i] = 0;
    }

    vector<pair<int, int>> graph[n];
    range(i, 0, m) {
        input(int, u);
        input(int, v);
        input(int, w);
        distance[u - 1][v - 1] = w;
        distance[v - 1][u - 1] = w;
    }

    range(k, 0, n - 1) {
        range(i, 0, n) {
            range(j, 0, n) {
                if (distance[i][k] < numeric_limits<int>::max() && distance[k][j] < numeric_limits<int>::max()) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    range(i, 0, n) {
        range(j, 0, n) {
            printf("%d ", distance[i][j]);
        }
        println("");
    }
}