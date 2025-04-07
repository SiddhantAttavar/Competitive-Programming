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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (n == 4) {
			print("2025");
			continue;
		}
		if (n == 5) {
			print("42025");
			continue;
		}
		if (n == 6) {
			print("632025");
			continue;
		}

		string res;
		if (n % 2 == 0) {
			int k = (n - 1) / 2;
			res = "16";
			res += string(k - 3, '0');
			res += "36";
			res += string(k - 3, '0');
			res += "2025";
			print(res);
		}
		else {
			int k = n / 2;
			res = '1';
			res += string(k - 2, '0');
			res += '9';
			res += string(k - 3, '0');
			res += "2025";
			print(res);
		}
	}
}
