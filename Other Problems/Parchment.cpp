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

int32_t main() {
	setup();

	int n, x;
	input(n, x);

	vector<int> a(n);
	arrput(a);

	sort(a.begin(), a.end());

	vector<int> res(x, 0);
	rep(k, 1, x + 1) {
		int i = 0;
		while (i < n) {
			i = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
			res[k - 1]++;
		}
	}
	reverse(res.begin(), res.end());

	set<int> s(a.begin(), a.end());
	int q;
	input(q);
	while (q--) {
		int f;
		input(f);

		if (f >= s.size()) {
			print(0);
			continue;
		}

		print(x - (upper_bound(res.begin(), res.end(), f) - res.begin()) + 1);
	}
}
