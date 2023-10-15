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

int modPow(int a, int b, int m) {
	int res;
	if (m == 0) {
		res = 1;
	}
	else {
 		res = 1 % m;
	}
	while (b) {
		if (b & 1) {
			if (m == 0) {
				res *= a;
			}
			else {
				res = (res * a) % m;
			}
		}

		if (m == 0) {
			a *= a;
		}
		else {
			a = (a * a) % m;
		}
		b >>= 1;
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		int res = 0;
		int m = *max_element(a.begin(), a.end());
		bool flag = true;

		range(i, 0, n) {
			int x = modPow(2, i, res);
			if (x < a[i]) {
				flag = false;
				break;
			}

			res = __gcd(res, x - a[i]);
			if (res != 0 and (x % res != a[i] or m >= res)) {
				flag = false;
				break;
			}
		}

		if (flag and res != 0) {
			print(res);
		}
		else {
			print(-1);
		}
	}
}
