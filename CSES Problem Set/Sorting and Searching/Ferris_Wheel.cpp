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
	
	int n, x;
	input(n);
	input(x);

	int p[n]; arrPut(p);
	sort(p, p + n);

	int res = 0;
	int l = 0, r = n - 1;
	while (l < r) {
		if (p[l] + p[r] <= x) {
			res++;
			l++;
		}
		else {
			res++;
		}
		r--;
	}

	if (l == r) {
		print(res + 1);
	}
	else {
		print(res);
	}
}