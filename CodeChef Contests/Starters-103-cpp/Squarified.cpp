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

const int MAX_N = (int) 1e7;
int spf[(int) 1e7 + 10];

int32_t main() {
	spf[1] = 1;
	for (int i = 2; i <= MAX_N; i++) {
		spf[i] = i;
	}

	for (int i = 4; i <= MAX_N; i += 2) {
		spf[i] = 2;
	}

	for (int i = 3; i * i <= MAX_N; i++) {
		if (spf[i] == i) {
			for (int j = i + i; j <= MAX_N; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		map<int, int> m;

		for (int i = 0; i < n; i++) {
			vector<int> fact;
			int x = a[i];
			while (x != 1) {
				// print(x);
				// cout.flush();
				fact.push_back(spf[x]);
				x /= spf[x];
			}

			if (fact.size() == 0) {
				continue;
			}

			int y = 1, c = 1;
			for (int j = 1; j < (int) fact.size(); j++) {
				if (fact[j] != fact[j - 1]) {
					if (c % 2 == 1) {
						y *= fact[j - 1];
					}
					c = 0;
				}
				c++;
			}
			if (c % 2 == 1) {
				y *= fact[fact.size() - 1];
			}

			m[y]++;
		}

		int res = 0;
		for (pair<int, int> p : m) {
			// print(p.first, p.second);
			if (p.first != 1 && res < p.second) {
				res = p.second;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
