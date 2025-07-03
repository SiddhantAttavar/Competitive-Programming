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

	const int N = 1e7;
	vector<int> p;
	vector<bool> s(N + 1, true);

	int l, r;
	input(l, r);

	vector<bool> t(r - l + 1, true);
	vector<bool> q(r - l + 1, false);
	rep(i, 2ll, N + 1) {
		if (!s[i]) {
			continue;
		}
		p.push_back(i);
		for (int j = i; j <= N; j += i) {
			s[j] = false;
		}
		for (int j = l - l % i + i * (l % i > 0); j <= r; j += i) {
			t[j - l] = false;
		}
		for (__int128_t j = i; j <= r; j *= i) {
			if (j >= l) {
				q[j - l] = true;
			}
		}
	}

	int res = 1;
	rep(i, l + 1, r + 1) {
		res += t[i - l] or q[i - l];
	}
	print(res);
}
