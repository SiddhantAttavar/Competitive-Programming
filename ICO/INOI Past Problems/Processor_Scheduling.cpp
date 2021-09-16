#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

const long long INF = 1e15;

int main() {
	setup();
	input(long long, tc); while (tc--) {
		input(long long, n);
		input(long long, m);
		long long a[n + 1];
		range(i, 1, n + 1) {
			cin >> a[i];
		}
		pair<long long, long long> b[m + 1];
		range(i, 1, m + 1) {
			cin >> b[i].second;
		}
		range(i, 1, m + 1) {
			cin >> b[i].first;
		}
		sort(b + 1, b + m + 1);

		long long dp[n + 1][m + 1];

		dp[0][0] = 0;
		range(i, 1, n + 1) {
			dp[i][0] = dp[i - 1][0] + a[i];
		}
		range(j, 1, m + 1) {
			if (dp[0][j - 1] <= b[j].first) {
				dp[0][j] = max(b[j].first, dp[0][j - 1] + b[j].second);
			}
			else {
				dp[0][j] = INF;
			}
		}
		range(i, 1, n + 1) {
			range(j, 1, m + 1) {				
				if (dp[i][j - 1] <= b[j].first) {
					dp[i][j] = min(dp[i - 1][j] + a[i], max(b[j].first, dp[i][j - 1] + b[j].second));
				}
				else {
					dp[i][j] = dp[i - 1][j] + a[i];
				}
			}
		}

		if (dp[n][m] >= INF) {
			print(-1);
		}
		else {
			print(dp[n][m]);
		}
	}
}