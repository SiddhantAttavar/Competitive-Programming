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

vector<int> fact(int x, vector<int> &spf) {
	set<int> res;
	while (x > 1) {
		res.insert(spf[x]);
		x /= spf[x];
	}
	return vector<int>(res.begin(), res.end());
}

int32_t main() {
	const int N = 2e5;
	vector<int> spf(N + 1);
	rep(i, 0, N + 1) {
		spf[i] = i;
	}
	rep(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}

		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		int x = 0, res = 0;
		map<int, int> m;
		rep(i, 0, n) {
			int y = gcd(a[i], x);
			if (x != y) {
				res = 0;
				m.clear();
				x = y;
				rep(j, 0, i) {
					for (int k : fact(a[j] / x, spf)) {
						m[k]++;
						res = max(res, m[k]);
					}
				}
			}

			for (int k : fact(a[i] / x, spf)) {
				m[k]++;
				res = max(res, m[k]);
			}
			cout << res << ' ';
		}
		cout << endl;
	}
}
