#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

bool verify(string s, vector<pair<int, int>> &res) {
	vector<char> x(s.begin(), s.end());
	sort(x.begin(), x.end());
	for (pair<int, int> p : res) {
		s = (s.substr((int) s.size() - p.second, p.second) + 
			 s.substr(p.first, (int) s.size() - p.first - p.second) + 
			 s.substr(0, p.first));
	}
	range(i, 0, (int) s.size()) {
		if (s[i] != x[i]) {
			string t(x.begin(), x.end());
			print(s, t);
			cout.flush();
			return false;
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		string s;
		input(s);

		/* if (n == 2) {
			if (s[0] < s[1]) {
				print(0);
			}
			else {
				print(1);
				print(1, 1);
			}
			continue;
		} */

		vector<pair<int, int>> a(n);
		range(i, 0, n) {
			a[i] = {s[i] - 'a', i};
		}
		sort(a.begin(), a.end());
		
		vector<pair<int, int>> res;
		ordered_set p;
		for (int i = n - 1; i >= 0; i--) {
			if (p.find(a[i].second) != p.end()) {
				continue;
			}

			int j = i;
			int z = 1;
			while (j - 1 >= 0 and a[j - 1].second == a[j].second - 1) {
				j--;
				z++;
			}
			int x = a[j].second + (p.size() - p.order_of_key(a[j].second));
			int y = n - x - z;
			// print(n, x, z, y, j);
			range(l, j, i + 1) {
				p.insert(a[l].second);
			}

			if (!x) {
				continue;
			}

			if (y) {
				res.push_back({x + z, y});
				res.push_back({y, z});
			}
			else {
				res.push_back({x, z});
			}
		}

		assert(verify(s, res));

		print(res.size());
		for (pair<int, int> l : res) {
			print(l.first, l.second);
		}
	}
}
