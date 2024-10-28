#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--) {
		int n;
		cin >> n;

		vector<bool> seive(n + 1, true);
		int res = 0;
		for (int i = 2; i <= n; i++) {
			if (!seive[i]) {
				continue;
			}

			int o = i;
			while (o) {
				if (o % 10 == 0) {
					break;
				}
				o /= 10;
			}
			res += o == 0;
			for (int j = i; j <= n; j += i) {
				seive[j] = false;
			}
		}

		cout << res << endl;
	}
}
