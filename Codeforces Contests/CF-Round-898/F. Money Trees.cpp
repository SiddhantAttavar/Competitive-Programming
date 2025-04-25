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
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n), h(n);
		arrPut(a);
		arrPut(h);

		int res = a[0] <= k, l = a[0] > k, s = a[0] <= k ? a[0] : 0;
		range(i, 1, n) {
			if (h[i - 1] % h[i] != 0) {
				l = i;
				s = 0;
			}

			s += a[i];
			while (s > k) {
				s -= a[l];
				l++;
			}

			res = max(res, i - l + 1);
		}

		print(res);
	}
}
