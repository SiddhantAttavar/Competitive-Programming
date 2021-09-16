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
	
	int n; input(n);

	if (n == 1) {
		print(1);
		return 0;
	}
	if (n < 4) {
		print("NO SOLUTION");
		return 0;
	}
	if (n == 4) {
		print("2 4 1 3");
	}
	if (n == 5) {
		print("1 4 2 5 3");
		return 0;
	}

	if (n % 2 == 1) {
		cout << n << " ";
	}
	range(i, 1, n / 2 + 1) {
		cout << i << " " << n / 2 + i << " ";
	}
}