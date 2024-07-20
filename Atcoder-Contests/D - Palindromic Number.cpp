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

	int n;
	input(n);

	n--;
	string res;
	int x = 9, y = 1;
	while (n >= 0) {
		if (n <= x) {
			y += n - 1;
			string t = to_string(y);
			res = t;
			t.pop_back();
			reverse(t.begin(), t.end());
			res += t;
			break;
		}
		n -= x;

		if (n <= x) {
			y += n - 1;
			string t = to_string(y);
			res = t;
			reverse(t.begin(), t.end());
			res += t;
			break;
		}
		n -= x;

		x *= 10;
		y *= 10;
	}

	print(res);
}
