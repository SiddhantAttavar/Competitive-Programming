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
typedef long long ll;
const int MOD = 1e9 + 7;

int modPow(ll a, int b) {
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

int main() {
	setup();
	const int MAX_N = 1e5;
	ll factorial[MAX_N + 1] = {1};
	range(i, 1, MAX_N + 1) {
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
	int tc; input(tc); while (tc--) {
		int n, k; input(n, k);
		if (k < n) {
			print((factorial[k] * modPow(k + 1, n - k)) % MOD);
		}
		else {
			print(factorial[n]);
		}
	}
}