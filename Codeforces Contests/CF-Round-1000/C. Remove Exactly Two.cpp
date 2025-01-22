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
        int n;
        input(n);

        vector<set<int>> graph(n);
        range(i, 0, n - 1) {
            int u, v;
            input(u, v);
            graph[u - 1].insert(v - 1);
            graph[v - 1].insert(u - 1);
        }

        if (n == 2) {
            print(0);
            continue;
        }

        vector<pair<int, int>> v(n);
        range(i, 0, n) {
            v[i] = {graph[i].size(), i};
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        if (v[0].first == v[1].first) {
            if (v[0].first == v[2].first) {
                print(2 * v[0].first - 1);
            }
            else {
                print(2 * v[0].first - 1 - graph[v[0].second].count(v[1].second));
            }
            continue;
        }

        if (v[1].first != v[2].first) {
            print(v[0].first + v[1].first - 1 - graph[v[0].second].count(v[1].second));
            continue;
        }

        bool flag = false;
        range(i, 1, n) {
            if (v[i].first != v[1].first) {
                break;
            }
            if (!graph[v[0].second].count(v[i].second)) {
                flag = true;
                break;
            }
        }
        print(v[0].first + v[1].first - 2 + flag);
    }
}
