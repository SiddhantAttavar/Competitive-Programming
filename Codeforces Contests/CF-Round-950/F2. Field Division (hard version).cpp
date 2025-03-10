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
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		vector<pair<int, int>> a(k);
		range(i, 0, k) {
			input(a[i].first, a[i].second);
		}
		a.push_back({n, m + 1});

		vector<int> b(k + 1);
		range(i, 0, k + 1) {
			b[i] = i;
		}
		sort(b.begin(), b.end(), [&](int x, int y) {
			if (a[x].second == a[y].second) {
				return a[x].first > a[y].first;
			}
			return a[x].second < a[y].second;
		});

		int res = 0;
		int x = 0;
		vector<bool> v(k + 1, false);
		for (int i : b) {
			if (a[i].first <= x) {
				continue;
			}

			res += (a[i].first - x) * (a[i].second - 1);
			x = a[i].first;
			v[i] = true;
		}
		v.pop_back();

		print(res);
		arrPrint(v);
	}
}
