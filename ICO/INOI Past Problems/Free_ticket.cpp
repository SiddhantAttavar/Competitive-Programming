#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
    setup();

    //Input
    input(int, c);
    input(int, f);
    int cost[c][c];
    range(i, 0, c) {
        range(j, 0, c) {
            cost[i][j] = numeric_limits<int>::max();
        }
        cost[i][i] = 0;
    }
    range(i, 0, f) {
        input(int, x);
        input(int, y);
        input(int, p);
        
        cost[x - 1][y - 1] = p;
        cost[y - 1][x - 1] = p;
    }

    //Minimum cost for any two nodes
    range(k, 0, c) {
        range(i, 0, c) {
            range(j, 0, c) {
                if (cost[i][k] + cost[k][j] >= 0) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }

    //Finding Maximum route cost
    int res = 0;
    range(i, 0, c) {
        for (int j: cost[i]) {
            res = max(res, j);
        }
    }
    print(res);
}