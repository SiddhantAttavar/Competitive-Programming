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

	int n, q;
	input(n, q);

	vector<vector<bool>> a(n, vector<bool>(n));
	map<char, int> m = {{'.', -1}, {'L', 0}, {'U', 1}, {'R', 2}, {'D', 3}};
	vector<vector<pair<int, int>>> v(4);
	vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	range(i, 0, n) {
		string s;
		input(s);

		range(j, 0, n) {
			a[i][j] = m[s[j]] != -1;
			if (a[i][j]) {
				v[m[s[j]]].push_back({i, j});
			}
		}
	}

	deque<pair<pair<int, int>, int>> l;
	vector<vector<bool>> b(n, vector<bool>(n, false));
	l.push_back({{0, 0}, 0});
	b[0][0] = true;
	int c = 0;
	while (!l.empty()) {
		int x, y, k = l.front().second;
		tie(x, y) = l.front().first;

		if (k != c) {
			range(i, 0, 4) {
				for (pair<int, int> p : v[i]) {

				}
			}
			c++;
		}

		if (x == n and y == n) {
			print(d);
			return 0;
		}
	}
}
