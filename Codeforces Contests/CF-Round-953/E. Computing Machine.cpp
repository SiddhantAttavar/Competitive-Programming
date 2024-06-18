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

		string s, t;
		input(s, t);

		vector<bool> a(n, false), b(n, false);
		a[0] = s[0] == '1';
		b[0] = t[0] == '1';
		a[n - 1] = s[n - 1] == '1';
		b[n - 1] = t[n - 1] == '1';
		range(i, 1, n - 1) {
			b[i] = t[i] == '1' or (s[i - 1] == '0' and s[i + 1] == '0');
		}
		range(i, 1, n - 1) {
			a[i] = s[i] == '1' or (b[i - 1] and b[i + 1]);
		}

		vector<int> p(n + 1, 0);
		range(i, 0, n) {
			p[i + 1] = p[i] + a[i];
		}

		int q;
		input(q);
		while (q--) {
			int l, r;
			input(l, r);

			l--;
			r--;
			
			if (l == r) {
				print(s[l] == '1');
				continue;
			}

			if (l + 1 == r) {
				print((s[l] == '1') + (s[r] == '1'));
				continue;
			}

			if (l + 2 == r) {
				print((s[l] == '1') + (s[r] == '1') + (s[l + 1] == '1' or (t[l] == '1' and t[r] == '1')));
				continue;
			}

			int x = p[r - 1] - p[l + 2] + (s[l] == '1') + (s[r] == '1');
			x += (s[l + 1] == '1') or (t[l] == '1' and b[l + 2]);
			x += (s[r - 1] == '1') or (t[r] == '1' and b[r - 2]);
			print(x);
		}
	}
}
