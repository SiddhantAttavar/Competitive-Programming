#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;

    vi l(n), r(n);
    vector<vi> x(n);
    rep(i, 0, n) {
        int k;
        cin >> k >> l[i] >> r[i];

        x[i].resize(k);
        rep(j, 0, k) {
            cin >> x[i][j];
        }
    }

    multiset<int> end;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<vi> p(n);
    vi ind(n, -1), curend(n, 0), sum(n, 0);
    rep(i, 0, n) {
        sum[i] = accumulate(x[i].begin(), x[i].end(), 0ll);
        curend[i] = r[i] - sum[i];
        end.insert(curend[i]);
        pq.push({l[i], i});
    }
    
    int start = *max_element(l.begin(), l.end());
    int res = max(0ll, *end.begin() - start);
    while (!pq.empty()) {
        auto [z, i] = pq.top();
        pq.pop();

        start = max(z, start);

        end.erase(end.find(curend[i]));
        curend[i] = r[i] - (sum[i] - (z - l[i]));
        end.insert(curend[i]);
        res = max(res, *end.begin() - start);

        ind[i]++;
        if (ind[i] < sz(x[i])) {
            pq.push({z + x[i][ind[i]], i});
        }
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
