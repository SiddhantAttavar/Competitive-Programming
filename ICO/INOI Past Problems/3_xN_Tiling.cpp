#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

const int MOD = 1e9 + 7;
const int maxN = 1e6;
int dp2[maxN + 1] = {1, 0, 1};
int dp3A[maxN + 1] = {1, 1, 1};
int dp3B[maxN + 1], dp3C[maxN + 1];

int main() {
	setup();

	range(i, 3, maxN + 1) {
		dp2[i] = (dp2[i - 2] + dp2[i - 3]) % MOD;
	}

	range(i, 3, maxN + 1) {
		dp3A[i] = ((dp3A[i - 1] + dp3A[i - 3]) % MOD + (2 * dp3B[i - 2]) % MOD) % MOD;
		dp3B[i] = (dp3B[i - 3] + dp3C[i - 1]) % MOD;
		dp3C[i] = (dp3C[i - 3] + dp3A[i - 3]) % MOD;
	}

	input(int, tc); while (tc--) {
		input(int, k);
		input(int, n);

		if (k == 1) {
			print(n % 3 == 0);
		}
		else if (k == 2) {
			print(dp2[n]);
		}
		else {
			print(dp3A[n]);
		}
	}
}
