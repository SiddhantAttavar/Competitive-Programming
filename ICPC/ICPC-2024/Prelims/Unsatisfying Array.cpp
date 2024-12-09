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
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, k;
        input(n, k);

        vector<vector<pair<int, int>>> v(n + 1);
        range(i, 0, k) {
            int l, r, m;
            input(l, r, m);

            v[m].push_back({l - 1, r - 1});
        }

        vector<int> res(n, 0);
        range(m, 1, n + 1) {
            range(i, 0, n) {
                if (res[i] == 0) {
                    res[i] = m;
                }
            }

            if (v[m].empty()) {
                continue;
            }

            sort(v[m].begin(), v[m].end());
            vector<pair<int, int>> l = {v[m][0]};
            range(i, 1, v[m].size()) {
                if (v[m][i].first <= l.back().second) {
                    l.back().second = max(l.back().second, v[m][i].second);
                }
                else {
                    l.push_back(v[m][i]);
                }
            }

            for (pair<int, int> p : l) {
                bool flag = false;
                range(i, p.first, p.second + 1) {
                    if (res[i] != m) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    continue;
                }
                range(i, p.first, p.second + 1) {
                    res[i] = 0;
                }
            }
        }

        bool flag = true;
        range(i, 0, n) {
            if (res[i] == 0) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            print(-1);
        }
        else {
            arrPrint(res);
        }
    }
}
