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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int get(vector<int> &x, vector<int> &p, map<int, int> &f, int k, int i, int b) {
	int r = lower_bound(x.begin(), x.end(), x[i] + k) - x.begin() - 1;
	int l = upper_bound(x.begin(), x.end(), x[i] - k) - x.begin();
	int s = x[i] * (i - l) - (p[i] - p[l]) + (p[r + 1] - p[i]) - x[i] * (r + 1 - i);
	if (s > b) {
		return -1;
	}
	int u = upper_bound(x.begin(), x.end(), x[i] + k) - x.begin() - 1;
	int v = lower_bound(x.begin(), x.end(), x[i] - k) - x.begin();
	return r - l + min(u - r + l - v, (b - s) / k);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> x(n), b(n);
		arrput(x);
		arrput(b);

		map<int, int> f;
		for (int i : x) {
			f[i]++;
		}

		vector<int> p(n + 1, 0);
		rep(i, 0, n) {
			p[i + 1] = p[i] + x[i];
		}

		rep(i, 0, n) {
			int l = 1, r = 1e9, res = 0;
			while (l <= r) {
				int m = (l + r) / 2;
				int z = get(x, p, f, m, i, b[i]);
				if (z != -1) {
					res = max(res, z);
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			cout << res << ' ';
		}
		cout << endl;
	}
}
