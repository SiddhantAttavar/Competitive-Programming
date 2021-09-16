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

int legenders(int n, int p) {
	int res = 0;
	int k = p;
	while (true) {
		int x = n / k;
		if (x == 0) {
			break;
		}
		res += x;
		k *= p;
	}
	return res;
}

int main() {
	setup();
	
	int n; input(n);
	print(min(legenders(n, 2), legenders(n, 5)));
}