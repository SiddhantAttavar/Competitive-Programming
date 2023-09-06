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
		int n;
		input(n);

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		vector<int> pre(n), suf(n);
		pre[0] = a[0];
		range(i, 1, n) {
			pre[i] = __gcd(pre[i - 1], a[i]);
		}

		suf[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			suf[i] = __gcd(suf[i + 1], a[i]);
		}

		int res = max({
			pre[n - 1],
			__gcd(pre[n - 2], b[n - 1]),
			__gcd(suf[1], b[0]),
		});
		range(i, 1, n - 1) {
			res = max(res, __gcd(b[i], __gcd(pre[i - 1], suf[i + 1])));
		}
		print(res);
	}
}
