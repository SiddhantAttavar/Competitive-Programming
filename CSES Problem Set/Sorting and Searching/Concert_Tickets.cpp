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

	int n, m;
	input(n, m);

	multiset<int> h;
	range(i, 0, n) {
		int x;
		input(x);
		h.insert(x);
	}

	range(i, 0, m) {
		int x;
		input(x);

		multiset<int>::iterator k = h.upper_bound(x);
		if (k == h.begin()) {
			print(-1);
		}
		else {
			k--;
			print(*k);
			h.erase(k);
		}
	}
}
