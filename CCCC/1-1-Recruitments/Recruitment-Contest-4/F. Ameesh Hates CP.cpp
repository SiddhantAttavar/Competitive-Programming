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

bool check(vector<int> pref, vector<int> a, int k) {
	int n = a.size();
	range(i, k + 1, n) {
		int x = (pref[i] ^ pref[i - k]);
		if (a[i - k] > x or x > a[i]) {
			return true;
		}
	}

	return (a[0] > pref[k]) or ((pref[n - 1] ^ pref[n - 1 - k]) > a[n - 1]);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	if (n > 60) {
		print(1);
		return 0;
	}

	int res = n;
	range(i, 0, n) {
		int x = a[i];
		range(j, i + 1, n) {
			int y = a[j];
			range(k, j + 1, n) {
				if (x > y) {
					// print(x, y, i, j, k);
					res = min(res, (int) k - i - 2);
				}
				y ^= a[k];
			}
			if (x > y) {
				// print(x, y, i, j, n);
				res = min(res, (int) n - i - 2);
			}
			x ^= a[j];
		}
	}

	if (res == n) {
		print(-1);
	}
	else {
		print(res);
	}
}
