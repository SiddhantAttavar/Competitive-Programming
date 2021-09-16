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
	
	ll n; input(n);
	
	print(0);
	if (n == 1) {
		return 0;
	}
	print(6);
	for (ll i = 3; i <= n; i++) {
		print((i * i * (i * i - 1) / 2) - (4 * (i - 1) * (i - 2)));
	}
}