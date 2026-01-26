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
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		if (n % 2 == 0) {
			print("NO");
			continue;
		}

		int x = 0, y = 0;
		for (int i : a) {
			x += i % 3 == 0;
			x += i % 5 == 0;
			if (i % 2 == 1) {
				continue;
			}

			int c = 0;
			while (i % 2 == 0) {
				c++;
				i /= 2;
			}
			x += c % 2 == 0;
			y += c % 2 == 1;
		}

		if ((x + y) % 2) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
