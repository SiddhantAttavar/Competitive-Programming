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

	ll deadlineSum = 0;
	int a[n];
	range(i, 0, n) {
		input(a[i]);
		int x; input(x);
		deadlineSum += x;
	}
	sort(a, a + n);

	ll curr = 0;
	ll finishSum = 0;
	for (int i : a) {
		curr += i;
		finishSum += curr;
	}

	print(deadlineSum - finishSum);
}