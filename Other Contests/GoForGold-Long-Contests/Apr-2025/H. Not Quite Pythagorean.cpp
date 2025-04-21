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

bool check(int a, int b, int c, int d) {
	return a * a + b * b == c * c + d and min({a, b, c}) >= 1 and max({a, b, c}) <= 1e9 and a + b > c and a + c > b and b + c > a;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int d;
		input(d);

		if (d > 12) {
			if (d % 2) {
				assert(check((d - 5) / 2 + 1, 2, (d - 5) / 2, d));
				print((d - 5) / 2 + 1, 2, (d - 5) / 2);
			}
			else {
				assert(check((d - 10) / 2 + 1, 3, (d - 10) / 2, d));
	 			print((d - 10) / 2 + 1, 3, (d - 10) / 2);
			}
			continue;
		}

		if (d < 0) {
			if (d % 2 == -1) {
				assert(check((3 - d) / 2, 2, (3 - d) / 2 + 1, d));
				print((3 - d) / 2, 2, (3 - d) / 2 + 1);
			}
			else {
				assert(check((8 - d) / 2, 3, (8 - d) / 2 + 1, d));
				print((8 - d) / 2, 3, (8 - d) / 2 + 1);
			}
			continue;
		}

		bool flag = false;
		rep(a, 1, 11) {
			rep(b, 1, 11) {
				rep(c, 1, 11) {
					if (check(a, b, c, d)) {
						print(a, b, c);
						flag = true;
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			print(-1);
		}
	}
}
