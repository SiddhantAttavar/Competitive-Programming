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

	int n = (int) 1e7 + 1;
	vector<int> spf(n);
	spf[1] = 1;
	range(i, 2, n) {
		spf[i] = i;
	}

	for (int i = 4; i < n; i += 2) {
		spf[i] = 2;
	}

	for (int i = 3; i * i < n; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < n; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}

	int tc; input(tc); while (tc--) {
		int l, r;
		input(l, r);

		bool flag = false;
		range(i, l, r + 1) {
			if (spf[i] != i) {
				print(spf[i], i - spf[i]);
				flag = true;
				break;
			}
		}
		if (!flag) {
			print(-1);
		}
	}
}
