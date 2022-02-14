// https://codebreaker.xyz/problem/arrayfind
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	int n, q;
	input(n, q);
	vector<int> a(n);
	arrPut(a);
	sort(a.begin(), a.end());
	while (q--) {
		int x;
		input(x);
		int l = lower_bound(a.begin(), a.end(), x) - a.begin();
		int r = n - (upper_bound(a.begin(), a.end(), x) - a.begin());
		cout << "Smaller: " << l << ", Greater: " << r << endl;
	}
}
