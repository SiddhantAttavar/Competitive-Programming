#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, l;
pair<int, int> a[3000];

bool isPossible(int d) {
	int dp[n];
	fill(dp, dp + n, 1);

	range(i, 0, n) {
		range(j, 0, i) {
			if (abs(a[i].second - a[j].second) >= d) {
				dp[i] = max(dp[i], dp[j] + 1);
				if (dp[i] == l) {
					return true;
				}
			}
		}
	}

	return false;
}
	
int main() {
	setup();
	input(int, tc); while (tc--) {
		//Input
		cin >> n >> l;
		range(i, 0, n) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a, a + n);

		int low = 0;
		int high = n - 1;
		range(i, 0, n) {
			range(j, i + 1, n) {
				if (a[j].first > a[i].first) {
					break;
				}
				low = max(low, abs(a[j].second - a[i].second));
			}
		}

		while (low < high) {
			int mid = (low + high + 1) / 2;
			if (isPossible(mid)) {
				low = mid;
			}
			else {
				high = mid - 1;
			}
		}

		print(low);
	}
}