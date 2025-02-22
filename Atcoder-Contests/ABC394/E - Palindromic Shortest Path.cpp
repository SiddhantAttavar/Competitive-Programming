#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
    setup();

    int n;
    input(n);

    vector<string> c(n);
    arrput(c);

    vector<vector<int>> graph(n * n);
    range(i, 0, n) {
        range(j, 0, n) {
            range(p, 0, n) {
                range(q, 0, n) {
                    if (c[i][p] == c[q][j] and c[i][p] != '-') {
                        graph[p * n + q].push_back(i * n + j);
                    }
                }
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> res(n * n, 1e9);
    range(i, 0, n) {
        range(j, 0, n) {
            if (i == j) {
                pq.push({0, i * n + j});
                res[i * n + j] = 0;
            }
            else if (c[i][j] != '-') {
                pq.push({1, i * n + j});
                res[i * n + j] = 1;
            }
        }
    }

    while (!pq.empty()) {
        int x, u;
        tie(x, u) = pq.top();
        pq.pop();

        if (x != res[u]) {
            continue;
        }

        for (int v : graph[u]) {
            if (x + 2 < res[v]) {
                res[v] = x + 2;
                pq.push({res[v], v});
            }
        }
    }

    range(i, 0, n) {
        range(j, 0, n) {
            cout << (res[i * n + j] == 1e9 ? -1 : res[i * n + j]) << ' ';
        }
        cout << endl;
    }
}
