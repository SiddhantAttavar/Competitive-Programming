#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
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

		vector<int> a(n);
		arrput(a);

		bool flag = false;
		if (a.size() <= 32) {
			rep(i, 0, n) {
				rep(j, i + 1, n) {
					if ((a[j] % a[i]) % 2 == 0) {
						print(a[i], a[j]);
						cout.flush();
						flag = true;
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
			continue;
		}

		vector<int> x, y;
		for (int i : a) {
			if (i % 2 == 0) {
				x.push_back(i);
			}
			else {
				y.push_back(i);
			}
		}

		if (x.size() >= 2) {
			print(x[0], x[1]);
			continue;
		}

		rep(i, 1, y.size()) {
			if ((y[i] % y[i - 1]) % 2 == 0) {
				print(y[i - 1], y[i]);
				break;
			}
		}
	}
}
