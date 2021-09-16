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

int n, t;
vector<int> k;

bool possible(ll x) {
	ll res = 0;
	for (int i : k) {
		res += x / i;
		if (res >= t) {
			return true;
		}
	}
	return false;
}

int main() {
	setup();
	
	input(n);
	input(t);

	k.resize(n);
	arrPut(k);

	ll low = 0, high = 1e18;
	ll ans = 1e18;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (possible(mid)) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	print(ans);
}