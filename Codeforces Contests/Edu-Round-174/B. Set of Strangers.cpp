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
        int n, m;
        input(n, m);

        vector<vector<int>> a(n, vector<int>(m));
        range(i, 0, n) {
            arrput(a[i]);
        }

        vector<vector<pair<int, int>>> v(n * m);
        range(i, 0, n) {
            range(j, 0, m) {
                v[a[i][j] - 1].push_back({i, j});
            }
        }

        vector<int> c(n * m, 0);
        range(i, 0, n * m) {
            if (v[i].empty()) {
                continue;
            }
            c[i] = 1;

            sort(v[i].begin(), v[i].end());
            range(j, 1, v[i].size()) {
                if (v[i][j - 1].first == v[i][j].first and v[i][j - 1].second == v[i][j].second - 1) {
                    c[i] = 2;
                    break;
                }
            }


            sort(v[i].begin(), v[i].end(), [](pair<int, int> a, pair<int, int> b) {
                if (a.second == b.second) {
                    return a.first < b.first;
                }
                return a.second < b.second;
            });
            range(j, 1, v[i].size()) {
                if (v[i][j - 1].second == v[i][j].second and v[i][j - 1].first == v[i][j].first - 1) {
                    c[i] = 2;
                    break;
                }
            }
        }

        print(accumulate(c.begin(), c.end(), 0) - *max_element(c.begin(), c.end()));
    }
}
