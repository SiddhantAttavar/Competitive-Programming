#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, k;

vector<unordered_set<int>> a;
vector<bool> visited;

bool isRelative(int x, int y) {
    int common = 0;
    for (int i: a[x]) {
        if (a[y].find(i) != a[y].end()) {
            common++;
        }
    }
    return common >= k;
}

int dfs(int u) {
    if (visited[u]) {
        return 0;
    }
    visited[u] = true;
    int res = 1;
    range(v, 0, n) {
        if (!visited[v] && isRelative(u, v)) {
            res += dfs(v);
        }
    }
    return res;
}

int main() {
    setup();

    //Input
    cin >> n >> k;
    a = vector<unordered_set<int>>(n);
    visited = vector<bool>(n);
    range(i, 0, n) {
        input(int, p);
        range(j, 0, p) {
            input(int, x);
            a[i].insert(x);
        }
    }
    range(i, 0, n) {
        visited[i] = false;
    }

    print(dfs(0));
}