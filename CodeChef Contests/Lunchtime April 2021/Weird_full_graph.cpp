<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

int main() {
	setup(); int tc; input(tc); while (tc--) {
		int n; input(n);
		int a[n]; arrPut(a);
		ll cost[n][n];
		range(i, 0, n) {
			range(j, 0, n) {
				cost[i][j] = a[i];
			}
		}
		int m; input(m);
		range(i, 0, m) {
			int u, v, c; input(u, v, c);
			cost[u - 1][v - 1] = c;
		}
		range(k, 0, n) {
			range(i, 0, n) {
				range(j, 0, n) {
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}
		ll res = 0;
		range(i, 0, n) {
			range(j, 0, n) {
				res += cost[i][j] * (i != j);
			}
		}
		print(res);
	}
=======
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

int main() {
	setup(); int tc; input(tc); while (tc--) {
		int n; input(n);
		int a[n]; arrPut(a);
		ll cost[n][n];
		range(i, 0, n) {
			range(j, 0, n) {
				cost[i][j] = a[i];
			}
		}
		int m; input(m);
		range(i, 0, m) {
			int u, v, c; input(u, v, c);
			cost[u - 1][v - 1] = c;
		}
		range(k, 0, n) {
			range(i, 0, n) {
				range(j, 0, n) {
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}
		ll res = 0;
		range(i, 0, n) {
			range(j, 0, n) {
				res += cost[i][j] * (i != j);
			}
		}
		print(res);
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}