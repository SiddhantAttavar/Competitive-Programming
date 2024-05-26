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

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		int y = *max_element(a.begin(), a.end());
		bool flag = true;
		for (int i : a) {
			if (y % i) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print(n);
			continue;
		}

		int o = y;
		map<int, int> m;
		for (int i = 2ll; i * i <= o; i++) {
			while (o % i == 0) {
				o /= i;
				m[i]++;
			}
		}
		if (o > 1) {
			m[o] = 1;
		}

		vector<int> v = {1};
		for (pair<int, int> p : m) {
			int z = 1;
			vector<int> l(v.begin(), v.end());
			range(i, 0ll, p.second) {
				z *= p.first;
				for (int j : v) {
					l.push_back(j * z);
				}
			}
			v.insert(v.end(), l.begin(), l.end());
		}

		int res = 0;
		set<int> t(a.begin(), a.end());
		for (int i : v) {
			if (t.count(i)) {
				continue;
			}

			int c = 0, k = 1;
			for (int j : a) {
				if (i % j) {
					continue;
				}

				c++;
				k = (k * j) / gcd(k, j);
			}
			if (k == i) {
				res = max(res, c);
			}
		}
		print(res);
	}
}
