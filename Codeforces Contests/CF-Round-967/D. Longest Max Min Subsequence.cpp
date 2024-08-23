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
		
		map<int, int> m;
		for (int i : a) {
			m[i]++;
		}

		vector<bool> v(n + 1, false);
		vector<int> res;
		multiset<int> s;
		int j = -1;
		range(i, 0, n) {
			m[a[i]]--;
			if (v[a[i]]) {
				continue;
			}

			s.insert(a[i]);

			if (m[a[i]]) {
				continue;
			}

			while (!res.size() or res.back() != a[i]) {
				if (res.size() % 2 == 0) {
					v[*s.rbegin()] = true;
					res.push_back(*s.rbegin());
				}
				else {
					v[*s.begin()] = true;
					res.push_back(*s.begin());
				}

				while (j == -1 or a[j] != res.back()) {
					j++;
					if (s.count(a[j])) {
						s.erase(s.find(a[j]));
					}
				}

				if (s.count(res.back())) {
					s.erase(res.back());
				}
			}
		}

		while (s.size()) {
			if (res.size() % 2 == 0) {
				v[*s.rbegin()] = true;
				res.push_back(*s.rbegin());
			}
			else {
				v[*s.begin()] = true;
				res.push_back(*s.begin());
			}
		}

		print(res.size());
		arrPrint(res);
		cout.flush();
	}
}
