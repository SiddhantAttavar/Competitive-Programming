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

bool check(vector<int> a, int m) {
	int k = 0;
	for (int i = a.size() - 1; i > 0; i--) {
		if (a[i] > m) {
			return false;
		}
		a[i - 1] -= m - a[i];
		a[i] = m;
	}
	return a[0] <= m;
}

bool check2(vector<int> a, int m) {
	rep(i, 0, a.size() - 1) {
		if (a[i] < m) {
			return false;
		}
		a[i + 1] += a[i] - m;
	}
	return a.back() >= m;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		int l = 0, r = 1e12, y = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(a, m)) {
				y = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}

		l = 0, r = 1e12;
		int x = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check2(a, m)) {
				x = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(y - x);
	}
}
