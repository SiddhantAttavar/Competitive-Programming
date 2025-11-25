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

#define double long double

constexpr double PI = 3.14159265358979311600;

template<class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator< (P p) const {return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const {return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a)); 
    }
    friend ostream& operator<<(ostream& os, P p) { 
        return os << "(" << p.x << "," << p.y << ") ";
    }
};

template<class P> 
double lineDist(const P& a, const P& b, const P& p) {
    return abs((double)(b-a).cross(p-a)/(b-a).dist());
}

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
    if(sz(pts) <= 1) { return pts; }
    sort(all(pts));
    vector<P> h(sz(pts) + 1);
    int s = 0, t = 0;
    for(int it = 2; it--; s = --t, reverse(all(pts))) {
        for(P p: pts) {
            while(t >= s + 2 && h[t-2].cross(h[t-1], p)<= 0) t--;
            h[t++] = p;
        }
    }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

template<class P>
int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

template<class P>
bool onSegment(P s, P e, P p) {
    return p.cross(s,e) == 0 && (s-p).dot(e-p) <= 0; 
}

bool inHull(const vector<P>& l, P p, bool strict = true) {
    int a = 1, b = sz(l) - 1, r = !strict;
    if(sz(l) < 3) return r && onSegment(l[0], l.back(), p);
    if(sideOf(l[0], l[a], l[b]) > 0) swap(a, b);
    if(sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p) <= -r) { return false; }
    while(abs(a-b) > 1) {
        int c = (a+b)/2;
        (sideOf(l[0], l[c], p) > 0 ? b : a) = c;
    }
    return sgn(l[a].cross(l[b], p)) < r;
}

double find_area(P a, P b, ll rad) {

    // cout << rad << endl;
    double perp = lineDist(a, b, P(0, 0));
    
    // double theta = acos(perp / (1.0 * rad));


    // double theta = atan()
    
    // cout << perp << " " << theta << endl;

    // cout << 1.0*sin(2*theta)*rad*rad/2.0 << endl;
    // cout << PI << endl;

    // double cs = (perp / rad);
    // double s2t = cs*(sqrtl(1 - cs*cs));

    double base = sqrtl(rad*rad - perp*perp);

    double theta = atan2(base, perp);

    double area1 = theta*rad*rad - base*perp;
    // double area2 = PI * rad*rad - area1;
    
    // cout << area1 << endl;
    
    // return min(area1, area2); 
    return area1;
}



void solve() {
    ll n, r; cin >> n >> r;
    // cout << "Rad: " << r << endl;
    vector<P> pts;
    for(ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        pts.push_back(P(x, y));
    }

    pts.push_back(P(0, 0));

    auto plg = convexHull(pts);

    if(sz(plg) < 2) {
        cout << fixed << setprecision(15) << PI * r * r / 2 << endl;
        return;
    }


    // for(auto p : plg) {
    //     cout << p << endl;
    // }

    // cout << inHull(plg, P(0, 0), false) << endl;

    // if(inHull(plg, P(0,0), false) == false) {
    //     double ans = PI * r * r;
    //     ans /= 2.0;
    //     cout << fixed << setprecision(15) << ans << endl;
    //     return;
    // }

    double ans = 0;

    for(ll i = 0; i < sz(plg); i++) {
        P p1 = plg[i];
        P p2 = plg[(i+1)%sz(plg)];

        if(p1 == p2) { continue; }

        ans = max(ans, find_area(p1, p2, r));
        
        // cout << p1 << " " << p2 << ": " << ans << endl;
    }

    cout << fixed << setprecision(15) << ans << endl;

}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
