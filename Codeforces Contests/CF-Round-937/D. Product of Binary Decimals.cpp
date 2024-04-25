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
	vector<int> a;
	range(i, 1, 1 << 5) {
		int c = 0, x = 1;
		range(j, 0, 5) {
			if ((1 << j) & i) {
				c += x;
			}
			x *= 10;
		}
		a.push_back(c);
	}
	a.push_back(1e5);

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		queue<int> q;
		set<int> vis;
		vis.insert(n);
		q.push(n);
		bool flag = false;
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			if (x == 1) {
				flag = true;
				break;
			}

			for (int i : a) {
				cout.flush();
				if (x >= i and x % i == 0 and !vis.count(x / i)) {
					vis.insert(x / i);
					q.push(x / i);
				}
			}
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
