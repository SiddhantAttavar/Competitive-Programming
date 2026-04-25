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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e6;

int32_t main() {
	setup();
	int n, r;
	input(n, r);
	int h = (int) round(ceil(sqrt(3) * (double) r));

	vector<pii> p(n);
	rep(i, 0, n) {
		input(p[i].first, p[i].second);
	}

	vector<pii> v;
	while (true) {
		int x = -(rng() % N), y = -(rng() % N);
		v.clear();

		int c = 0;
		for (auto [s, t] : p) {
			int p = 0, q = 1e9;
			pii k = {1e9, 1e9};
			while (p <= q) {
				int m = (p + q) / 2;
				int z = x + h + m * (2 * h);
				if (abs(s - z) <= r) {
					k.first = z;
					break;
				}
				else if (s < z - r) {
					q = m - 1;
				}
				else {
					p = m + 1;
				}
			}

			p = 0, q = 1e9;
			while (p <= q) {
				int m = (p + q) / 2;
				int z = y + r + m * (2 * r);
				if (abs(z - t) <= r) {
					k.second = z;
					break;
				}
				else if (t < z - r) {
					q = m - 1;
				}
				else {
					p = m + 1;
				}
			}

			if (k.first != (int) 1e9 and k.second != (int) 1e9 and (s - k.first) * (s - k.first) + (t - k.second) * (t - k.second) <= r * r) {
				c++;
				v.push_back(k);
				continue;
			}

			p = 0, q = 1e9;
			k = {1e9, 1e9};
			while (p <= q) {
				int m = (p + q) / 2;
				int z = x + m * (2 * h);
				if (abs(s - z) <= r) {
					k.first = z;
					break;
				}
				else if (s < z - r) {
					q = m - 1;
				}
				else {
					p = m + 1;
				}
			}

			p = 0, q = 1e9;
			while (p <= q) {
				int m = (p + q) / 2;
				int z = y + m * (2 * r);
				if (abs(z - t) <= r) {
					k.second = z;
					break;
				}
				else if (t < z - r) {
					q = m - 1;
				}
				else {
					p = m + 1;
				}
			}

			if (k.first != (int) 1e9 and k.second != (int) 1e9 and (s - k.first) * (s - k.first) + (t - k.second) * (t - k.second) <= r * r) {
				c++;
				v.push_back(k);
				continue;
			}
		}

		if (100 * c >= 89 * n) {
			break;
		}
	}

	sort(all(v));
	v.erase(unique(all(v)), v.end());
	print(sz(v));
	for (auto [x, y] : v) {
		print(x, y);
	}
}
