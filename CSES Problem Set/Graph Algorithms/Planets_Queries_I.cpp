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
	
	int n, q;
	input(n);
	input(q);

	int s = ceil(log2(1e9));
	int parent[n][s];
	range(i, 0, n) {
		input(parent[i][0]);
		parent[i][0]--;
	}

	range(i, 1, s) {
		range(j, 0, n) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}

	while (q--) {
		int x, k;
		input(x);
		input(k);

		x--;
		int i = 0;
		while (k > 0) {
			if (k % 2 == 1) {
				x = parent[x][i];
			}
			i++;
			k /= 2;
		}

		print(x + 1);
	}
}