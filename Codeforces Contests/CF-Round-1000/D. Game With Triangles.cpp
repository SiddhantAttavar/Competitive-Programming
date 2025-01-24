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

        vector<int> a(n), b(m);
        arrput(a);
        arrput(b);

        if (n < m) {
            swap(n, m);
            swap(a, b);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int> u(n / 2 + 1, 0), v(m / 2 + 1, 0);
        range(x, 0, n / 2) {
            u[x + 1] = u[x] + a[n - x - 1] - a[x];
        }
        range(y, 0, m / 2) {
            v[y + 1] = v[y] + b[m - y - 1] - b[y];
        }

        int k = 1;
        vector<int> res;
        while (true) {
            int c = 0;
            int l = max(0ll, 2 * k - m), r = min(k, n - k);
            if (l > r) {
                break;
            }
            while (l <= r) {
                int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
                int x = u[m1] + v[k - m1], y = u[m2] + v[k - m2];
                c = max({c, x, y});
                if (x == y) {
                    l = m1 + 1;
                    r = m2 - 1;
                }
                else if (x > y) {
                    r = m2 - 1;
                }
                else {
                    l = m1 + 1;
                }
            }
            k++;
            res.push_back(c);
        }
        print(res.size());
        arrprint(res);
    }
}
