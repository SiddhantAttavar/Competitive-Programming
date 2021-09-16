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

	set<int> s;
	map<int, int> ind;
	int special = -1;
	range(i, 1, n + 1) {
		int a; input(a);
		s.insert(a);
		if (x % 2 == 0 && a == x / 2 && special == -1) {
			special = i;
		}
		else {
			ind[a] = i;
		}
	}

	if (x % 2 == 0 && special != -1 && ind.find(x / 2) != ind.end()) {
		print(special <<  " " << ind[x / 2]);
		return 0;
	}

	for (int i : s) {
		if ((x % 2 == 1 || (x % 2 == 0 && i != x / 2)) && s.find(x - i) != s.end()) {
			print(ind[i] << " " << ind[x - i]);
			return 0;
		}
	}

	print("IMPOSSIBLE");
}