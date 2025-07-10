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

int calc(int n) {
	if (n < 2) {
		return 0;
	}
	return 4 * n * n * n + 6 * n * n + 4 * n + 1;
}

vector<vector<int>> solve(int n) {
	n++;
	vector<vector<int>> res;
	rep(i, 1, n) {
		rep(j, 1, n) {
			rep(k, 1, n) {
				res.push_back({i, j, k, n});
				res.push_back({i, j, n, k});
				res.push_back({i, n, j, k});
				res.push_back({n, i, j, k});
			}
			res.push_back({i, j, n, n});
			res.push_back({i, n, j, n});
			res.push_back({n, i, j, n});
			res.push_back({i, n, n, j});
			res.push_back({n, i, n, j});
			res.push_back({n, n, i, j});
		}
		res.push_back({i, n, n, n});
		res.push_back({n, i, n, n});
		res.push_back({n, n, i, n});
		res.push_back({n, n, n, i});
	}
	res.push_back({n, n, n, n});
	sort(res.begin(), res.end());
	return res;
}

bool check(vector<int> &v) {
	return false;
}

int32_t main() {
	setup();

	int l, r;
	input(l, r);

	l--;
	r--;

	int k = 0, n = 2;
	while (k + calc(n) < l) {
		k += calc(n);
		n++;
	}

	vector<vector<int>> res;
	int x = l - k;
	while (k < r) {
		vector<vector<int>> v = solve(n);
		// print(v.size(), calc(n), n);
		// cout.flush();
		res.insert(res.end(), v.begin(), v.end());
		k += calc(n);
		assert(calc(n) == v.size());
		n++;
	}
	res.erase(res.begin(), res.begin() + x);
	res.erase(res.begin() + r - l + 1, res.end());

	for (vector<int> v : res) {
		printf("%Ld^%Ld+%Ld^%Ld%c%Ld^%Ld\n", v[0], v[3], v[1], v[3], check(v) ? '<' : '>', v[2], v[3]);
	}
}
