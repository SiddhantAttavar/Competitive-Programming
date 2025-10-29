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

vector<int> check(vector<int> &a, int k, int m, int x) {
	m--;
	vector<pair<int, int>> v;
	for (int i : a) {
		int l = max(0ll, i - m), r = min(x, i + m);
		if (v.empty() or l > v.back().second + 1) {
			v.push_back({l, r});
		}
		else {
			v.back().second = r;
		}
	}
	vector<int> res;
	rep(j, 0, v.front().first) {
		res.push_back(j);
		if (res.size() == k) {
			return res;
		}
	}
	rep(i, 1, v.size()) {
		rep(j, v[i - 1].second + 1, v[i].first) {
			res.push_back(j);
			if (res.size() == k) {
				return res;
			}
		}
	}
	rep(j, v.back().second + 1, x + 1) {
		res.push_back(j);
		if (res.size() == k) {
			return res;
		}
	}
	return {};
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k, x;
		input(n, k, x);

		vector<int> a(n);
		arrput(a);

		sort(a.begin(), a.end());

		vector<int> res(k);
		rep(i, 0, k) {
			res[i] = i;
		}
		int l = 1, r = 1e9;
		while (l <= r) {
			int m = (l + r) / 2;
			vector<int> v = check(a, k, m, x);
			if (!v.empty()) {
				res = v;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		arrprint(res);
	}
}
