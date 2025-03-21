#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

const int N = 1000, m = 1000;
vector<vector<int>> a(N, vector<int>(N));
vector<vector<int>> t(4 * N + 1, vector<int>(4 * N + 1));

//a[n][m] is the given array
// t[4*n+1][4*m+1] is the segment tree array to be made
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry) {
		if (lx == rx)
			t[vx][vy] = a[lx][ly];
		else
			t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
	} else {
		int my = (ly + ry) / 2;
		build_y(vx, lx, rx, vy*2, ly, my);
		build_y(vx, lx, rx, vy*2+1, my+1, ry);
		t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
	}
}
void build_x(int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		build_x(vx*2, lx, mx);
		build_x(vx*2+1, mx+1, rx);
	}
	build_y(vx, lx, rx, 1, 0, m-1);
}
int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return t[vx][vy];
	int tmy = (tly + try_) / 2;
	return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
		+ sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}
int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int
		ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return sum_y(vx, 1, 0, m-1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
		+ sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry
			   );
}
void update_y(int vx, int lx, int rx, int vy, int ly, int ry,
		int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx)
			t[vx][vy] = new_val;
		else
			t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
	} else {
		int my = (ly + ry) / 2;
		if (y <= my)
			update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
		else
			update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y,
					new_val);
		t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
	}
}
void update_x(int vx, int lx, int rx, int x, int y, int new_val
		) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		if (x <= mx)
			update_x(vx*2, lx, mx, x, y, new_val);
		else
			update_x(vx*2+1, mx+1, rx, x, y, new_val);
	}
	update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	rep(i, 0, n) {
		string s;
		input(s);
		rep(j, 0, n) {
			a[j][i] = s[j] == '*';
		}
	}
	build_x(1, 0, n - 1);

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int y, x;
			input(y, x);

			x--;
			y--;
			a[x][y] = !a[x][y];
			update_x(1, 0, n - 1, x, y, a[x][y]);
		}
		else {
			int a, b, c, d;
			input(a, b, c, d);
			print(sum_x(1, 0, n - 1, b - 1, d - 1, a - 1, c - 1));
		}
	}
}
