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

int n;
vector<int> a;
ll total = 0;

ll solve(int i, ll curr) {
	if (i == n) {
		return abs(2 * curr - total);
	}
	if (curr >= total / 2) {
		return abs(2 * curr - total);
	}
	return min(
		solve(i + 1, curr),
		solve(i + 1, curr + a[i])
	);
}

int main() {
	setup();
	
	input(n);
	a = vector<int>(n);
	arrPut(a);
	for (int i : a) {
		total += i;
	}

	print(solve(0, 0));
}