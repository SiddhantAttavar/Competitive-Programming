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

	int h = ceil(log2(n));
	
	ll sum[n][h + 1];
	range(i, 0, n) {
		input(sum[i][0]);
	}

	for (int i = n - 1; i >= 0; i--) {
		int curr = 1;
		range(j, 1, h + 1) {
			if (i + curr >= n) {
				break;
			}
			sum[i][j] = sum[i][j - 1] + sum[i + curr][j - 1];
			curr *= 2;
		}
	}

	int res = 0;
	int temp = pow(2, h);
	range(i, 0, n) {
		ll s = 0;
		int curr = temp;
		int j = i;
		for (int k = h; k >= 0; k--) {
			if (j + curr <= n && s + sum[j][k] <= x) {
				s += sum[j][k];
				j += curr;
			}
			curr /= 2;
		}

		if (s == x) {
			res++;
		}
	}

	print(res);
}