#include <bits/stdc++.h>
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

const int N = 2e5, H = 30;
int p[N][H];

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	range(i, 0, n) {
		input(p[i][0]);
		p[i][0]--;
	}
	
	range(j, 1, H) {
		range(i, 0, n) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}

	while (q--) {
		int u, k;
		input(u, k);

		u--;
		range(i, 0, H) {
			if (k & 1) {
				u = p[u][i];
			}

			k >>= 1;
		}

		print(u + 1);
	}
}
