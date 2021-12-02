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
#define int long long

struct DSU {
	vector<int> p, a, b;

	DSU(int n) {
		p.resize(n);
		a.resize(n, -1);
		b.resize(n, 0);
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}

	int find(int u, int x) {
		if (a[x] == 1) {
			a[u] *= -1;
		}

		if (p[x] == x) {
			return x;
		}

		return p[x] = find(u, p[x]);
	}


}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		
	}
}
