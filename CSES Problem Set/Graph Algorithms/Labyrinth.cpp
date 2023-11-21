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

	vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1},{0, 1}};
	string t = "DURL";
	map<pair<int, int>, char> o;
	range(i, 0, 4) {
		o[d[i]] = t[i];
	}

	int n, m;
	input(n, m);

	vector<vector<bool>> w(n, vector<bool>(m));
	vector<vector<pair<int, int>>> l(n, vector<pair<int, int>>(m, {-1, -1}));
	pair<int, int> x, y;
	range(i, 0, n) {
		string s;
		input(s);
		range(j, 0, m) {
			w[i][j] = s[j] == '#';
			if (s[j] == 'A') {
				x = {i, j};
			}
			else if (s[j] == 'B') {
				y = {i, j};
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(x);
	w[x.first][x.second] = true;
	while (!q.empty()) {
		pair<int, int> u = q.front();
		q.pop();

		if (u == y) {
			break;
		}

		for (pair<int, int> p : d) {
			pair<int, int> v = {u.first + p.first, u.second + p.second};
			if (v.first >= 0 and v.first < n and v.second >= 0 and v.second < m and !w[v.first][v.second]) {
				w[v.first][v.second] = true;
				l[v.first][v.second] = u;
				q.push(v);
			}
		}
	}

	if (!w[y.first][y.second]) {
		print("NO");
		return 0;
	}

	print("YES");

	string res;
	pair<int, int> c = y;
	while (c != x) {
		pair<int, int> v = l[c.first][c.second];
		res += o[{v.first - c.first, v.second - c.second}];
		c = v;
	}

	print(res.size());
	reverse(res.begin(), res.end());
	print(res);
}
