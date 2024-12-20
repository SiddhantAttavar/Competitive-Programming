#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef array<long double,3> vec;

vec cross(vec a, vec b) {
    return {a[1]*b[2] - a[2]*b[1], a[2]*b[0] - a[0]*b[2], a[0]*b[1] - a[1]*b[0]};
}

vec diff(vec a, vec b) {
    return {a[0]-b[0], a[1]-b[1], a[2]-b[2]};
}

vec add(vec a, vec b) {
    return {a[0]+b[0], a[1]+b[1], a[2]+b[2]};
}

vec unit(vec a)
{
    long double norm = sqrtl(a[0]*a[0] + a[1]*a[1] + a[2]*a[2]);
    return {a[0]/norm, a[1]/norm, a[2]/norm};
}

vec div(vec a, long double l) {
    return {a[0] / l, a[1] / l, a[2] / l};
}

long double dot(vec a, vec b) {
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

void solve() { 
    vec os, oa, ob;
    cin >> os[0] >> os[1] >> os[2];
    cin >> oa[0] >> oa[1] >> oa[2];
    cin >> ob[0] >> ob[1] >> ob[2];
    vec sa = diff(oa, os);
    vec sb = diff(ob, os);
    vec plane = unit(cross(sa, sb));
    long double a = dot(plane, os);
    if (a < 0) {
        plane = {-plane[0], -plane[1], -plane[2]};
    }
    vec ac = cross(plane, sa);
    vec oc = add(oa, ac);
    vec bd = cross(sb, plane);
    vec od = add(ob, bd);
    vec ot = add(oc, od);
    vec ot_norm = div(ot, 2);
    cout << fixed << setprecision(8) << ot_norm[0] << ' ' << ot_norm[1] << ' ' << ot_norm[2] << '\n';
}
signed main() { cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit); int t; cin >> t; 
    int i = 0;
    while (t--) {
        solve();
    } 
}
