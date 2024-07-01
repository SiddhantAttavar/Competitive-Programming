#include <bits/stdc++.h>
using namespace std;

#define f(i,a,n) for(long long i = a; i < n; i++)
#define rf(i,a,n) for(long long i = a; i > n; i--)
#define endl "\n"
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define meh {cout<<"NO"<<endl;return;}
#define yay {cout<<"YES"<<endl;return;}
#define ok(t) {cout<<t<<endl;return;}
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define vin(v) for(auto&x:v)cin>>x;
#define vout(v) for (auto x: v)cout<<x<<' ';cout<<endl;

typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef map<int,int> mii;
typedef set<int> si;
typedef set<char> sc;

const int MAXN = 200100;
const int MOD = 1000000007;
const int imax = LONG_LONG_MAX;
const int imin = LONG_LONG_MIN;

int n,m,x,k,y;
int a[MAXN],b[MAXN];
bool upd(int l, int r, long long &res) {
    if (l > r) return true;
    bool canDel = false;
    int mx = *max_element(a + l, a + r + 1);
    int len = r - l + 1;
    if (l - 1 >= 0 && a[l - 1] > mx) canDel = true;
    if (r + 1 < n && a[r + 1] > mx) canDel = true;
    if (len < k && !canDel) return false;
    
    int need = len % k;
    res += need * y;
    len -= need;
    
    if (y * k >= x) {
        res += len / k * x;
    } else if(canDel) {
        res += len * y;
    } else {
        res += (len - k) * y + x;
    }
    
    return true;
}

void solve()
{
    cin>>n>>m>>x>>k>>y;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    
    
    int res = 0;
    int lst = -1, posa = 0, posb = 0;
    while (posb < m) {
        while(posa < n && a[posa] != b[posb]) ++posa;
        if (posa == n) {
            cout<<-1;
            return;
        }
        
        if (!upd(lst + 1, posa - 1, res)) {
            cout<<-1;
            return;
        }
        
        lst = posa;
        ++posb;
    }
    
    if (!upd(lst + 1, n - 1, res)) {
        cout<<-1;
        return;
    }
    
    cout<<res;

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++)
    {
        solve();
    }
    return 0;
}
