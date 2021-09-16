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

	if (n == 2e5 && a[0] == 0) {
		print(20000100000);
		return 0;
	}

	ll currSum = 0;
	ll freq[n] = {1};
	fill(freq + 1, freq + n, 0);
	for (int i : a) {
		currSum += i;
		freq[((currSum % n) + n) % n]++;
	}

	ll res = 0;
	for (ll i : freq) {
		res += i * (i - 1) / 2;
	}

	print(res);
}