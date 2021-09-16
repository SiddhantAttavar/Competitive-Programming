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
	int t[n]; arrPut(t);

	//K starts from the first book, but J starts from the last book
	//Conflict arises if time taken to read first n - 1 books is less
	//than time to read to read last book

	ll sum = 0;
	for (int i : t) {
		sum += i;
	}

	int max = *max_element(t, t + n);

	if (sum - max < max) {
		print(2 * max);
	}
	else {
		print(sum);
	}
}