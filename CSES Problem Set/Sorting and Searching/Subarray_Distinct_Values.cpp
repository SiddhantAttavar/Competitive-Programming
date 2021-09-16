#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define debug(a) cout << (&a) << " : " << a << '\n'
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
const int MAX_N = 2e5;
map<int, int> sum;
int inp[MAX_N];
int main() {
	fast;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> inp[i];
	int num = 0, l = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (sum[inp[i]] == 0) num++;
		sum[inp[i]]++;
		if (num > k) {
			for (; num > k; l++) {
				sum[inp[l]]--;
				if (sum[inp[l]] == 0) num--;
			}
		}
		ans += i - l + 1;
	}
	cout << ans;
	return 0;
}