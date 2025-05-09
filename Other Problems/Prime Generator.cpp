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
	int N = 1e6;
	vector<bool> seive(N + 1, true);
	vector<int> p;
	rep(i, 2, N + 1) {
		if (!seive[i]) {
			continue;
		}
		p.push_back(i);
		for (int j = i; j <= N; j += i) {
			seive[j] = false;
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int l, r;
		input(l, r);

		vector<bool> b(r - l + 1, true);
		for (int i : p) {
			for (int j = max((int) 2, (l + i - 1) / i) * i; j <= r; j += i) {
				b[j - l] = false;
			}
		}
		if (l == 1) {
			b[0] = false;
		}
		rep(i, l, r + 1) {
			if (b[i - l]) {
				print(i);
			}
		}
		print("");
	}
}
