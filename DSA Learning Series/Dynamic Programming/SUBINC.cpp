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
		ll res = 0;
		int curr = 0;
		int prev = 0;
		range(i, 0, n) {
			int x; input(x);
			if (prev <= x) {
				curr++;
			}
			else {
				curr = 1;
			}
			res += curr;
			prev = x;
		}
		print(res);
	}
}