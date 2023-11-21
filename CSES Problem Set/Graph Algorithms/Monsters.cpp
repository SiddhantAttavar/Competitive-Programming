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

bool dfs(pair<int, int> p, int n, int m, vector<vector<bool>> &a, string &path) {
	a[p.first][p.second] = false;

	vector<pair<char, pair<int, int>>> v = {
		{'U', {p.first - 1, p.second}},
		{'D', {p.first + 1, p.second}},
		{'R', {p.first, p.second + 1}},
		{'L', {p.first, p.second - 1}},
	};

	if (p.first == 0 or p.first == n - 1 or p.second == 0 or p.second == m - 1) {
		return true;
	}

	for (pair<char, pair<int, int>> q : v) {
		if (a[q.second.first][q.second.second]) {
			path += q.first;
			if (dfs(q.second, n, m, a, path)) {
				return true;
			}
			path.pop_back();
		}
	}

	return false;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> v(n, vector<int>(m, -1));
	vector<vector<bool>> a(n, vector<bool>(m, false));
	pair<int, int> o;
	queue<pair<int, pair<bool, pair<int, int>>>> q;
	range(i, 0, n) {
		string s;
		input(s);
		range(j, 0, m) {
			if (s[j] == '#') {
				v[i][j] = 1e18;
			}
			else if (s[j] == 'A') {
				a[i][j] = true;
				v[i][j] = 0;
				q.push({0, {true, {i, j}}});
				o = {i, j};
			}
			else if (s[j] == 'M') {
				v[i][j] = 0;
				q.push({0, {false, {i, j}}});
			}
			else {
				a[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		bool b = q.front().second.first;
		pair<int, int> u = q.front().second.second;
		q.pop();

		vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (pair<int, int> p : d) {
			pair<int, int> w = {u.first + p.first, u.second + p.second};

			if (w.first >= 0 and w.first < n and w.second >= 0 and w.second < m) {
				if (v[w.first][w.second] == -1) {
					v[w.first][w.second] = true;
					a[w.first][w.second] = b;
					q.push({x + 1, {b, w}});
				}
				else if (x + 1 == v[w.first][w.second]) {
					a[w.first][w.second] = a[w.first][w.second] && b;
				}
			}
		}
	}

	// range(i, 0, n) {
	// 	arrPrint(a[i]);
	// }

	string res;
	if (dfs(o, n, m, a, res)) {
		print("YES");
		print(res.size());
		// reverse(res.begin(), res.end());
		print(res);
	}
	else {
		print("NO");
	}
}
