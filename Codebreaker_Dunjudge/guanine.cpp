// https://codebreaker.xyz/problem/guanine
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
	int n;
	input(n);
	vector<string> a(6e5);
	int l = 3e5, r = 3e5 - 1;
	while (n--) {
		string s, x;
		input(s, x);
		if (s == "ADD_BACK") {
			r++;
			a[r] = x;
		}
		else if (s == "ADD_FRONT") {
			l--;
			a[l] = x;
		}
		else if (s == "SNIP_FRONT") {
			l += stoi(x) + 1;
		}
		else if (s == "SNIP_BACK") {
			r = l + stoi(x);
		}
		else {
			print(a[l + stoi(x)]);
		}
	}
}
