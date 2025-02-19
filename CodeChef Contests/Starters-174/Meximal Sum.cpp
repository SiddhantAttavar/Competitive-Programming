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

        vector<int> a(n);
        arrput(a);

        set<int> s(a.begin(), a.end());
        int x = 0;
        while (s.count(x)) {
            x++;
        }

        int l = 0, y = a[0] == 0;
        s.clear();
        s.insert(a[0]);
        while (y < x) {
            l++;
            s.insert(a[l]);
            while (s.count(y)) {
                y++;
            }
        }

        int r = n - 1, z = a[n - 1] == 0;
        s.clear();
        s.insert(a[n - 1]);
        while (z < x) {
            r--;
            s.insert(a[r]);
            while (s.count(z)) {
                z++;
            }
        }

        if (l >= r) {
            print(-1, -1);
            continue;
        }

        s = set<int>(a.begin() + l + 1, a.begin() + r);
        int w = 0;
        while (s.count(w)) {
            w++;
        }

        if (w != x) {
            print(-1, -1);
            continue;
        }

        vector<int> p(n + 1, 0);
        range(i, 0, n) {
            p[i + 1] = p[i] + a[i];
        }

        int res = p[r] - p[l + 1];
        int j = l + 1;
        map<int, int> m;
        range(i, l + 1, r) {
            if (a[i] < x) {
                m[a[i]]++;
            }
            while (j <= i and (a[j] > x or m[a[j]] > 1)) {
                if (a[j] < x) {
                    m[a[j]]--;
                }
                j++;
            }
            // print(i, j, m.size(), x, m.begin()->first, m.begin()->second);
            if (m.size() == x) {
                res = min(res, max(a[i], p[i + 1] - p[j]));
            }
        }

        // arrprint(p);
        // print(l, r, p[n], p[r], p[l + 1], res);
        print(p[n] - 2 * (p[r] - p[l + 1]), p[n] - 2 * res);
    }
}
