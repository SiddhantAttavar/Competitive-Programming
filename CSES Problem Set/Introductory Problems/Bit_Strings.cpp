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

int modPow(ll a, int b, int m) {
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = (res * a) % m;
		}
		b /= 2;
		a = (a * a) % m;
	}
	return res;
}

int main() {
	setup();
	
	int n; input(n);
	print(modPow(2, n, MOD));
}