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
	
	int n, m;
	input(n);
	input(m);

	multiset<int> h;
	while (n--) {
		int x; input(x);
		h.insert(x);
	}

	while (m--) {
		int x; input(x);
		auto i = h.upper_bound(x);
		if (i == h.begin()) {
			print(-1);
		}
		else {
			print(*(--i));
			h.erase(i);
		}
	}
}