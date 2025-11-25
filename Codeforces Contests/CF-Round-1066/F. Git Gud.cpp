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

bool check(vector<pair<int, int>> &res) {
	int k = 1e6, n = 25e4;
	vector<int> v(n + 1, 1);
	v[0] = 0;
	int x = 0;
	int c = n;
	for (auto [y, l] : res) {
		k -= l;
		if (y > x) {
			k -= 1000;
		}
		if (y + l <= n) {
			v[y + l] += v[y];
		}
		v[y] = 0;
		x = y;
	}
	return k >= 0 and !accumulate(v.begin(), v.end(), 0ll);
}

vector<pair<int, int>> get(int n, int k) {
	vector<vector<int>> v(k);
	rep(i, 1, n + 1) {
		v[i % k].push_back(i);
	}

	vector<pair<int, int>> res;
	rep(i, 1, k) {
		for (int j = (int) v[i].size() - 1; j >= 0; j--) {
			res.push_back({v[i][j], 1});
		}
	}
	return res;
}

int32_t main() {
	setup();

	int n;
	input(n);

	if (n == 4) {
		print("4\n1 4\n3 1\n2 1\n3 1");
		return 0;
	}

	int p = 100, q = 100;
	vector<pair<int, int>> res = get(n, p);
	vector<pair<int, int>> a = get(n / p, q);
	for (auto [y, l] : a) {
		res.push_back({p * y, p * l});
	}
	for (int y = p * q; y <= n; y += p * q) {
		res.push_back({y, p * q});
	}

	print(res.size());
	for (auto [y, l] : res) {
		print(y, l);
	}
	// assert(check(res));
}
