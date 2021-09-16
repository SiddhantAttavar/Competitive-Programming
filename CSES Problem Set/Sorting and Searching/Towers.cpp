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
	multiset<int> m;
	while (n--) {
		int x; input(x);
		multiset<int>::iterator it = m.upper_bound(x);
		if (it != m.end()) {
			//Remove existing tower to add new tower
			m.erase(it);
		}
		m.insert(x);
	}
	print(m.size());
}