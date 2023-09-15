#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	int n;
	input(n);

	if (n % 2 == 1) {
		print(-1);
		return 0;
	}

	vector<vector<int>> res(n, vector<int>(n));
	string s;
	range(i, 0, n - 1) {
		res[0][i] = i;
		s += 'R';
	}
	res[0][n - 1] = n - 1;
	s += 'D';

	int x = n - 1, y = 1;
	int t = 0;
	res[x][y] = 0;
	while (x != 0 or y != 1) {
		if (x % 2 == 1) {
			if (y == n - 1) {
				x--;
				s += 'L';
			}
			else {
				y++;
				s += 'D';
			}
		}
		else {
			if (y == 1) {
				x--;
				s += 'L';
			}
			else {
				y--;
				s += 'U';
			}
		}

		t++;
		res[y][x] = t % n;
	}
	s += 'U';

	range(i, 0, n) {
		arrPrint(res[i]);
	}
	print(s);
}
