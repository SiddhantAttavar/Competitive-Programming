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

const int MOD = 998244353;

int32_t main() {
	setup();
	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	int res = 0, mul = 1;
	range(i, 0, 33) {
		bool f = false;
		int x = -1;
		int e = 1, o = 1;
		range(j, 0, n) {
			vector<int> v = {-1};
			if (a[j] & (1 << i)) {
				f = !f;
				if (f) {
					int temp = e * (j - x);
					e = o;
					o = temp;
				}
				else {
					int temp = o * (j - x);
					o = e;
					e = temp;
				}
				res = (res + mul * o) % MOD;
				x = j;
			}
		}
		if (f) {
			int temp = e * (n - x);
			e = o;
			o = temp;
		}
		else {
			int temp = o * (n - x);
			o = e;
			e = temp;
		}
		res = (res + mul * o) % MOD;
		mul *= 2;

		/*
		vector<int> dp1((int) v.size() + 1, 0);
		vector<int> dp2((int) v.size() + 1, 0);

		range(j, 0, n) {
			res = (res + c) % MOD;

			if (a[j] & (1 << i)) {
				c = n - j - c;
			}
		}

		x >>= 1; */
	}
	
	print(res);
}
