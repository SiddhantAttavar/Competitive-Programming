#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int solve(int i, int j) {
	int res = 1;
	range(k, i - j + 1, i + 1) {
		res *= k;
	}
	return (res / j) % j;
}

int32_t main() {
	int N = 1e6;
	vector<int> spf(N + 1);
	vector<int> primes;
	range(i, 1, N + 1) {
		spf[i] = i;
	}
	range(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}

		primes.push_back(i);
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int res = 0;
		for (int j : primes) {
			if (j > n) {
				break;
			}

			range(i, 1, n / j) {
				res = (res + ((i * (j - 1)) % j) * j) % MOD;
			}
			res = (res + (((n / j) * (j - 1)) % j) * (n % j + 1)) % MOD;
		}

		if (n >= 4) {
			range(i, 1, n / 4) {
				res = (res + ((i * 2) % 4) * 4) % MOD;
			}
			res = (res + (((n / 4) * 2) % 4) * (n % 4 + 1)) % MOD;
		}

		print(res);
	}
}
