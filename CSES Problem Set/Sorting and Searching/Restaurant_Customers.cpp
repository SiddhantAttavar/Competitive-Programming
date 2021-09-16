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
	vector<pair<int, bool>> v;
	range(i, 0, n) {
		int a, b;
		input(a);
		input(b);
		v.push_back({a, true});
		v.push_back({b, false});
	}

	sort(v.begin(), v.end());

	int curr = 0;
	int res = 0;
	
	for (pair<int, bool> p : v) {
		if (p.second) {
			curr++;
			res = max(res, curr);
		}
		else {
			curr--;
		}
	}

	print(res);
}