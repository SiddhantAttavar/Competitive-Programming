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

#define vi vector<int> 
#define sz(x) (int) x.size()

bool check(vector<int> &a, vector<int> &b, int m, int p) {
	int l = 0;
	for (int i : a) {
		while (l < b.size() and abs(i - b[l]) + abs(b[l] - p) > m) {
			l++;
		}
		if (l == b.size()) {
			return false;
		}
		l++;
	}
	return true;
}

int32_t main() {
	setup();

	int n, k, p;
	input(n, k, p);

	vector<int> a(n), b(k);
	arrput(a);
	arrput(b);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int l = 0, r = 1e18, res = 1e18;
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(a, b, m, p)) {
			res = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	print(res);
}
