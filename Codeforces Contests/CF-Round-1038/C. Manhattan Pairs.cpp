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

		vector<pair<int, int>> v(n), w(n);
		vector<int> x(n), y(n);
		rep(i, 0, n) {
			input(x[i], y[i]);

			v[i] = {x[i], i};
			w[i] = {y[i], i};
		}
		sort(v.begin(), v.end());
		sort(w.begin(), w.end());

		vector<bool> a(n), b(n);
		rep(i, 0, n) {
			a[v[i].second] = i < n / 2;
			b[w[i].second] = i < n / 2;
		}

		vector<vector<vector<int>>> l(2, vector<vector<int>>(2));
		rep(i, 0, n) {
			l[a[i]][b[i]].push_back(i);
		}

		while (!l[0][0].empty()) {
			print(l[0][0].back() + 1, l[1][1].back() + 1);
			l[0][0].pop_back();
			l[1][1].pop_back();
		}
		while (!l[0][1].empty()) {
			print(l[0][1].back() + 1, l[1][0].back() + 1);
			l[0][1].pop_back();
			l[1][0].pop_back();
		}
	}
}
