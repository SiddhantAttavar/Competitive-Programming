#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int l, w, r, g, b;
		input(l, w, r, g, b);

		if (l > w) {
			swap(l, w);
		}

		if (r > g) {
			swap(r, g);
		}
		if (g > b) {
			swap(b, g);
		}
		if (r > g) {
			swap(r, g);
		}

		vector<int> a = {
			w, l, 2 * w, w + l, 2 * l,
			2 * w + l, 2 * l + w, 2 * w + 2 * l
		};

		bool flag = false;
		rep(x, 0, 9) {
			if ((x % 3) * w + (x / 3) * l != r) {
				continue;
			}
			rep(y, 0, 9) {
				if ((y % 3) * w + (y / 3) * l != g) {
					continue;
				}
				rep(z, 0, 9) {
					if ((z % 3) * w + (z / 3) * l != b) {
						continue;
					}
					vector<pii> v = {
						{x % 3, x / 3},
						{y % 3, y / 3},
						{z % 3, z / 3}
					};
					if (v[0].first + v[1].first + v[2].first != 2) {
						continue;
					}
					if (v[0].second + v[1].second + v[2].second != 2) {
						continue;
					}
					flag = true;
				}
			}
		}

		if (flag) {
			print(4);
			continue;
		}
		
		if (count(all(a), r) or count(all(a), g) or count(all(a), b)) {
			print(5);
			continue;
		}

		print(6);
	}
}
