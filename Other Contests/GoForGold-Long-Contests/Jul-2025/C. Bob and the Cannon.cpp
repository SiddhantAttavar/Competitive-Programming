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
		int n, m, x, y;
		input(n, m, x, y);

		vector<string> a(n);
		arrput(a);

		int u = -1, v = -1;
		rep(i, 0, n) {
			rep(j, 0, m) {
				if (a[i][j] == 'c') {
					u = i;
					v = j;
					break;
				}
			}
		}

		int p = u - 1, q = v;
		vector<vector<bool>> l(n, vector<bool>(m, false));
		while (p >= 0 and a[p][q] == '.') {
			l[p][q] = true;
			p--;
		}
		p++;

		p = u + 1;
		while (p < n and a[p][q] == '.') {
			l[p][q] = true;
			p++;
		}
		p--;

		p = u;
		q = v - 1;
		while (q >= 0 and a[p][q] == '.') {
			l[p][q] = true;
			q--;
		}
		q++;

		q = v + 1;
		while (q < m and a[p][q] == '.') {
			l[p][q] = true;
			q++;
		}
		q--;

		bool flag = false;
		x--;
		y--;
		rep(i, 0, n) {
			if (l[i][y]) {
				flag = true;
				break;
			}
		}
		rep(j, 0, m) {
			if (l[x][j]) {
				flag = true;
				break;
			}
		}

		if (flag) {
			print("Yes");
		}
		else {
			print("No");
		}
	}
}
