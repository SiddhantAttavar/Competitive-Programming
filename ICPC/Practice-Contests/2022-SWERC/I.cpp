#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


ll tri_area_double(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
}

ll calc_triangle(ll L, ll i, ll R, vector<array<ll, 3>>& pts) {
    return tri_area_double(pts[L][0], pts[L][1], pts[i][0], pts[i][1], pts[R][0], pts[R][1]);
}

void solve() {
	ll n; cin >> n;

    vector<array<ll, 3>> pts;

    for(ll i = 0; i < n; i++) {
        ll x,y; cin >> x >> y;
        pts.push_back({x, y, i});
    }

    auto store_pts = pts;

    // simulation:
    ll A = 0, B = 0;

    auto choose_and_delete = [&](ll player)->ll {
        vector<pair<ll, ll>> areas; // {area, idx}
        for(ll i = 0; i < sz(pts); i++) {
            ll L = (i - 1 + sz(pts)) % sz(pts);
            ll R = (i + 1) % sz(pts);
            areas.push_back({calc_triangle(L, i, R, pts), pts[i][2]});
        }

        auto it = min_element(all(areas));
        ll min_area_tri_idx = it - areas.begin();
        
        if(player == 0) { A += it->first; }
        else { B += it->first; }

        ll og_idx_delt = it->second;

        pts.erase(pts.begin() + min_area_tri_idx);
        return og_idx_delt;
    };
    
    ll player = 0;
    while(sz(pts) >= 3) {
        ll og_idx_delt = choose_and_delete(player);
        // cout << player << " chooses : " << og_idx_delt + 1 << endl;
        player ^= 1;
    }

    // cout << A << " " << B << endl;

    pts = store_pts;

    auto do_judge = [&](ll og_pt_idx) -> void {
        ll idx = -1;
        for(ll i = 0; i < sz(pts); i++) {
            if(pts[i][2] == og_pt_idx) {
                idx = i;
                break;
            }
        }
        assert(idx != -1);
        pts.erase(pts.begin() + idx);
        return;
    };

    if(A >= B) {
        // choose B
        cout << "Beatrice" << endl; cout.flush();

        for(ll i = 0; i < n-2; i++) {
            if(i % 2 == 0) {
                ll judge_pt; cin >> judge_pt;
                judge_pt--;
                do_judge(judge_pt);
            } else {
                ll x = choose_and_delete(1);
                cout << x+1 << endl; cout.flush();
            }
        }

    } else {
        // choose A
        cout << "Alberto" << endl; cout.flush();

        for(ll i = 0; i < n-2; i++) {
            if(i % 2 == 0) {
                ll x = choose_and_delete(0);
                cout << x+1 << endl; cout.flush();
            } else {
                ll judge_pt; cin >> judge_pt;
                judge_pt--;
                do_judge(judge_pt);
            }
        }
    }


}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
