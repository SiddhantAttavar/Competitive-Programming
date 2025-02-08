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
        int n, k;
        input(n, k);

        vector<int> a(n);
        arrput(a);

        vector<vector<int>> v;
        range(i, 0, n) {
            int l = 0, r = v.size() - 1, x = v.size();
            while (l <= r) {
                int m = (l + r) / 2;
                if (a[i] < a[v[m].back()]) {
                    x = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }

            if (x == v.size()) {
                v.push_back({});
            }
            v[x].push_back(i);
        }

        sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b) {
            return a.size() > b.size();
        });

        vector<int> l;
        range(i, 0, min((k + 1) / 2, (int) v.size())) {
            l.insert(l.end(), v[i].begin(), v[i].end());
        }

        if (l.size() < k) {
            print("NO");
            continue;
        }

        print("YES");
        vector<int> res(k);
        range(i, 0, k) {
            res[i] = l[i] + 1;
        }
        sort(res.begin(), res.end());
        arrprint(res);
    }
}
