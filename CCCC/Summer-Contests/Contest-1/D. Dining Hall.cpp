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

int solve(int x, int y) {
	if (x % 3 == 2 and y % 3 == 2) {
		return x + y + 1;
	}
	return x + y - 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		set<pair<int, pair<int, int>>> a, b;
		a.insert({1, {1, 1}});
		b.insert({1, {1, 1}});
		rep(i, 0, n) {
			int o;
			input(o);

			int x, y;
			if (o == 0) {
				tie(x, y) = a.begin()->second;
				b.erase(*a.begin());
				a.erase(*a.begin());
				print(x, y);
			}
			else {
				tie(x, y) = b.begin()->second;
				a.erase(*b.begin());
				b.erase(*b.begin());
				print(x, y);
			}

			if (x % 3 == 1 and y % 3 == 1) {
				a.insert({solve(x + 3, y), {x + 3, y}});
				b.insert({solve(x + 3, y), {x + 3, y}});
				a.insert({solve(x, y + 3), {x, y + 3}});
				b.insert({solve(x, y + 3), {x, y + 3}});
				b.insert({solve(x + 1, y), {x + 1, y}});
				b.insert({solve(x, y + 1), {x, y + 1}});
				b.insert({solve(x + 1, y + 1), {x + 1, y + 1}});
			}
		}
	}
}
