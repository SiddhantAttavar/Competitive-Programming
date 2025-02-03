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
    setup(); int tc; input(tc); while (tc--) {
        int n, s1, s2;
        input(n, s1, s2);

        s1--;
        s2--;

        int m1;
        input(m1);
        vector<vector<int>> g1(n);
        range(i, 0, m1) {
            int u, v;
            input(u, v);

            g1[u - 1].push_back(v - 1);
            g1[v - 1].push_back(u - 1);
        }

        int m2;
        input(m2);
        vector<vector<int>> g2(n);
        range(i, 0, m2) {
            int u, v;
            input(u, v);

            g2[u - 1].push_back(v - 1);
            g2[v - 1].push_back(u - 1);
        }

        set<int> b;
        range(u, 0, n) {
            set<int> s(g1[u].begin(), g1[u].end());
            for (int v : g2[u]) {
                if (s.count(v)) {
                    b.insert(u);
                    break;
                }
            }
        }

        if (b.empty()) {
            print(-1);
            continue;
        }

        int res = -1;
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> d(n, vector<int>(n, 1e18));
        pq.push({0, {s1, s2}});
        d[s1][s2] = 0;
        while (!pq.empty()) {
            int x = pq.top().first;
            int u1, u2;
            tie(u1, u2) = pq.top().second;
            pq.pop();

            if (u1 == u2 and b.count(u1)) {
                res = -x;
                break;
            }

            if (d[u1][u2] != -x) {
                continue;
            }

            for (int v1 : g1[u1]) {
                for (int v2 : g2[u2]) {
                    if (d[v1][v2] > -x + abs(v1 - v2)) {
                        d[v1][v2] = -x + abs(v1 - v2);
                        pq.push({-d[v1][v2], {v1, v2}});
                    }
                }
            }
        }
        print(res);
    }
}
