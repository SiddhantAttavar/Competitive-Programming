#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	input(int, n);
	input(string, s);
	
	int res = 1;
	int start = -1;

	//For length = 1
	bool dp[n][n];
	range(i, 0, n) {
		fill(dp[i], dp[i] + n, false);
	}

	range(i, 0, n) {
		dp[i][i] = true;
		start = i;
	}

	//For length = 2
	range(i, 0, n - 1) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
			res = 2;
			start = i;
		}
	}

	//For length > 2
	range(l, 3, n + 1) {
		range(i, 0, n - l + 1) {
			if (s[i] == s[i + l - 1] && dp[i + 1][i + l - 2]) {
				dp[i][i + l - 1] = true;
				res = l;
				start = i;
			}
		}
	}

	print(res);
	range(i, start, start + res) {
		cout << s[i];
	}
}