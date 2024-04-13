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

int check(vector<vector<int>> &b) {
	range(i, 0, 3) {
		if (b[i][0] != 0 and b[i][0] == b[i][1] and b[i][0] == b[i][2]) {
			return b[i][0];
		}
	}

	range(j, 0, 3) {
		if (b[0][j] != 0 and b[0][j] == b[1][j] and b[0][j] == b[2][j]) {
			return b[0][j];
		}
	}

	if (b[0][0] != 0 and b[0][0] == b[1][1] and b[0][0] == b[2][2]) {
		return b[0][0];
	}
	if (b[0][2] != 0 and b[0][2] == b[1][1] and b[0][2] == b[2][0]) {
		return b[0][2];
	}

	return 0;
}

int solve(vector<vector<int>> &a, vector<vector<int>> &b) {
	int k = check(b);
	if (k != 0) {
		return -1e15;
	}

	int p = 0, x = 0;
	range(i, 0, 3) {
		range(j, 0, 3) {
			x += b[i][j] != 0;
		}
	}
	if (x == 9) {
		return 0;
	}

	if (x % 2 == 0) {
		p = 1;
	}
	else {
		p = -1;
	}

	int res = -1e18;
	range(i, 0, 3) {
		range(j, 0, 3) {
			if (!b[i][j]) {
				b[i][j] = p;
				res = max(res, a[i][j] - solve(a, b));
				b[i][j] = 0;
			}
		}
	}

	return res;
}

int32_t main() {
	setup();

	vector<vector<int>> a(3, vector<int>(3));
	range(i, 0, 3) {
		arrPut(a[i]);
	}

	vector<vector<int>> b(3, vector<int>(3, 0));
	if (solve(a, b) > 0) {
		print("Takahashi");
	}
	else {
		print("Aoki");
	}
}
