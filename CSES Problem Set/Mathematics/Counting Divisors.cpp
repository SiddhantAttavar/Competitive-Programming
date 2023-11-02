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
	int N = 1e6;
	vector<int> spf(N + 1);
	range(i, 0, N + 1) {
		spf[i] = i;
	}

	for (int i = 4; i <= N; i += 2) {
		spf[i] = 2;
	}

	for (int i = 3; i * i <= N; i++) {
		if (spf[i] == i) {
			for (int j = 2 * i; j <= N; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int x;
		input(x);

		map<int, int> m;
		while (x > 1) {
			m[spf[x]]++;
			x /= spf[x];
		}

		int res = 1;
		for (pair<int, int> p : m) {
			res *= p.second + 1;
		}
		print(res);
	}
}
