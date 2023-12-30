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

	int n, m;
	input(n, m);

	vector<int> a(n), b(m);
	arrPut(a);
	arrPut(b);

	int res = (1 << 9) - 1;
	vector<vector<bool>> v(n, vector<bool>(m, true));
	for (int i = 8; i >= 0; i--) {
		res ^= 1 << i;
		bool q = true;
		vector<pair<int, int>> d;
		range(j, 0, n) {
			bool flag = false;
			range(k, 0, m) {
				if (!v[j][k]) {
					continue;
				}
				int x = a[j] & b[k];
				if (((1 << i) & x)) {
					d.push_back({j, k});
				}
				else {
					flag = true;
				}
			}
			if (!flag) {
				q = false;
			}
		}
		if (!q) {
			res ^= 1 << i;
			continue;
		}

		for (pair<int, int> p : d) {
			v[p.first][p.second] = false;
		}
	}

	print(res);
}
