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

const int MAX = 1e6;

int numDivisors[MAX + 1];
int prefSum[MAX + 1][6];

int main() {
	setup();

	range(i, 2, MAX / 2 + 1) {
		if (numDivisors[i] == 0) {
			for (int j = i; j <= MAX; j += i) {
				numDivisors[j]++;
			}
		}
	}

	range(i, 2, MAX + 1) {
		range(j, 1, 6) {
			prefSum[i][j] = prefSum[i - 1][j];
		}
		if (numDivisors[i] <= 5) {
			prefSum[i][numDivisors[i]]++;
		}
	}

	int tc; input(tc); while (tc--) {
		int a, b, k;
		input(a);
		input(b);
		input(k);

		print(prefSum[b][k] - prefSum[a - 1][k]);
	}
}