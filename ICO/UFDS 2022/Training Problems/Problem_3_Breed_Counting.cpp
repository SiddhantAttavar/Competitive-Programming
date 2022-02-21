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
	
	if (fopen("bcount.in", "r")) {
		freopen("bcount.in", "r", stdin);
		freopen("bcount.out", "w", stdout);
	}

	int n, q;
	input(n, q);

	vector<vector<int>> p(n + 1, vector<int>(3));
	range(i, 1, n + 1) {
		range(j, 0, 3) {
			p[i][j] = p[i - 1][j];
		}
		int x;
		input(x);
		p[i][x - 1]++;
	}

	while (q--) {
		int l, r;
		input(l, r);
		print(
			p[r][0] - p[l - 1][0], 
			p[r][1] - p[l - 1][1], 
			p[r][2] - p[l - 1][2]
		);
	}
}
