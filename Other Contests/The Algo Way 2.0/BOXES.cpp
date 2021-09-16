#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(arr) for (auto &inVar : arr) {cin >> inVar;}
#define arrPrint(arr) for (auto &outVar : arr) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	setup();
	vi a;
	int x;
	while (cin >> x) {
		a.push_back(x);
	}
	
	int n = a.size();
	ll end[n] = {a[0]};
	range(i, 1, n) {
		end[i] = max(end[i - 1], (ll) 0) + a[i];
	}

	ll start[n];
	start[n - 1] = max(0, a[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		start[i] = max(a[i] + start[i + 1], (ll) 0);
	}

	ll res = start[0];
	range(i, 1, n - 1) {
		res = max(res, end[i - 1] + start[i + 1]);
	}
	print(max(res, start[n - 2]));
}