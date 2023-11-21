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

int solve_util(int x) {
	if (x == -1) {
		return 0;
	}

	if (x == 0) {
		return 1;
	}

	vector<int> d;
	range(i, 0, 18) {
		d.push_back(x % 10);
		x /= 10;
		if (x == 0) {
			break;
		}
	}
	reverse(d.begin(), d.end());
	// arrPrint(d);
 
	int c = 1;
	range(i, 0, (int) d.size() - 1) {
		c *= 9;
	}

	int res = c * (d[0] - 1);
	c /= 9;

	range(i, 1, (int) d.size()) {
		res += c * (d[i] - (d[i] > d[i - 1]));
		c /= 9;
		if (d[i] == d[i - 1]) {
			return res;
		}
	}

	return res + 1;
}

int solve(int x) {
	if (x == (int) 1e18) {
		x--;
	}

	int res = 0, c = 1;
	for (int i = 1; i <= x; i *= 10) {
		res += c;
		c *= 9;
	}

	return res + solve_util(x);
}

int32_t main() {
	setup();

	// print(solve_util(123));

	int a, b;
	input(a, b);

	// print(solve(b), solve(a - 1));
	print(solve(b) - solve(a - 1));
}
