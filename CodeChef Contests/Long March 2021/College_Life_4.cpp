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
#define int ll

signed main() {
	setup();
	int tc; input(tc); while (tc--) {
		ll n, e, h, a, b, c;
		cin >> n >> e >> h >> a >> b >> c;

		ll res = LONG_LONG_MAX;
		range(r, 0, min({n, e, h}) + 1) {
			int curr = r;
			ll cost = r * c;
			if (a < b) {
				int p = min(n - curr, (e - r) / 2);
				curr += p;
				cost += p * a;

				int q = min(n - curr, (h - r) / 3);
				curr += q;
				cost += q * b;
			}
			else {
				int q = min(n - curr, (h - r) / 3);
				curr += q;
				cost += q * b;

				int p = min(n - curr, (e - r) / 2);
				curr += p;
				cost += p * a;
			}

			if (curr == n) {
				res = min(res, cost);
			}
		}

		print((res == LONG_LONG_MAX ? -1 : res));
	}
}