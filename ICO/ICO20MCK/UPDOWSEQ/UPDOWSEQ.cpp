#include <bits/stdc++.h>
#define range(var, start, end) for (int var = start; var < end; var++)
#define input(var) cin >> var
#define arrPut(arr) for (auto &var : arr) {cin >> var;}
#define print(msg) cout << msg << '\n'
#define arrPrint(arr) for (auto var : arr) {cout << var << " ";} cout << '\n';
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	int tc; input(tc); while (tc--) {
		int n; input(n);
		int a[n]; arrPut(a);

		int up[n + 1], down[n + 1];
		fill(up, up + n, 1);
		fill(down, down + n, 1);
		up[n] = down[n] = 0;

		for (int i = n - 2; i >= 0; i--) {
			if (a[i] <= a[i + 1]) {
				down[i] = up[i + 1] + 1;
			}

			if (a[i] >= a[i + 1]) {
				up[i] = down[i + 1] + 1;
			}
		}

		int res = *max_element(up, up + n);
		range(i, 0, n) {
			int j = i + down[i];
			if (down[i] % 2 == 0) {
				res = max(res, down[i] + up[j] + 1);
			}
			else {
				res = max(res, down[i] + down[j] + 1);
			}
		}

		print(res);
	}
}