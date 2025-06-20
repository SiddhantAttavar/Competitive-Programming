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
	setup();

	int n;
	input(n);

	vector<vector<int>> d(n, vector<int>(n, -1));
	queue<pair<int, int>> q;
	d[0][0] = 0;
	q.push({0, 0});
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		vector<pair<int, int>> l = {
			{x - 1, y - 2},
			{x - 1, y + 2},
			{x + 1, y - 2},
			{x + 1, y + 2},
			{x - 2, y - 1},
			{x - 2, y + 1},
			{x + 2, y - 1},
			{x + 2, y + 1}
		};

		for (auto [a, b] : l) {
			if (min(a, b) >= 0 and max(a, b) < n and d[a][b] == -1) {
				d[a][b] = d[x][y] + 1;
				q.push({a, b});
			}
		}
	}
	rep(i, 0, n) {
		arrprint(d[i]);
	}
}
