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

		vector<int> p(n);
		arrput(p);

		int x = 0;
		rep(i, 0, n) {
			x += p[i] == i + 1;
		}

		if (x % 2 == 0) {
			print(x / 2);
			continue;
		}

		if (n % 2 == 0 or p[n / 2] != n / 2 + 1) {
			print(x / 2 + 1);
			continue;
		}

		bool flag = true;
		int a = 0, b = 0;
		rep(i, 0, n / 2) {
			if (p[i] == i + 1) {
				a++;
			}
			else if (p[i] < n / 2 + 1) {
				flag = false;
				break;
			}
		}
		rep(i, n / 2 + 1, n) {
			if (p[i] == i + 1) {
				b++;
			}
			else if (p[i] > n / 2 + 1) {
				flag = false;
				break;
			}
		}

		if (flag and a == b) {
			print(x / 2);
		}
		else {
			print(x / 2 + 1);
		}
	}
}
