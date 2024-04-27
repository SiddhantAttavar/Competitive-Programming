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
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);
		
		map<int, int> m;
		for (int i : a) {
			m[i]++;
		}

		vector<int> b;
		int y = 0;
		for (pair<int, int> p : m) {
			y += (k - 1) * (p.second / k);
			if (p.second % k) {
				b.push_back(p.second % k);
			}
			m[p.first] %= k;
		}

		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		vector<int> c;
		for (int x : b) {
			if (y >= k - x) {
				y += k - 1;
			}
			else {
				c.push_back(x);
			}
		}
		b = c;

		y = min(y, k - 1);
		for (int i : b) {
			y += i;
		}

		print(y);
	}
}
