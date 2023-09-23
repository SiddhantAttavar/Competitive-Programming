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

	int n, x;
	input(n, x);

	vector<int> a(n - 1);
	arrPut(a);

	int y = 0, z = 0, t = 100;
	for (int i : a) {
		y += i;
		z = max(z, i);
		t = min(t, i);
	}

	if (y - z >= x) {
		print(0);
	}
	else if (x - (y - t - z) <= z) {
		print(x - (y - t - z));
	}
	else if (y - t >= x) {
		print(z);
	}
	else {
		print(-1);
	}
} 
