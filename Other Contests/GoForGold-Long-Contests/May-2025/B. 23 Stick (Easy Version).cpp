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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (n == 1) {
			print("1");
			continue;
		}
		if (n == 4) {
			print("2 4 1 3");
			continue;
		}
		if (n < 4) {
			print(-1);
			continue;
		}

		n -= 5;
		int i;
		for (i = 0; i + 5 <= n; i += 5) {
			cout << i + 2 << ' ' << i + 4 << ' ' << i + 1 << ' ' << i + 3 << ' ' << i + 5 << ' ';
		}
		if (n % 5 == 4) {
			cout << i + 2 << ' ' << i + 4 << ' ' << i + 1 << ' ' << i + 3 << ' ' << i + 5 << ' ';
			i += 5;
			cout << i + 2 << ' ' << i + 4 << ' ' << i + 1 << ' ' << i + 3;
		}
		if (n % 5 == 3) {
			cout << i + 2 << ' ' << i + 5 << ' ' << i + 7 << ' ' << i + 4 << ' ' << i + 1 << ' ' << i + 3 << ' ' << i + 6 << ' ' << i + 8;
		}
		if (n % 5 == 2) {
			cout << i + 2 << ' ' << i + 5 << ' ' << i + 7 << ' ' << i + 4 << ' ' << i + 1 << ' ' << i + 3 << ' ' << i + 6;
		}
		if (n % 5 == 1) {
			cout << i + 2 << ' ' << i + 5 << ' ' << i + 3 << ' ' << i + 1 << ' ' << i + 4 << ' ' << i + 6;
		}
		if (n % 5 == 0) {
			cout << i + 2 << ' ' << i + 4 << ' ' << i + 1 << ' ' << i + 3 << ' ' << i + 5;
		}
		cout << endl;
	}
}
