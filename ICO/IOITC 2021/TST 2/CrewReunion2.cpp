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

int n, m, k;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
vector<int> moves;

void dfs(int u) {
    visited[u] = true;
    for (pair<int, int> p : graph[u]) {
        if (!visited[p.first]) {
            dfs(p.first);
            moves.push_back(p.second);
        }
    }
}

int main() {
    setup(); int tc; input(tc); while (tc--) {
        input(n, m, k);

        graph.clear();
        graph.resize(n);
        range(i, 0, m) {
            int u, v, w;
            input(u, v, w);
            graph[v - 1].push_back({u - 1, w});
        }

        bool flag = false;
        range(i, 0, n) {
            visited.clear();
            visited.resize(n, false);
            moves.clear();

            dfs(i);
            bool res = true;
            for (bool b : visited) {
                res &= b;
            }
            
            if (res) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            print("NO");
            continue;
        }

        cout << "YES" << endl << moves.size() << ' ';
        arrPrint(moves);
    }
}