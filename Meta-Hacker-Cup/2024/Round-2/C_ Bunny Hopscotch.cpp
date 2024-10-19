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
	setup(); int tc; input(tc); range(t, 0, tc) {
		int n, m, k;
		input(n, m, k);

		vector<vector<int>> a(n, vector<int>(m));
		range(i, 0, n) {
			arrPut(a[i]);
		}

		vector<map<int, vector<int>>> p(n), q(m);
		range(i, 0, n) {
			range(j, 0, m) {
				p[i][a[i][j]].push_back(j);
			}
		}
		range(j, 0, m) {
			range(i, 0, n) {
				q[j][a[i][j]].push_back(i);
			}
		}

		range(x, 1, 801) {
			int c = 0;
			range(i, 0, n) {
				range(j, 0, m) {

					if (j >= x) {
						c += min(n - 1, (int) i + x) - max(i - x, 0) + 1;
						if (q[j - x].count(a[i][j])) {
							vector<int> v = q[j - x][a[i][j]];
							c -= upper_bound(v.begin(), v.end(), i + x) - lower_bound(v.begin(), v.end(), i - x);
						}
					}

					if (j + x < m) {
						c += min(n - 1, (int) i + x) - max(i - x, 0) + 1;
						if (q[j + x].count(a[i][j])) {
							vector<int> v = q[j + x][a[i][j]];
							c -= upper_bound(v.begin(), v.end(), i + x) - lower_bound(v.begin(), v.end(), i - x);
						}
					}

					if (i >= x) {
						c += min(m - 1, (int) j + x - 1) - max(j - x + 1, 0) + 1;
						if (p[i - x].count(a[i][j])) {
							vector<int> v = p[i - x][a[i][j]];
							c -= lower_bound(v.begin(), v.end(), j + x) - upper_bound(v.begin(), v.end(), j - x);
						}
					}

					if (i + x < n) {
						c += min(m - 1, (int) j + x - 1) - max(j - x + 1, 0) + 1;
						if (p[i + x].count(a[i][j])) {
							vector<int> v = p[i + x][a[i][j]];
							c -= lower_bound(v.begin(), v.end(), j + x) - upper_bound(v.begin(), v.end(), j - x);
						}
					}
				}
			}

			if (c >= k) {
				cout << "Case #" << t + 1 << ": " << x << endl;
				cout.flush();
				break;
			}
			k -= c;
		}
	}
}
