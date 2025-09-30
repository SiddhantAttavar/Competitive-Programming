#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc; while (tc--) {
		string s;
		cin >> s;

		int a = 0, b = 0, c = 0;
		rep(i, 0, s.size()) {
			if (s[i] == '2') {
				c++;
			}
			else if ((s[i] == '0') == i % 2) {
				a++;
			}
			else {
				b++;
			}
		}

		cout << max((int) s.size() % 2, abs(a - b) - c) << endl;
	}
}
