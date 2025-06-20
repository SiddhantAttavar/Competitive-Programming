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
	vector<int> fact(21, 1);
	rep(i, 2, 21) {
		fact[i] = i * fact[i - 1];
	}

	setup(); int tc; input(tc); while (tc--) {
		int x, n;
		input(x, n);

		ordered_set o;
		rep(i, 0, n) {
			o.insert(i + 1);
		}
		if (x == 1) {
			int k;
			input(k);
			k--;

			vector<int> p(n);
			rep(i, 0, n) {
				p[i] = *o.find_by_order(k / fact[n - i - 1]);
				o.erase(p[i]);
				k %= fact[n - i - 1];
			}
			arrprint(p);
		}
		else {
			vector<int> p(n);
			arrput(p);

			int k = 1;
			rep(i, 0, n) {
				k += o.order_of_key(p[i]) * fact[n - i - 1];
				o.erase(p[i]);
			}
			print(k);
		}
	}
}
