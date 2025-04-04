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

void sort3(int &a, int &b, int &c) {
	if (a > b) {
		swap(a, b);
	}
	if (b > c) {
		swap(b, c);
	}
	if (a > b) {
		swap(a, b);
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int a, b, c;
		input(a, b, c);

		if ((a + b + c) % 2 == 1) {
			print(-1);
			continue;
		}

		int res = 0;
		sort3(a, b, c);
		while (b > 0) {
			c--;
			b--;
			sort3(a, b, c);
			res++;
		}
		print(res);
	}
}
