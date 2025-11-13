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
		string s;
		input(s);

		int n = s.size(), u = s.find('0');
		if (u == string::npos) {
			print(1, n, 1, 1);
			continue;
		}

		vector<bool> a(n);
		rep(i, 0, n) {
			a[i] = s[i] == '1';
		}

		vector<int> v;
		rep(i, 0, u) {
			v.push_back(i);
		}

		int res = 0;
		rep(i, u, n) {
			vector<int> x, y;
			for (int j : v) {
				if (a[i] ^ a[i + j - u]) {
					x.push_back(j);
				}
				else {
					y.push_back(j);
				}
			}
			v = x.empty() ? y : x;
			res = v[0];
		}
		print(1, n, res + 1, res + n - u);
	}
}
