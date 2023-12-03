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

		vector<int> a(n);
		arrPut(a);

		int y = *max_element(a.begin(), a.end());
		int x = -1;
		for (int i : a) {
			if (x == -1) {
				if (i != y) {
					x = y - i;
				}
			}
			else {
				x = __gcd(x, y - i);
			}
		}

		if (x == -1) {
			x = 1;
		}

		int res = 0;
		for (int i : a) {
			res += (y - i) / x;
		}

		set<int> s(a.begin(), a.end());
		int z = y - x;
		while (s.count(z)) {
			z -= x;
		}

		print(res + (y - z) / x);
	}
}
