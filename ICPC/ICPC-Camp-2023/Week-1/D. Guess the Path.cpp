#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

vector<pair<int, int>> query(vector<int> v, int m, int n) {
	int y = 0;
	string s;
	v.pop_back();
	for (int i : v) {
		while (y < i) {
			s += 'D';
			y++;
		}
		s += 'R';
	}
	while (y < n - 1) {
		s += 'D';
		y++;
	}
	print('?', s);
	cout.flush();

	vector<pair<int, int>> res(m, {n, -1});
	int t;
	input(t);
	while (t--) {
		int r, c;
		input(r, c);
		res[c - 1].second = max(res[c - 1].second, r - 1);
		res[c - 1].first = min(res[c - 1].first, r - 1);
	}
	return res;
}

// string t;
// vector<pair<int, int>> query(vector<int> v, int m, int n) {
// 	if (t.empty()) {
// 		input(t);
// 	}
//
// 	vector<vector<bool>> w(n, vector<bool>(m, false));
// 	int x = 0, y = 0;
// 	w[0][0] = true;
// 	for (char c : t) {
// 		if (c == 'D') {
// 			x++;
// 		}
// 		else {
// 			y++;
// 		}
// 		w[x][y] = true;
// 	}
//
// 	x = 0;
// 	vector<pair<int, int>> res(m, {n, -1});
// 	rep(y, 0, m) {
// 		if (w[x][y]) {
// 			res[y] = {x, x};
// 		}
// 		while (x < v[y]) {
// 			x++;
// 			if (w[x][y]) {
// 				res[y].second = x;
// 			}
// 		}
// 	}
// 	return res;
// }

int32_t main() {
	int m, n;
	input(n, m);

	if (n == 2 and m == 1) {
		print("! D");
		cout.flush();
		return 0;
	}

	vector<int> l(m, 0), r(m, n - 1), res(m, -1);
	l[m - 1] = n - 1;
	res[m - 1] = n - 1;
	rep(i, 0, 10) {
		vector<int> v(m);
		rep(j, 0, m) {
			if (l[j] <= r[j]) {
				v[j] = (l[j] + r[j]) / 2;
			}
			else {
				v[j] = res[j];
			}
		}
		vector<pair<int, int>> w = query(v, m, n);
		rep(j, 0, m) {
			res[j] = max(res[j], w[j].second);
			if (w[j].second != -1) {
				l[j] = w[j].second + 1;
				if (w[j].second < v[j]) {
					r[j] = v[j] - 1;
				}
				if (j > 0) {
					r[j - 1] = min(r[j - 1], w[j].first);
				}
			}
		}
		rep(j, 1, m) {
			l[j] = max(l[j], l[j - 1]);
			res[j] = max(res[j], res[j - 1]);
		}
		for (int j = m - 2; j >= 0; j--) {
			r[j] = min(r[j], r[j + 1]);
		}
	}

	int y = 0;
	string s;
	res.pop_back();
	for (int i : res) {
		while (y < i) {
			s += 'D';
			y++;
		}
		s += 'R';
	}
	while (y < n - 1) {
		s += 'D';
		y++;
	}
	print('!', s);
	cout.flush();
}
