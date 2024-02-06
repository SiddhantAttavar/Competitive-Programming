#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<bool>> v(n, vector<bool>(n, false));
	int x = -1, y, a, b;
	range(i, 0, n) {
		string s;
		input(s);

		range(j, 0, n) {
			v[i][j] = s[j] == '#';
			if (s[j] == 'P') {
				if (x == -1) {
					x = i;
					y = j;
				}
				else {
					a = i;
					b = j;
				}
			}
		}
	}

	vector<vector<vector<vector<bool>>>> s(n, vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(n, false))));
	s[x][y][a][b] = true;
	queue<tuple<int, int, int, int, int>> q;
	q.push({x, y, a, b, 0});

	while (!q.empty()) {
		int x, y, a, b, d;
		tie(x, y, a, b, d) = q.front();
		q.pop();

		if (x == a and y == b) {
			print(d);
			return 0;
		}

		vector<pair<int, int>> p = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (pair<int, int> o : p) {
			int i, j;
			tie(i, j) = o;
			int nx = x + i, ny = y + j, na = a + i, nb = b + j;
			if (min(nx, ny) < 0 or max(nx, ny) >= n or v[nx][ny]) {
				nx = x;
				ny = y;
			}
			if (min(na, nb) < 0 or max(na, nb) >= n or v[na][nb]) {
				na = a;
				nb = b;
			}
			if (!s[nx][ny][na][nb]) {
				s[nx][ny][na][nb] = true;
				q.push({nx, ny, na, nb, d + 1});
			}
		}
	}

	print(-1);
}
