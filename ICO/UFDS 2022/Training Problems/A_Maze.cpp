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
	
	int n, m, k;
	input(n, m, k);

	vector<vector<bool>> a(n, vector<bool>(m));
	vector<string> res(n);
	int s = 0;
	pair<int, int> start;
	range(i, 0, n) {
		input(res[i]);
		range(j, 0, m) {
			a[i][j] = res[i][j] == '.';
			if (a[i][j]) {
				s++;
				start = {i, j};
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(start);
	a[start.first][start.second] = false;
	range(u, 0, s - k) {
		int i, j;
		tie(i, j) = q.front();
		q.pop();
		
		res[i][j] = '_';

		vector<pair<int, int>> next = {
			{i - 1, j},
			{i + 1, j},
			{i, j - 1},
			{i, j + 1}
		};
		for (pair<int, int> v: next) {
			int x, y;
			tie(x, y) = v;
			if (x >= 0 and x < n and y >= 0 and y < m and a[x][y]) {
				a[x][y] = false;
				q.push({x, y});
			}
		}
	}

	range(i, 0, n) {
		range(j, 0, m) {
			if (res[i][j] == '.') {
				res[i][j] = 'X';
			}
			else if (res[i][j] == '_') {
				res[i][j] = '.';
			}
		}
	}
	
	range(i, 0, n) {
		print(res[i]);
	}
}
