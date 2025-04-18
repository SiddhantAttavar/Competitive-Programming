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
	vector<int> v(1e7, 0);
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);
		sort(a.begin(), a.end());

		vector<vector<int>> b(n);
		range(i, 0, n) {
			range(j, i + 1, n) {
				b[i].push_back(a[i] ^ a[j]);
				v[a[i] ^ a[j]]++;
			}
		}

		int res = 0;
		range(i, 0, n) {
			for (int j : b[i]) {
				v[j]--;
			}
			range(j, 0, i) {
				res += v[a[i] ^ a[j]];
			}
		}
		res *= 24;

		int x = 0;
		map<int, int> m;
		for (int i : a) {
			m[i]++;
		}
		for (pair<int, int> p : m) {
			x += (p.second * (p.second - 1)) / 2;
		}
		for (pair<int, int> p : m) {
			int y = (p.second * (p.second - 1)) / 2;
			res -= y * (x - y) * 8;
			res -= (y * (p.second - 2) * (p.second - 3)) * 2;
		}
		print(res);
	}
}
