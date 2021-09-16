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

	int a[n]; arrPut(a);

	ll sum = 0;
	ll res = 0;
	map<ll, int> freq;
	freq[0] = 1;

	for (int x : a) {
		sum += x;
		res += freq[sum - x];
		freq[x]++;
	}

	print(res);
}