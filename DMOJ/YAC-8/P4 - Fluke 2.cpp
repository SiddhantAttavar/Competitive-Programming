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
	// setup();

	int n, m, t;
	input(n, m, t);

	while (t--) {
		if (max(n, m) == 2) {
			print(2);
			cout.flush();

			while (true) {
				int x, y;
				input(x, y);

				char c;
				input(c);
				if (c == 'W') {
					break;
				}

				print(1, 3 - y);
				input(c);
				if (c == 'W') {
					break;
				}
			}
			continue;
		}

		vector<vector<bool>> v(n + 1, vector<bool>(m + 1, false));

		print(1);
		int a = n / 2 + 1, b = m / 2 + 1;
		print(a, b);
		v[a][b] = true;
		char c;
		input(c);
		if (c == 'W') {
			continue;
		}
		// assert(c != 'L' and c != 'I');
		// assert(c != 'I');

		int x, y;
		input(x, y);
		v[x][y] = true;
		input(c);
		if (c == 'W') {
			continue;
		}
		// assert(c != 'L' and c != 'I');
		
		if (n == 2 and y == b) {
			int i = x, j = y - 1;
			print(i, j);
			input(c);
			if (c == 'W') {
				continue;
			}

			int p, q;
			input(p, q);
			input(c);
			if (c == 'W') {
				continue;
			}

			if (p == x and q == y) {
				x = i;
				y = j;
			}
			else {
				print(x, y + 1);
				input(c);
				continue;
			}
		}

		int p = -1, q = -1;
		while (true) {
			// print(x, y, a, b);
			// assert(v[x][y] and v[a][b]);
			if (x == a and abs(y - b) == 1) {
				if (min(y, b) > 1) {
					print(a, min(y, b) - 1);
					// assert(!v[a][min(y, b) - 1]);
				}
				else {
					print(a, max(y, b) + 1);
					// assert(!v[a][max(y, b) + 1]);
				}
				input(c);
				// assert(c == 'W');
				break;
			}
			else if (x == a and abs(y - b) == 2) {
				print(a, min(y, b) + 1);
				input(c);
				// assert(c == 'W');
				break;
			}
			else if (y == b and abs(x - a) == 1) {
				if (min(x, a) > 1) {
					print(min(x, a) - 1, b);
				}
				else {
					print(max(x, a) + 1, b);
				}
				input(c);
				// assert(c == 'W');
				break;
			}
			else if (y == b and abs(x - a) == 2) {
				print(min(x, a) + 1, b);
				input(c);
				// assert(c == 'W');
				break;
			}

			int i = (x + a + 1) / 2, j = (y + b + 1) / 2;
			if ((i == x and j == y) or (i == a and j == b)) {
				i--;
			}
			print(i, j);
			input(c);
			// assert(!v[i][j]);
			// assert(i != p or j != q);
			// assert(1 <= i and i <= n and 1 <= j and j <= m);
			// assert(c != 'I');
			// assert(c != 'L');
			v[i][j] = true;
			if (c == 'W') {
				break;
			}

			input(p, q);
			input(c);
			// assert(c != 'L');
			if (c == 'W') {
				break;
			}

			if (p == x and j == y) {
				x = i;
				y = j;
			}
			else if (p == a and q == b) {
				a = i;
				b = j;
			}
			else if (min(i, a) <= p and p <= max(i, a) and min(j, b) <= q and q <= max(j, b)) {
				x = p;
				y = q;
			}
			else {
				x = i;
				y = j;
			}
		}
	}
}
