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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> b(2 * n);
        arrput(b);
        sort(b.begin(), b.end());
        
        vector<int> c(b.begin(), b.begin() + n);
        vector<int> d(b.begin() + n, b.end());

        int p = accumulate(c.begin(), c.end(), 0ll);
        int q = accumulate(d.begin(), d.end(), 0ll);


        set<int> s(b.begin(), b.end());

        if (!s.count(q - p)) {
            rep(i, 0, n) {
                cout << c[i] << ' ' << d[i] << ' ';
            }
            print(q - p);
            continue;
        }

        int x = d.back();
        bool flag = false;
        rep(i, 0, n) {
            if (c[i] == q - p) {
                d.pop_back();
                d.push_back(2 * x - c[i]);
                c.push_back(x);
                flag = true;
                break;
            }
        }

        if (flag) {
            rep(i, 0, n) {
                cout << c[i] << ' ' << d[i] << ' ';
            }
            print(c.back());
            continue;
        }

        set<int> t(d.begin(), d.end());
        t.erase(q - p);
        rep(i, 0, n) {
            int k = q - p + 2 * c[i];
            if (!t.count(k) and k > 0) {
                flag = true;
                d.push_back(c[i]);
                c.erase(c.begin() + i);
                c.push_back(k);
                break;
            }
        }

        swap(c, d);
        rep(i, 0, n) {
            cout << c[i] << ' ' << d[i] << ' ';
        }
        print(c.back());
        continue;
    }
}
