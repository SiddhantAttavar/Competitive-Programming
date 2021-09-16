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
	int a[n]; arrPut(a);
	int ind[n];
	range(i, 0, n) {
		ind[a[i] - 1] = i;
	}

	int rounds = 1;
	range(i, 1, n) {
		if (ind[i] < ind[i - 1]) {
			rounds++;
		}
	}

	print(rounds);
}