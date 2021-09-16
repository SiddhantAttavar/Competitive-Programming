#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int n; input(n);
	int curr; input(curr);
	long long res = 0;
	range(i, 0, n - 1) {
		int x; input(x);
		res += max(0, curr - x);
		curr = max(curr, x);
	}
	print(res);
}