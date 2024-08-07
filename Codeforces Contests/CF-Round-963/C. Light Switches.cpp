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

bool clock(int x, int y, int z, int k) {
	return (y - x + k) % k + (z - y + k) % k == (z - x + k) % k;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);

		int z = 2 * k;
		vector<int> b(z, 0);
		for (int i : a) {
			b[i % z]++;
		}

		int x = 0;
		range(i, 0, k) {
			x += b[i];
		}
		
		int res = -1;
		vector<bool> v(z, false);
		range(i, k, z) {
			x += b[i] - b[i - k];
			if (x == n) {
				v[i] = true;
			}
		}

		range(i, 0, k) {
			x += b[i] - b[i + k];
			if (x == n) {
				v[i] = true;
			}
		}

		if (accumulate(v.begin(), v.end(), 0ll) == 0) {
			print(-1);
			continue;
		}

		int y = *max_element(a.begin(), a.end());
		while (!v[y % z]) {
			y++;
		}
		print(y);
	}
}
