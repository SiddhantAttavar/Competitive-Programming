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
	setup();

	int n, k;
	input(n, k);

	string s;
	input(s);

	sort(s.begin(), s.end());
	int res = 0;
	do {
		res++;
		range(i, 0, n - k + 1) {
			bool flag = true;
			range(j, 0, k / 2) {
				if (s[i + j] != s[i + k - 1 - j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				res--;
				break;
			}
		}
	} while (next_permutation(s.begin(), s.end()));
	print(res);
}
