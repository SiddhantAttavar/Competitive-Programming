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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, d, k;
		input(n, d, k);

		vector<int> p(n + 1, 0), q(n + 1, 0);
		range(i, 0, k) {
			int l, r;
			input(l, r);
			p[l]++;
			q[r]++;
		}
		
		int c = 0;
		range(i, 1, d + 1) {
			c += p[i];
		}

		vector<int> res(n - d + 1, 0);
		res[0] = c;
		range(i, d + 1, n + 1) {
			c += p[i] - q[i - d];
			res[i - d] = c;
		}

		print(max_element(res.begin(), res.end()) - res.begin() + 1, min_element(res.begin(), res.end()) - res.begin() + 1);
	}
}
