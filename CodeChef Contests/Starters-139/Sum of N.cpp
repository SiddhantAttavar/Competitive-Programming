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

int32_t main() {
	int N = 1e6;
	vector<int> spf(N + 1, true);
	range(i, 0, N + 1) {
		spf[i] = i;
	}
	vector<int> primes;
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

	vector<int> pref(primes.size() + 1, 0);
	range(i, 0, primes.size()) {
		pref[i + 1] = pref[i] + primes[i];
	}

	setup(); int tc; input(tc); while (tc--) {
		int k;
		input(k);

		print(k * (
			// pref[upper_bound(primes.begin(), primes.end(), k) - primes.begin()] - 
			pref[lower_bound(primes.begin(), primes.end(), spf[k]) - primes.begin() + 1]
		));
	}
}