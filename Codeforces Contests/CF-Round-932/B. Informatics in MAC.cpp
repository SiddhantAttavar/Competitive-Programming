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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		set<int> s(a.begin(), a.end());
		int x = 0;
		while (s.count(x)) {
			x++;
		}

		map<int, int> m;
		for (int i : a) {
			m[i]++;
		}

		set<int> t;
		bool flag = true;
		int res = -1;
		range(i, 0, n) {
			if (a[i] >= x) {
				continue;
			}

			m[a[i]]--;
			t.insert(a[i]);
			if (t.size() == x) {
				range(j, 0, x) {
					if (m[j] == 0) {
						flag = false;
						break;
					}
				}
				res = i;
				break;
			}
		}

		if (!flag) {
			print(-1);
			continue;
		}

		if (res == -1) {
			print(n);
			range(i, 0, n) {
				print(i + 1, i + 1);
			}
			continue;
		}

		print(2);
		print(1, res + 1);
		print(res + 2, n);
	}
}
