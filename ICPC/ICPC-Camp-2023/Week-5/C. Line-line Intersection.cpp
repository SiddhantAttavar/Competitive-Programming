#include <bits/stdc++.h>
using namespace std;
char getChar() {
	char c;
	cin >> c;
	return c;
}
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
// template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
// template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int __int128

int32_t main() {
	setup(); int tc = read(); while (tc--) {
		int n = read();

		vector<int> v[n];
		range(i, 0, n) {
			v[i] = vector<int>(4);
			range(j, 0, 4) {
				v[i][j] = read();
			}
		}

		sort(v, v + n, [](vector<int> a, vector<int> b) {
			int ax = a[2] - a[0];
			int ay = a[3] - a[1];

			int bx = b[2] - b[0];
			int by = b[3] - b[1];

			vector<int> at = {ay * bx, (ax * a[1] - ay * a[0]) * bx, a[0]};
			vector<int> bt = {by * ax, (bx * b[1] - by * b[0]) * ax, b[0]};

			return at < bt;
		});

		int x = 0, y = 0;
		int p = 1, q = 1;
		range(i, 1, n) {
			int ax = v[i][2] - v[i][0];
			int ay = v[i][3] - v[i][1];

			int bx = v[i - 1][2] - v[i - 1][0];
			int by = v[i - 1][3] - v[i - 1][1];

			vector<int> at = {ay * bx, (ax * v[i][1] - ay * v[i][0]) * bx, v[i][0]};
			vector<int> bt = {by * ax, (bx * v[i - 1][1] - by * v[i - 1][0]) * ax, v[i - 1][0]};

			if (at[0] == bt[0]) {
				p++;

				if ((at[1] == bt[1]) and (ax != 0 or bx != 0 or at[2] == bt[2])) {
					q++;
				}
				else {
					y += q * (q - 1) / 2;
					q = 1;
				}
			}
			else {
				x += p * (p - 1) / 2;
				p = 1;

				y += q * (q - 1) / 2;
				q = 1;
			}
		}

		x += p * (p - 1) / 2;
		y += q * (q - 1) / 2;

		// print(x, y);
		print(n * (n - 1) / 2 - x + y);
		putchar('\n');
	}
}
