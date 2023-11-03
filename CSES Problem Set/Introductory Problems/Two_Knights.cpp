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
#define int __int128

int32_t main() {
	setup();

	long long n;
	input(n);

	for (int k = 1; k <= n; k++) {
		print((long long) (
			k * k * (k * k - 1) / 2 - 
			4 * (k - 4) * (k - 2) - 
			10 * (k - 2) - 
			2 * (k - 4) - 
			4
		));
	}
}
