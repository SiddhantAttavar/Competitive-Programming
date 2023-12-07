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
		int l, r, p;
		input(l, r, p);

		vector<int> v;
		__int128 x = p;
		do {
			v.push_back(r / x - (l - 1) / x);
			x *= p;
		} while (r >= x);

		x = 0;
		for (int i = v.size() - 1; i >= 0; i--) {
			v[i] -= x;
			x += v[i];
		}

		int res = 0;
		range(i, 0, (int) v.size()) {
			if (v[i] % 2 == 1) {
				res ^= i + 1;
			}
		}
		// arrPrint(v);

		if (res == 0) {
			print("Second");
		}
		else {
			print("First");
		}
	}
}
