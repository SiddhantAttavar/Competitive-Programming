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
	
	ll n; input(n);
	ll total = n * (n + 1) / 2;

	if (total % 2 == 1) {
		print("NO");
		return 0;
	}

	print("YES");

	vector<int> a, b;
	total /= 2;
	for (int i = n; i > 0; i--) {
		if (total >= i) {
			a.push_back(i);
			total -= i;
		}
		else {
			b.push_back(i);
		}
	}

	print(a.size());
	arrPrint(a);
	print(b.size());
	arrPrint(b);
}