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
	int N = 5e6;
	vector<bool> v(N + 1, true);
	for (int i = 1; i <= N; i++) {
		int c = 0;
		for (int j = 5; j <= i; j *= 5) {
			c += i / j;
		}
		v[c] = false;
	} 

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int x = 0;
		for (int i = 5; i <= n; i *= 5) {
			x += n / i;
		}

		vector<int> res;
		rep(i, 1, x + 1) {
			if (v[i] and v[i - 1]) {
				res.push_back(i);
			}
		}
		print(res.size());
		arrprint(res);
	}
}
