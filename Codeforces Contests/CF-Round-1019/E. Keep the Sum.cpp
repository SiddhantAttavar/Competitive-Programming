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

bool check(vector<pair<pair<int, int>, int>> &res, vector<int> &a, int k) {
	if (res.size() > 3 * a.size()) {
		return false;
	}
	for (pair<pair<int, int>, int> p : res) {
		int i = p.first.first, j = p.first.second;
		if (a[i] + a[j] != k) {
			return false;
		}
		if (p.second < -a[j] or p.second > a[i]) {
			return false;
		}
		a[i] -= p.second;
		a[j] += p.second;
	}
	rep(i, 1, a.size()) {
		if (a[i - 1] > a[i]) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrput(a);

		vector<int> b(a.begin(), a.end());

		int x = -1, y = -1;
		map<int, int> m;
		rep(i, 0, n) {
			if (m.count(k - a[i])) {
				x = m[k - a[i]];
				y = i;
				break;
			}
			m[a[i]] = i;
		}

		if (x == -1) {
			vector<int> b(a.begin(), a.end());
			sort(b.begin(), b.end());
			if (a == b) {
				print(0);
			}
			else {
				print(-1);
			}
			continue;
		}

		if (x > y) {
			swap(x, y);
		}

		vector<pair<pair<int, int>, int>> res;
		if (x > 0) {
			res.push_back({{x, y}, a[x] - a[0]});
			a[x] = a[0];
			a[y] = k - a[0];
			x = 0;
		}

		if (y < n - 1) {
			res.push_back({{y, x}, a[y] - a[n - 1]});
			a[y] = a[n - 1];
			a[x] = k - a[n - 1];
			y = n - 1;
		}

		multiset<pair<int, int>> pq;
		rep(i, 0, n) {
			if (i != x and i != y) {
				pq.insert({a[i], i});
			}
		}

		rep(i, 1, n - 1) {
			int j = pq.begin()->second;
			pq.erase(pq.begin());
			if (i == j) {
				continue;
			}
			pq.erase({a[i], i});
			res.push_back({{x, y}, a[x] - a[i]});
			a[x] = a[i];
			a[y] = k - a[x];
			res.push_back({{i, y}, a[i] - a[j]});
			a[i] = a[j];
			a[y] = k - a[i];
			res.push_back({{j, y}, a[j] - a[x]});
			a[j] = a[x];
			a[y] = k - a[x];
			pq.insert({a[j], j});
		}

		res.push_back({{x, y}, a[x]});
		a[x] = 0;
		a[y] = k;

		print(res.size());
		for (pair<pair<int, int>, int> p : res) {
			print(p.first.first + 1, p.first.second + 1, p.second);
		}
		assert(check(res, b, k));
	}
}
