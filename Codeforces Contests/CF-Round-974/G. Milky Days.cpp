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
	int N = 2e6;
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		vector<pair<int, int>> v(n);
		range(i, 0, n) {
			input(v[i].first, v[i].second);
		}
		v.push_back({N, 0});

		int res = 0;
		deque<int> dq;
		int t = 1;
		range(i, 0, n) {
			dq.push_back(i);
			t = v[i].first;
			while (!dq.empty() and v[dq.front()].first + k < t) {
				dq.pop_front();
			}

			while (t < v[i + 1].first and !dq.empty()) {
				int c = min({v[dq.back()].first + k - t, v[dq.back()].second / m, v[i + 1].first - t});
				if (c == 0) {
					break;
				}
				res += c;
				t += c;
				v[dq.back()].second -= c * m;
				// print(t, i, c);

				if (t == v[i + 1].first) {
					break;
				}

				if (t >= v[dq.back()].first + k) {
					dq.clear();
					break;
				}

				int z = v[dq.back()].second;
				dq.pop_back();
				while (z < m and !dq.empty() and t < v[dq.back()].first + k) {
					// print(z, t, 'd');
					if (z + v[dq.back()].second >= m) {
						v[dq.back()].second -= m - z;
						z = m;
						break;
					}
					z += v[dq.back()].second;
					dq.pop_back();
				}
				res += z == m;
				t++;
				if (!dq.empty() and t >= v[dq.back()].first + k) {
					dq.clear();
					break;
				}
				while (!dq.empty() and v[dq.back()].second == 0) {
					dq.pop_back();
				}
			}
		}

		print(res);
	}
}
