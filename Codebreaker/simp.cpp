// https://codebreaker.xyz/problem/simp
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
#define int long long

int32_t main() {
	setup();
	int n;
	input(n);
	
	int a1, a2;
	input(a1, a2);
	a1--;
	a2--;

	int b1, b2;
	input(b1, b2);
	b1--;
	b2--;
	
	int c1, c2;
	input(c1, c2);
	c1--;
	c2--;

	vector<vector<bool>> grid(n, vector<bool>(n));
	range(i, 0, n) {
		range(j, 0, n) {
			grid[i][j] = (a1 == i) or (a2 == j) or (abs(a1 - i) == abs(a2 - j));
		}
	}
	grid[b1][b2] = false;
	
	queue<pair<int, int>> q;
	q.push({b1, b2});
	bool flag = false;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		if (x == c1 and y == c2) {
			flag = true;
			break;
		}

		if (x < 0 or x >= n or y < 0 or y >= n or grid[x][y]) {
			continue;
		}
		grid[x][y] = true;
		
		vector<pair<int, int>> next = {
			{x - 1, y - 1},
			{x - 1, y},
			{x - 1, y + 1},
			{x, y - 1},
			{x, y + 1},
			{x + 1, y - 1},
			{x + 1, y},
			{x + 1, y + 1},
		};
		for (pair<int, int> p : next) {
			q.push(p);
		}
	}

	if (flag) {
		print("YES");
	}
	else {
		print("NO");
	}
}
