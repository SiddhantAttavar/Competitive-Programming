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
		int n, m;
		input(n, m);

		vector<int> a(n);
		arrPut(a);

		vector<int> b(n);
		b[0] = a[0];
		int x = a[0];
		range(i, 1, n) {
			int k2 = x / a[i];
			for (int j = m / a[i]; j >= 1; j--) {
				if (__gcd(k2, j) == 1) {
					b[i] = a[i] * j;
					x = __gcd(x, b[i]);
					break;
				}
			}
		}

		arrPrint(b);
	}
}
