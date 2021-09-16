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
	map<int, vector<int>> m;
	range(i, 0, n) {
		m[a[i]].push_back(i);
	}

	range(i, 0, n) {
		range(j, 0, i) {
			int left = x - a[i] - a[j];
			if (m.find(left) != m.end()) {
				int k = -1;
				for (int l : m[left]) {
					if (l != i && l != j) {
						k = l;
						break;
					}
				}
				if (k != -1) {
					print(i + 1 << " " << j + 1 << " " << k + 1);
					return 0;
				}
			}
		}
	}

	print("IMPOSSIBLE");
}