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
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrPut(a);


		int z = accumulate(a.begin(), a.end(), 0ll);
		set<int> s;
		range(i, 0, n) {
			if (a[i] == 1) {
				s.insert(i);
			}
		}

		while (q--) {
			int o;
			input(o);

			if (o == 1) {
				int x;
				input(x);
				
				if (x % 2 == z % 2) {
					if (x <= z) {
						print("YES");
					}
					else {
						print("NO");
					}
					continue;
				}

				if (s.empty()) {
					print("NO");
					continue;
				}

				int k = z - 1 - 2 * min(*s.begin(), n - 1 - *s.rbegin());
				if (x <= k) {
					print("YES");
				}
				else {
					print("NO");
				}
			}
			else {
				int i, x;
				input(i, x);
				i--;

				if (a[i] == 1) {
					s.erase(i);
				}

				z -= a[i];
				a[i] = x;
				z += a[i];

				if (a[i] == 1) {
					s.insert(i);
				}
			}
		}
	}
}
