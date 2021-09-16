#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MOD = 1e9 + 7;

int modPow(ll a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

vector<bool> visited;
vector<vi> graph;

int dfs(int u) {
    visited[u] = true;
    int res = 1;
    for (int v : graph[u]) {
        if (!visited[v]) {
            res += dfs(v);
        }
    }
    return res;
}

int main() {
    ll fact[10000] = {1};
    range(i, 1, 10000) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    setup(); int tc; input(tc); while (tc--) {
        int n, m;
        input(n, m);

        graph = vector<vi>(n);
        visited = vector<bool>(n, false);
        range(i, 0, m) {
            int u, v; input(u, v);
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }

        int curr = 0;
        int curr2 = 0;
        range(i, 0, n) {
            if (!visited[i]) {
                curr2 += dfs(i) > 1;
                curr++;
            }
        }

        int res = fact[curr];

        //res = (res * modPow(fact[n], 2 * n)) % MOD;
        print(res);
    }
}