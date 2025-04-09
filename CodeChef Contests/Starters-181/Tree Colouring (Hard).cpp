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

		vector<vector<int>> graph(n);
		int x = 0;
		rep(i, 1, n) {
			int p;
			input(p);
			p--;

			x -= graph[p].size() % 2 == 1;
			graph[p].push_back(i);
			x += graph[p].size() % 2 == 1;

			if (x == 1 and graph[0].size() % 2) {
				cout << '1';
			}
			else {
				cout << '0';
			}
		}
		cout << endl;

		if (x != 1 or graph[0].size() % 2 == 0) {
			continue;
		}

		vector<int> res(n, -1);
		int t = 1;
		rep(i, 0, n) {
			for (int j = 0; j + 1 < graph[i].size(); j += 2) {
				res[graph[i][j]] = res[graph[i][j + 1]] = t++;
			}
		}
		res[0] = res[graph[0].back()] = t;
		arrprint(res);
	}
}
