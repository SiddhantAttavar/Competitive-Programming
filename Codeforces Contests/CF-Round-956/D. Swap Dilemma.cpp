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

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		vector<int> p(a.begin(), a.end()), q(b.begin(), b.end());
		sort(p.begin(), p.end());
		sort(q.begin(), q.end());
		if (p != q) {
			print("NO");
			continue;
		}

		map<int, int> m;
		range(i, 0, n) {
			m[a[i]] = i;
		}

		bool flag = true;
		range(i, 0, n) {
			// print(i);
			// cout.flush();
			int j = m[b[i]];
			if (i == j) {
				continue;
			}

			if (j < n - 1) {
				// print(i, j);
				// cout.flush();
				swap(a[i], a[j]);
				m[a[j]] = j;
				m[a[i]] = i;
				swap(b[i + 1], b[j + 1]);
				continue;
			}

			if (i == n - 2) {
				flag = false;
				break;
			}

			if (i == n - 3) {
				if (m[b[i + 1]] == i + 1) {
					flag = false;
				}
				break;
			}

			swap(a[n - 2], a[n - 1]);
			m[a[n - 1]] = n - 1;
			m[a[n - 2]] = n - 2;
			swap(b[n - 2], b[n - 1]);
			i--;
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
