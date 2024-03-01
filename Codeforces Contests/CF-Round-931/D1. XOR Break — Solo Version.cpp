#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> v;
		range(i, 0, 60) {
			if ((1ll << i) & n) {
				v.push_back(i);
			}
		}
		reverse(v.begin(), v.end());

		vector<int> res = {n};
		bool flag = true;
		range(i, 0, 60) {
			if ((1ll << i) & n) {
				v.pop_back();
			}

			if (((1ll << i) & n) == ((1ll << i) & m)) {
				continue;
			}

			if ((1ll << i) & n) {
				n ^= 1ll << i;
				assert(n < res.back() and (n ^ res.back()) < res.back());
				res.push_back(n);
				continue;
			}

			if (v.size() < 2) {
				flag = false;
				break;
			}

			int u = v.size() - 1;
			for (int j = v.size() - 1; j >= 0; j--) {
				if (((1ll << v[u]) & m) == 0) {
					u = j;
					break;
				}
			}

			n ^= 1ll << i;
			assert(v[u] > i);
			n ^= 1ll << v[u];
			v.erase(v.begin() + u);
			assert(n < res.back() and (n ^ res.back()) < res.back());
			res.push_back(n);
		}

		if (flag) {
			print(res.size() - 1);
			assert(res.back() == m);
			arrPrint(res);
		}
		else {
			print(-1);
		}
	}
}
