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
	int N = 2e5;
	vector<int> spf(N + 1, 0);
	range(i, 1, N + 1) {
		spf[i] = i;
	}
	range(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}

		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		map<int, int> m;
		int o = n;
		while (o != 1) {
			m[spf[o]]++;
			o /= spf[o];
		}

		vector<int> l = {1};
		for (pair<int, int> p : m) {
			vector<int> nl(l.begin(), l.end());
			int x = 1;
			range(i, 0, p.second) {
				x *= p.first;
				for (int j : l) {
					nl.push_back(x * j);
				}
			}
			l = nl;
		}
		l.pop_back();

		int res = n;
		for (int i : l) {
			if (res < i) {
				continue;
			}

			int l = i;
			while (l < n and s[l] == s[i + l % i]) {
				l++;
			}

			int x = 0;
			range(j, 0, i) {
				x += s[j] != s[j + i];
			}

			if (l == n and x <= 1) {
				res = i;
				continue;
			}

			l = 0;
			while (l < n and s[l] == s[l % i]) {
				l++;
			}
			int r = n - 1;
			while (r >= 0 and s[r] == s[r % i]) {
				r--;
			}
			if (l >= r) {
				res = i;
			}

		}

		print(res);
	}
}
