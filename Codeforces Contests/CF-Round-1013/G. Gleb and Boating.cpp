#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
// #define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int s, k;
		input(s, k);

		if (s > k * k) {
			if (s % k == 0) {
				print(k);
			}
			else {
				print(k - 2);
			}
			continue;
		}

		vector<bool> v(s + 1, false);
		for (int i = 0; i <= s; i += k) {
			v[i] = true;
		}
		if (v[s]) {
			print(k);
			continue;
		}

		int res = 1;
		for (int i = k - 1; i > 0; i--) {
			vector<bool> w(s + 1, false);
			if (i % 2 == k % 2) {
				rep(j, i, s + 1) {
					w[j] = v[j - i] or w[j - i];
				}
			}
			else {
				for (int j = s - i; j >= 0; j--) {
					w[j] = v[j + i] or w[j + i];
				}
			}
			v = w;
			if (v[s]) {
				res = i;
				break;
			}
		}
		print(res);
	}
}
