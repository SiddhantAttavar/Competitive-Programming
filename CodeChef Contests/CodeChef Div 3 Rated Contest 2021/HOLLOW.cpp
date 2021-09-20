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

vector<vector<ll>> prefSum;
int n, m, k;

bool possible(int l) {
	bool flag = true;
	range(i, 1, n - l + 2) {
		range(j, 1, m - l + 2) {
			int x = i + l - 1, y = j + l - 1;
			ll sum = prefSum[x][y] - prefSum[i - 1][y] - prefSum[x][j - 1] + prefSum[i - 1][j - 1];
			if (sum <= k && ((n * m - prefSum[n][m]) - (l * l - sum)) >= sum) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		input(n);
		input(m);
		input(k);

		prefSum = vector<vector<ll>>(n + 1, vector<ll>(m + 1, 0));
		range(i, 1, n + 1) {
			string s; input(s);
			range(j, 1, m + 1) {
				prefSum[i][j] = prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1];
				prefSum[i][j] += s[j - 1] == '1';
			}
		}

		int res = 0;
		int low = 0, high = n;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (possible(mid)) {
				res = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}

		print(res);
		prefSum.clear();
	}
}