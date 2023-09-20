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
		int a, b;
		input(a, b);
		
		if (a > b) {
			swap(a, b);
		}

		/* int x = 0;
		for (int i = 30; i >= 0; i--) {
			if (!((1 << i) & a) and ((1 << i) & b)) {
				// print('d', i);
				int a1 = a ^ (1 << i);
				int b1 = b ^ (1 << i);
				if (abs((a1 ^ x) - (b1 ^ x)) < abs((a ^ x) - (b ^ x))) {
					// print("debug");
					a = b1;
					b = a1;
					x ^= (1 << i);
				}
			}
		} */
		
		int x = 0, flag = false;
		for (int i = 30; i >= 0; i--) {
			if (((1 << i) & a) or !((1 << i) & b)) {
				continue;
			}

			if (!flag) {
				flag = true;
				continue;
			}

			x ^= (1 << i);
		}


		print(x);
		// print(abs((a ^ x) - (b ^ x)));
	}
}
