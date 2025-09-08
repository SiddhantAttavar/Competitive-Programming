#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

template<class F, class G, class T>
void rec(int from, int to, F& f, G& g, int& i, T& p, T q) {
	if (p == q) return;
	if (from == to) {
		g(i, to, p);
		i = to; p = q;
	} else {
		int mid = (from + to) >> 1;
		rec(from, mid, f, g, i, p, f(mid));
		rec(mid+1, to, f, g, i, p, q);
	}
}
template<class F, class G>
void constantIntervals(int from, int to, F f, G g) {
	if (to <= from) return;
	int i = from; auto p = f(i), q = f(to-1);
	rec(from, to-1, f, g, i, p, q);
	g(i, to, q);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c ,r;
	cin >> n >> c >> r;

	vector<int> s(n);
	rep(i, 0, n) {
		cin >> s[i];
	}

	vector<int> v = {0};
	rep(i, 0, n) {
		v.push_back(abs(s[i]) + 1);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int res = 2e18;
	constantIntervals(0, v.size(), [&, a = s](int i) {
		int nc = v[i];
		int ans = 0;
		vector<vector<int>> dp(n, vector<int>(2, 0));
		if(a[0] > 0){
			dp[0][0] = 0;
			dp[0][1] = r;
			if(a[0] < nc){
				dp[0][1] = 0;
			}
		} else if(a[0] < 0){
			dp[0][1] = 0;
			dp[0][0] = r;
			if(abs(a[0]) < nc){
				dp[0][0] = 0;
			}
		} else{
			if(nc > 0){
				dp[0][0] = dp[0][1] = 0;
			} else{
				dp[0][0] = dp[0][1] = r;
			}
		}
		for(int i = 1; i<n; i++){
			// dp[i][0]
			dp[i][0] = dp[i-1][0] + r;
			if(a[i] > 0 || (abs(a[i]) < nc)){
				dp[i][0] = min(dp[i][0], dp[i-1][1]);
			}
	 
			// dp[i][1]
			dp[i][1] = dp[i-1][1] + r;
			if(a[i] < 0 || ((abs(a[i]) < nc))){
				dp[i][1] = min(dp[i][1], dp[i-1][0]);
			}
		}
		ans += min(dp[n-1][0], dp[n-1][1]);
		return -ans;
	}, [&](int a, int b, int x) {
		cout << -x / r << ' ' << a << endl;
		res = min(res, c * v[a] - x);
	});
	cout << res << endl;
}
