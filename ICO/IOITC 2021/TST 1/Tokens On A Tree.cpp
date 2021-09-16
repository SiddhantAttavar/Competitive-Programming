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

int n, res;
vector<vector<int>> graph;
vector<bool> hasToken;
vector<int> parent;
vector<int> nextLast;
vector<int> level;
vector<pair<int, int>> last;
vector<int> num;

pair<int, int> dfs(int u) {
    if (!hasToken[u]) {
        last[u] = {-1, 0};
    }
    else {
        last[u] = {level[u], 1};
        num[level[u]]++;
    }

    for (int v : graph[u]) {
        level[v] = level[u] + 1;
        pair<int, int> p = dfs(v);
        if (p.first > last[u].first) {
            last[u] = p;
        }
        else if (p.first == last[u].first) {
            last[u].second += p.second;
        }
        dfs(v);
    }

    if (!hasToken[u] && last[u].first != -1) {
        res += level[u] - last[u].first;
        last[u].second--;
        num[last[u].first]--;
        if (last[u].second == 0) {
            last[u].first--;
            last[u].second = num[u];
        }
    }

    return last[u];
}

int main() {
    setup(); int tc; input(tc); while (tc--) {
        input(n);
        string s; input(s);

        hasToken.resize(n);
        range(i, 0, n) {
            hasToken[i] = s[i] == '1';
        }

        graph.clear();
        graph.resize(n);
        parent.resize(n);
        parent[0] = -1;
        range(i, 1, n) {
            int p; input(p);
            parent[i - 1] = p - 1;
            graph[p - 1].push_back(i);
        }

        num.clear();
        num.resize(n, 0);
        nextLast.resize(n);
        level.resize(n);
        level[0] = 0;
        last.resize(n);

        res = 0;
        dfs(0);
        print(res);
    }
}