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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

int solve(int i, int j, int lx, int rx, int ly, int ry, vector<string> &res) {
	int n = sz(res);
	if (lx == rx) {
		assert(lx == i);
		res[i] = string(n, '0');
		if (j) {
			res[i][j - 1] = '1';
			return 1;
		}
		return 0;
	}

	int z;
	if (lx == i) {
		// down
		z = solve(i, j, lx, rx - 1, ly, ry, res);
		z += n;
		if (z % 2 == 1) {
			res[rx][n - 1] = '0';
			z--;
		}
		assert(z % 2 == 0);
	}
	else {
		// up
		z = solve(i, j, lx + 1, rx, ly, ry, res);
		z += n;
		if (z % 2 == 0) {
			res[lx][n - 1] = '0';
			z--;
		}
		assert(z % 2 == 1);
	}
	return z;

}

bool check(int x, int y, string &s, vector<string> &t) {
	int n = sz(t);
	vector<vi> p(n + 1, vi(n + 1, 0));
	rep(i, 0, n) {
		rep(j, 0, n) {
			p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + (t[i][j] == '1');
		}
	}
	if (p[n][n] < n * n - 24) {
		return false;
	}
	int x0 = 0, y0 = 0, x1 = n - 1, y1 = n - 1;
	while (x0 <= x1 and y0 <= y1) {
		if (x0 == x and x == x1 and y0 == y and y == y1) {
			return true;
		}
		int z = p[x1 + 1][y1 + 1] - p[x1 + 1][y0] - p[x0][y1 + 1] + p[x0][y0];
		if (s[z] == 'U') {
			x0++;
		}
		else if (s[z] == 'L') {
			y0++;
		}
		else if (s[z] == 'D') {
			x1--;
		}
		else if (s[z] == 'R') {
			y1--;
		}
	}
	return false;
}

int32_t main() {
	setup();

	int n;
	input(n);

	if (n == 3) {
		print(R"""(111
111
001

011
111
100

110
110
110

010
111
111

111
111
111

010
111
101

111
111
110

111
011
111

011
010
111

DURLDULRUU
		)""");
		return 0;
	}

	string s(n * n + 1, 'U');
	s[0] = 'R';
	s[1] = 'L';
	rep(i, 2, n * n + 1) {
		if (i % 2) {
			s[i] = 'U';
		}
		else {
			s[i] = 'D';
		}
	}

	rep(i, 0, n) {
		rep(j, 0, n) {
			vector<string> t(n, string(n, '1'));
			int z = solve(i, j, 0, n - 1, 0, n - 1, t);
			rep(k, 0, n) {
				print(t[k]);
			}
			print("");
			// cout.flush();
			assert(z >= n * n - 24);
			assert(check(i, j, s, t));
		}
	}

	print(s);
}
