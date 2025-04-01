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

        vector<int> x(n), y(n);
        arrput(x);
        arrput(y);

        vector<pair<int, int>> v, w;
        int c = 0;
        rep(i, 0, n) {
            if (x[i] < 0 and y[i] < 0) {
                c++;
            }
            else if (x[i] < 0) {
                v.push_back({-x[i], y[i]});
            }
            else {
                w.push_back({x[i], -y[i]});
            }
        }

        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second * b.first < b.second * a.first;
        });

        sort(w.begin(), w.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second * b.first > b.second * a.first;
        });

        int res = 2 * c * (n - c);
        res += c * (c - 1);
        res += v.size() * (v.size() - 1);
        res += w.size() * (w.size() - 1);
        for (pair<int, int> p : v) {
            // print(p.first, p.second);
            pair<int, int> z = {-p.first, -p.second};
            int l = 0, r = w.size() - 1, k = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (z.second * w[m].first >= z.first * w[m].second) {
                    k = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            res += k + 1;
        }
        // print(res, 'r');

        for (pair<int, int> p : w) {
            // print(p.first, p.second);
            pair<int, int> z = {-p.first, -p.second};
            int l = 0, r = v.size() - 1, k = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                // print(z.first, z.second, v[m].first, v[m].second);
                if (z.second * v[m].first <= z.first * v[m].second) {
                    k = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            // print(k, 'k');
            res += k + 1;
        }

        print(res);
	}
}
