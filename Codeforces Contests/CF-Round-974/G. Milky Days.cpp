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
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		vector<pair<int, int>> a(n);
		range(i, 0, n) {
			input(a[i].first, a[i].second);
		}
		sort(a.begin(), a.end());
		a.push_back({1e9, 0});

		int res = 0;
		stack<int> s;
		range(i, 0, n) {
			s.push(i);
			int c = 0, t = a[i].first;
			while (!s.empty() and t < a[i + 1].first) {
				int j = s.top();
				if (a[j].first + k <= t) {
					s.pop();
					continue;
				}

				if (c + a[j].second < m) {
					c += a[j].second;
					a[j].second = 0;
					s.pop();
					continue;
				}

				if (c) {
					a[j].second -= m - c;
					c = 0;
					t++;
					res++;
					if (a[j].second == 0) {
						s.pop();
					}
					continue;
				}

				int x = min({a[j].second / m, a[i + 1].first - t, a[j].first + k - t});
				a[j].second -= x * m;
				res += x;
				t += x;
			}
		}
		print(res);
	}
}
