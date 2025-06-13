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

	string k;
	input(k);

	int d;
	input(d);

	vector<int> f(d, 0);
	int c = 0;
	rep(i, 0, k.size()) {
		vector<int> nf(d, 0);
		int x = k[i] - '0';
		rep(j, 0, 10) {
			rep(l, 0, d) {
				nf[(l + j) % d] = (nf[(l + j) % d] + f[l]) % MOD;
			}
			if (j < x) {
				nf[(c + j) % d] = (nf[(c + j) % d] + 1) % MOD;
			}
		}
		f = nf;
		c = (c + x) % d;
	}
	f[0] = (f[0] + MOD - 1) % MOD;
	f[c] = (f[c] + 1) % MOD;
	print(f[0]);
}
