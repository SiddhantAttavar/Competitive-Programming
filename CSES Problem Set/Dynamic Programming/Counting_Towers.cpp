#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n; input(n);
		
		ll f[n] = {1};
		ll g[n] = {1};

		range(i, 1, n) {
			f[i] = (2 * f[i - 1] + g[i - 1]) % MOD;
			g[i] = (4 * g[i - 1] + f[i - 1]) % MOD;
		}

		print((f[n - 1] + g[n - 1]) % MOD);
	}
}