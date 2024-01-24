#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int modPow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}

		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		int n = s.size();

		vector<int> pref(n + 1, 0);
		range(i, 0, n) {
			pref[i + 1] = pref[i] + (s[i] == 'a');
		}

		vector<int> suff(n + 2, 0);
		for (int i = n - 1; i >= 0; i--) {
			suff[i] = max(suff[i + 1], suff[i + 2] + (i < n - 1 and s[i] == 'a' and s[i + 1] == 'b'));
		}

		// vector<int> v(n + 1, -1);
		// range(i, 0, n + 1) {
		// 	v[pref[i]] = max(v[pref[i]], suff[i]);
		// }
		//
		// arrPrint(v);
		
		arrPrint(pref);
		arrPrint(suff);

		int res = 0;
		range(i, 0, n + 1) {
			res += (pref[i] + 1) * (suff[i] + 1) - 1;
		}

		print(res);
	}
}
