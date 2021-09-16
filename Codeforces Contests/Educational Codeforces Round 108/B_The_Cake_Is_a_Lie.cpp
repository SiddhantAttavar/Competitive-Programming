#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

map<pair<pair<int, int>, int>, bool> memo;

bool solve(int i, int j, int k) {
	if (i <= 0 || j <= 0 || k < 0) {
		return false;
	}
	if (memo.find({{i, j}, k}) != memo.end()) {
		return memo[{{i, j}, k}];
	}

	return memo[{{i, j}, k}] = solve(i - 1, j, k - j) || solve(i, j - 1, k - i);
}

int main() {
	memo[{{1, 1}, 0}] = true;
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);
		print((solve(n, m, k) ? "YES" : "NO"));
	}
}