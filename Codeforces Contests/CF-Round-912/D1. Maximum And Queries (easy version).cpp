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

	vector<int> a(n);
	arrPut(a);

	while (q--) {
		int k;
		input(k);

		vector<int> b(a.begin(), a.end());

		int res = 0;
		for (int i = 60; i >= 0; i--) {
			__int128_t x = 0;
			range(j, 0, n) {
				if ((b[j] & (1ll << i)) == 0) {
					x += (1ll << i) - (b[j] & ((1ll << i) - 1));
				}
			}

			if (x <= k) {
				k -= x;
				res += (1ll << i);

				// print(res, k);

				range(j, 0, n) {
					if ((b[j] & (1ll << i)) == 0) {
						b[j] = (1ll << i);
					}
				}
			}
		}

		print(res);
	}
}
