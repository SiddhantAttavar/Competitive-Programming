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
	list<int> l;
	range(i, 1, n + 1) {
		l.push_back(i);
	}

	if (n == 1) {
		print(1);
		return 0;
	}

	list<int>::iterator prev = l.begin();
	list<int>::iterator it = next(l.begin(), 1);
	range(i, 0, n) {
		cout << *it << " ";
		l.erase(it);
		if (l.size() != 0) {
			prev++;
			if (prev == l.end()) {
				prev = l.begin();
			}
			list<int>::iterator temp = prev;
			it = next(temp, 1);
			if (it == l.end()) {
				it = l.begin();
			}
		}
	}
}