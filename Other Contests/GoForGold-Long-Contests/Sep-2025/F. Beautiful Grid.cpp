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

bool check(vector<int> &l, vector<pair<int, int>> &a, int t, int m) {
	int n = l.size();
	vector<int> b(n);
	for (auto [x, i] : a) {
		b[i] = x;
	}
	int x = 0, y = 0;
	rep(i, 0, n) {
		if (l[i] == 1) {
			x += b[i];
		}
		else {
			y += m - b[i];
		}
	}
	return x <= t and y <= t;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<pair<int, int>> x(n);
		int m = 0, z = 0;
		rep(i, 0, n) {
			int y;
			input(x[i].first, y);
			m = x[i].first + y;
			z += x[i].first;
			x[i].second = i;
		}
		sort(x.begin(), x.end());

		int t = (n + 1) * m / 4;
		int k = -1, c = 0;
		rep(i, 0, n) {
			c += x[i].first;
			if (c <= t and c + (n - i - 1) * m - z <= t) {
				k = i + 1;
				break;
			}
		}

		vector<int> res(n, 2);
		rep(i, 0, k) {
			res[x[i].second] = 1;
		}
		arrprint(res);
		// assert(check(res, x, t, m));
	}
}
