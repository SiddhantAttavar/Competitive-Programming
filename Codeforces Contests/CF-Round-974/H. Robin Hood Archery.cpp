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
const int MOD = (int) 1e9 + 7; //998244353

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
	int N = 1e6;
	vector<int> x(N + 1);
	range(i, 1, N + 1) {
		x[i] = rng();
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrPut(a);

		vector<int> p(n + 1, 0);
		range(i, 0, n) {
			p[i + 1] = p[i] ^ x[a[i]];
		}

		while (q--) {
			int l, r;
			input(l, r);
			l--;
			r--;

			if (p[r + 1] == p[l]) {
				print("YES");
			}
			else {
				print("NO");
			}
		}
	}
}
