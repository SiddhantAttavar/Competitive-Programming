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

vector<vector<int>> get(vector<int> &a) {
	vector<vector<int>> res(4);
	rep(i, 0, 1 << a.size()) {
		vector<int> l;
		int c = 0;
		bool flag = true;
		rep(j, 0, a.size()) {
			if (!(i >> j & 1)) {
				continue;
			}

			l.push_back(a[j]);
			if (a[j] >= 0) {
				c = 0;
			}
			else {
				c++;
			}
			if (c >= 4) {
				flag = false;
				break;
			}
		}

		if (flag) {
			res[c].push_back(accumulate(l.begin(), l.end(), 0ll));
		}
	}
	return res;
}

int comb(vector<int> &x, vector<int> &y, int s) {
	int res = 1e18, j = (int) y.size() - 1;
	for (int i : x) {
		while (j > 0 and i + y[j - 1] >= s) {
			j--;
		}
		if (i + y[j] >= s) {
			res = min(res, i + y[j]);
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, s;
		input(n, s);

		vector<int> a(n);
		arrput(a);

		vector<int> b;
		while (a.size() > b.size()) {
			b.push_back(a.back());
			a.pop_back();
		}

		vector<vector<int>> x = get(a), y = get(b);
		rep(i, 0, 4) {
			x[i].push_back(0);
			y[i].push_back(0);
			sort(x[i].begin(), x[i].end());
			sort(y[i].begin(), y[i].end());
		}

		int res = 1e18;
		rep(i, 0, 4) {
			rep(j, 0, 4 - i) {
				res = min(res, comb(x[i], y[j], s));
			}
		}

		if (res == 1e18) {
			print("Impossible");
		}
		else {
			print(res);
		}
	}
}
