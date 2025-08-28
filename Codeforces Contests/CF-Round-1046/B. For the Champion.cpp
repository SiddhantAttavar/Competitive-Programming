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

int get(char c, int k) {
	print('?', c, k);
	cout.flush();
	int s;
	input(s);
	return s;
}

// int x, y;
// vector<pair<int, int>> w;

// int get(char c, int k) {
// 	if (c == 'U') {
// 		y += k;
// 	}
// 	else if (c == 'D') {
// 		y -= k;
// 	}
// 	else if (c == 'L') {
// 		x -= k;
// 	}
// 	else {
// 		x += k;
// 	}
// 	int s = 1e18;
// 	for (auto [a, b] : w) {
// 		s = min(s, abs(a - x) + abs(b - y));
// 	}
// 	return s;
// }

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		// input(x, y);

		vector<pair<int, int>> v(n);
		rep(i, 0, n) {
			input(v[i].first, v[i].second);
		}
		// w = v;

		int a = -2e9, b = -2e9;
		rep(i, 0, n) {
			a = max(a, v[i].first + v[i].second);
			b = max(b, v[i].second - v[i].first);
		}

		get('U', 1e9);
		get('U', 1e9);
		get('R', 1e9);
		int s = get('R', 1e9);

		get('L', 1e9);
		get('L', 1e9);
		get('L', 1e9);
		int t = get('L', 1e9);

		int p = s + a - 4e9;
		int q = t + b - 4e9;

		print('!', (p - q) / 2, (p + q) / 2);
		cout.flush();
	}
}
