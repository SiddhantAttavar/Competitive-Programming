#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

vector<vector<int>> tree;
vector<int> a;
int maxDiff = numeric_limits<int>::min();

int dfs(int u) {
    int res = a[u];
    for (int v: tree[u]) {
        res = min(res, dfs(v));
    }
    maxDiff = max(maxDiff, a[u] - res);
    return res;
}

int main() {
    setup();

    //Input
    input(int, n);
    a = vector<int>(n);
    range(i, 0, n) {
        cin >> a[i];
    }
    tree = vector<vector<int>>(n);
    int root = 0;
    range(i, 0, n) {
        input(int, p);
        if (p == -1) {
            root = i;
        }
        else {
            tree[p - 1].push_back(i);
        }
    }

    dfs(root);
    print(maxDiff);
}