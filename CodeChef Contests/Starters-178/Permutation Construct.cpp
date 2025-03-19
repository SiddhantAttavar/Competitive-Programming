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
		int n, k;
		input(n, k);

		if (k * 2 > n) {
			print(-1);
			continue;
		}

		vector<vector<int>> a(k);
		rep(i, 0, n) {
			a[(i + 1) % k].push_back(i + 1);
		}
		rep(i, 0, k) {
			a[i].insert(a[i].begin(), a[i].back());
			a[i].pop_back();
			reverse(a[i].begin(), a[i].end());
		}
		vector<int> p(n);
		rep(i, 0, n) {
			p[i] = a[(i + 1) % k].back();
			a[(i + 1) % k].pop_back();;
		}
		arrprint(p);
		cout.flush();
		rep(i, 0, n) {
			assert(p[i] != i + 1);;
			assert(p[i] % k == (i + 1) % k);
		}
		set<int> s(p.begin(), p.end());
		assert(s.size() == n);
	}
}
