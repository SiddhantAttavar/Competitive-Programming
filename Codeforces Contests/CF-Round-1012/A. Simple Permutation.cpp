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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	int N = 1e5;
	vector<int> spf(N + 1);
	vector<int> primes;
	rep(i, 0, N + 1) {
		spf[i] = i;
	}
	rep(i, 2, N + 1) {
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

		int p = 2;
		for (int i : primes) {
			if (abs(2 * i - n) <= abs(2 * p - n)) {
				p = i;
			}
		}

		vector<int> res = {p};
		int l = p - 1, r = p + 1;
		while (l > 0 and r <= n) {
			res.push_back(l);
			res.push_back(r);
			l--;
			r++;
		}
		while (l > 0) {
			res.push_back(l);
			l--;
		}
		while (r <= n) {
			res.push_back(r);
			r++;
		}
		arrprint(res);
	}
}
