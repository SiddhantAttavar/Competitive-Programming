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

	int MAX_N = 1e6;
	vector<vector<int>> factors(MAX_N);
	range(i, 2, MAX_N + 1) {
		if (factors[i].size()) {
			continue;
		}

		for (int j = i; j <= MAX_N; j += i) {
			factors[j].push_back(i);
		}
	}

	int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		map<int, int> m;
		int o = n;
		for (int p : factors[n]) {
			while (o % p == 0) {
				m[p]++;
				o /= p;
			}
		}

		while (q--) {
			int k, x;
			input(k);

			if (k == 1) {
				input(x);
			}
			else {
				x = n;
				m = map<int, int>();
			}

			int o = x;
			for (int p : factors[x]) {
				while (o % p == 0) {
					m[p]++;
					o /= p;
				}
			}

			if (k == 1) {
				int res = 1;
				for (pair<int, int> p : m) {
					res *= p.second + 1;
				}
				print(res);
			}
		}
	}
}
