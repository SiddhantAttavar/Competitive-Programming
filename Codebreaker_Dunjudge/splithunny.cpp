// https://codebreaker.xyz/problem/splithunny
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
	
	int r, c;
	input(r, c);
	vector<vector<bool>> a(r, vector<bool>(c));
	range(i, 0, r) {
		string s;
		input(s);
		range(j, 0, c) {
			a[i][j] = s[j] == 'H';
		}
	}
	
	vector<vector<bool>> visited(r, vector<bool>(c));
	int res = 0;
	range(i, 0, r) {
		range(j, 0, c) {
			if (a[i][j] and !visited[i][j]) {
				queue<pair<int, int>> q;
				q.push({i, j});
				while (!q.empty()) {
					int x, y;
					tie(x, y) = q.front();
					q.pop();

					vector<pair<int, int>> next = {
						{x - 1, y},
						{x + 1, y},
						{x, y - 1},
						{x, y + 1}
					};
					for (pair<int, int> p : next) {
						int m, n;
						tie(m, n) = p;
						if (m < 0 or m >= r or n < 0 or n >= c) {
							continue;
						}
						if (visited[m][n] or !a[m][n]) {
							continue;
						}
						visited[m][n] = true;
						q.push({m, n});
					}
				}
				res++;
			}
		}
	}
	print("Oh, bother. There are", res, "pools of hunny.");
}
