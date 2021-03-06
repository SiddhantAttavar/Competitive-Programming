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
		ll n; input(n);
		ll a[n]; arrPut(a);

		ll res = n * (n + 1) / 2;
		ll curr = 1;
		range(i, 1, n) {
			if (a[i] != a[i - 1]) {
				res -= curr * (curr + 1) / 2;
				curr = 0;
			}
			curr++;
		}
		res -= curr * (curr + 1) / 2;

		print(res);
	}
}