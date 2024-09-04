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
		int n, k, q;
		input(n, k, q);

		vector<int> a(n);
		arrPut(a);

		range(i, 0, n) {
			a[i] -= i;
		}

		map<int, int> m;
		range(i, 0, k) {
			m[a[i]]++;
		}
		multiset<int> s;
		for (pair<int, int> p : m) {
			s.insert(p.second);
		}

		vector<int> res(n);
		res[k - 1] = k - *s.rbegin();
		range(i, k, n) {
			s.erase(s.find(m[a[i - k]]));
			m[a[i - k]]--;
			s.insert(m[a[i - k]]);

			if (s.count(m[a[i]])) {
				s.erase(s.find(m[a[i]]));
			}
			m[a[i]]++;
			s.insert(m[a[i]]);

			res[i] = k - *s.rbegin();
		}

		while (q--) {
			int l, r;
			input(l, r);

			l--;
			r--;

			print(res[r - 1]);
		}
	}
}
