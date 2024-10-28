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
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);

		sort(a.begin(), a.end());

		vector<int> v;
		for (int i : a) {
			if (i > k) {
				v.push_back(i - k);
			}
		}

		if (v.size() <= 1) {
			print(accumulate(a.begin(), a.end(), 0ll));
			continue;
		}

		v.pop_back();

		while (v.size() > 1 and v[v.size() - 2]) {
			int i = lower_bound(v.begin(), v.end(), v.back()) - v.begin();

			if (i == v.size() - 1) {
				v[v.size() - 1]--;
				v[v.size() - 2]--;
			}
			else {
				v[i]--;
				v[i + 1]--;
			}
		}

		int res = 0;
		for (int i : a) {
			res += min(i, k);
		}
		print(res + a[n - 1] - v.back() - k);
	}
}
