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

		string s;
		input(s);

		if (n == 1) {
			print(1);
			continue;
		}

		vector<pair<int, bool>> v(n);
		range(i, 0, n) {
			v[i] = {a[i], s[i] == '1'};
		}
		sort(v.begin(), v.end());

		multiset<int> x, y, z;
		vector<int> b;
		for (pair<int, bool> p : v) {
			if (p.second) {
				b.push_back(p.first);
			}
			else {
				x.insert(p.first);
			}
		}

		if (b.empty() or b.back() <= *x.begin()) {
			print(n);
			continue;
		}

		int res = 0;
		for (int i : b) {
			int c = 0, d = 0;
			multiset<int>::iterator j = y.lower_bound(i);
			if (j != y.end()) {
				c++;
				z.insert(*j);
				y.erase(j);
			}

			j = y.lower_bound(i);
			if (j != y.end()) {
				c++;
				z.insert(*j);
				y.erase(j);
			}

			j = x.lower_bound(i);
			if (c < 2 and j != x.end()) {
				c++;
				d++;
				y.insert(*j);
				x.erase(j);
			}

			j = x.lower_bound(i);
			if (c < 2 and j != x.end()) {
				c++;
				d++;
				y.insert(*j);
				x.erase(j);
			}

			if (c != 2) {
				break;
			}

			res += d + 1;
		}

		if (!x.empty() or y.size() >= 2) {
			res += z.size();
		}

		print(res);
	}
}
