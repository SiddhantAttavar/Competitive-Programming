// https://codebreaker.xyz/problem/catfight
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
	
	int n, p;
	input(n, p);
	vector<int> a(n);
	arrPut(a);

	int l = 0, r = 0;
	int c = a[0];
	int res = 0;
	while (l <= r + 1 and r < n) {
		if (c < p) {
			res = max(res, r - l + 1);
			r++;
			if (r < n) {
				c += a[r];
			}
		}
		else {
			c -= a[l];
			l++;
		}
	}
	print(res);
}
