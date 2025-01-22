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

        int t = m;
        if (m >= (n - m)) {
            int x = 2 * m - n;
            t = n - m + 2 * x / 3 + (x % 3 == 2);
        }

        print(t);

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int> pa(n + 1, 0), pb(m + 1, 0);
        range(i, 0, n) {
            pa[i + 1] = pa[i] + a[i];
        }
        range(i, 0, m) {
            pb[i + 1] = pb[i] + b[i];
        }

        vector<int> u(n / 2 + 1, 0), v(m / 2 + 1, 0);
        range(x, 0, n / 2 + 1) {
            u[x] = pa[n] - pa[n - x] - pa[x];
        }
        range(y, 0, m / 2 + 1) {
            v[y] = pb[m] - pb[m - y] - pb[y];
        }

        range(k, 1ll, t + 1) {
            int res = 0;
            range(x, max(0ll, 2 * k - m), min(k, n - k) + 1) {
                res = max(res, u[x] + v[k - x]);
            }
            cout << res << ' ';
        }
        cout << endl;
    }
}
