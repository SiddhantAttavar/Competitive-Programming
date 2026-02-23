#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

#define ld long double

#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Pt {
    ll x, y;
};

ll cross(vector<Pt>& p, ll a, ll b, ll c) {
    ll x1 = p[b].x - p[a].x;
    ll x2 = p[c].x - p[a].x;
    ll y1 = p[b].y - p[a].y;
    ll y2 = p[c].y - p[a].y;
    return (x1*y2 - x2*y1);
}

ld slope(vector<Pt>& p, ll i, ll j) {
    return ((ld)(p[i].y - p[j].y) / (ld)(p[i].x - p[j].x));
}


vector<ld> mx_slope_to_left(vector<Pt>& p) {
    ll n = sz(p);
    vector<ld> ans(n);
    vector<ll> useful_indices;

    useful_indices.reserve(n);

    for(ll i = 0; i < n; i++) {

        if(!useful_indices.empty()) {

            ll L = 0, R = sz(useful_indices) - 2, best = -1;
            while(L <= R) {
                ll mid = L + (R - L)/2;
                if(cross(p, useful_indices[mid], useful_indices[mid+1], i) >= 0) {
                    best = mid;
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
            ll curr_best = (best == -1 ? 0 : best+1);
            ans[i] = slope(p, i, useful_indices[curr_best]);
        }

        ll SZ = sz(useful_indices);
        while(sz(useful_indices) >= 2 && cross(p, useful_indices[sz(useful_indices)-2], useful_indices[sz(useful_indices)-1], i) <= 0) {
            useful_indices.pop_back();
        }
        useful_indices.push_back(i);

    }

    return ans;
}


void solve() {

    // return;

    ll n; cin >> n;
    vector<Pt> p(n); for(ll i = 0; i < n; i++) { cin >> p[i].x >> p[i].y; }

    // for(ll i = 0; i < n; i++) {
    //     cout << p[i].x << " " << p[i].y << endl;
    // }
    // cout << "---------" << endl;

    auto left_mx = mx_slope_to_left(p);

    vector<Pt> rev_p(n);
    for(ll i = 0; i < n; i++) {
        rev_p[i].x = -p[n-1-i].x;
        rev_p[i].y = p[n-1-i].y;
    }

    auto right_mx_rev = mx_slope_to_left(rev_p);

    vector<ld> right_mx(n);
    for(ll i = 0; i < n; i++) {
        right_mx[i] = right_mx_rev[n-1-i];
    }

    // for(ll i = 0; i < n; i++) {
    //     cout << left_mx[i] << " "<< right_mx[i] << endl;
    //     // assert(left_mx[i] != 0);
    //     // assert(right_mx[i] != 0);
    // }

    ld ans = 0;
    for(ll i = 1; i <= n-2; i++) {
        ll y = p[i].y;
        ld area = 0.5 * y * y * ((1.0 / left_mx[i]) + (1.0 / right_mx[i]));
        ans = max(ans, area);
    }

    cout << fixed << setprecision(10) << ans << endl;

}   

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t; // comment out if reqd.
    while (t--) {solve();}
}
