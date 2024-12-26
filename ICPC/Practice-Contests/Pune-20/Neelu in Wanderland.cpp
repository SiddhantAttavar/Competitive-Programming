#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define all(v) begin(v), end(v)
#define sz(a) (int)a.size()

typedef long long ll;
typedef complex<double> C;
typedef vector<double> vd;

const int mod = 1e9+7;

void fft(vector<C> &a)
{   
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2,1);
    static vector<C> rt(2,1);
    for(static int k = 2; k < n; k*= 2)
    {
        R.resize(n);rt.resize(n);
        auto x = polar(1.0L,acos(-1.0L)/k);
        rep(i,k,2*k)rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n)rev[i] = (rev[i/2] | (i & 1) << L) / 2;
    rep(i,0,n) if(i < rev[i])swap(a[i], a[rev[i]]);
    for(int k = 1; k < n; k *= 2)
    {
        for(int i = 0; i < n; i += 2*k)rep(j,0,k){
            C z = rt[j+k] * a[i+j+k];
            a[i+j+k] = a[i+j] - z;
            a[i+j] += z;
        }
    }
}

typedef vector<ll> vl;

// template<int M> vl convMod(const vl &a, const vl &b){
//     if(a.empty() || b.empty())return {};
//     vl res(sz(a) + sz(b) - 1);
//     int B = 32 - __builtin_clz(sz(res)), n = 1<<B, cut = int(sqrt(M));
//     vector<C> L(n), R(n), outs(n), outl(n);
//     rep(i,0,sz(a))L[i] = C((int)a[i]/cut, (int)a[i] % cut);
//     rep(i,0,sz(b))R[i] = C((int)b[i]/cut, (int)b[i] % cut);
//     fft(L),fft(R);
//     rep(i,0,n)
//     {
//         int j = -i & (n-1);
//         outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
//         outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
//     }
//     fft(outl), fft(outs);
//     rep(i,0,sz(res)){
//         ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i]) + .5);
//         ll bv = ll(real(outl[i])+.5) +  ll(imag(outs[i]) + .5);
//         res[i] = ((av%M * cut + bv)%M * cut + cv) % M;
//     }
//     return res;
// }

vd conv(const vd &a, const vd &b)
{
    if(a.empty() || b.empty())return {};
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i,0,sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x: in) x *= x;
    rep(i,0,n) out[i] = in[-i & (n-1)] - conj(in[i]);
    fft(out);
    rep(i,0,sz(res))res[i] = imag(out[i]) / (4*n);
    return res;
}

const double EPS = .01;

void pow(vd &a, int n)
{
    vd res(1,1);
    // if(n == 0)
    // {
    //     a = res;
    //     return;
    // }
    while(n)
    {
        if(n&1)
        {
            res = conv(res, a);
        }
        a = conv(a,a);
        n >>= 1;
    }
    a = res;
}

void solve()
{
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    s.resize(n);
    t.resize(n);
    vd p(13,0);
    p[6] = 1;
    vd p1(13, 1);
    p1[6] = 0; // ? - ?

    vd pL(13), pR(13);
    rep(i,0,6)pL[i] = 1,pR[12-i] = 1;

    int fixed = 0;
    int cnt = 1;
    
    int cntl = 0, cntr = 0, cntx = 0;
    int cnts[7] = {0};

    rep(i,0,sz(s))
    {
        if(s[i] == '?' && t[i] == '?')
        {
            cnt++;
            // p = conv(p,p1);
            cntx++;
        }
        else if(s[i] == '?')
        {
            cnt++;
            if(t[i] == 'L')
            {
                cntl++;
                // p = conv(p,pL);
            }
            else 
            {
                cntr++;
                // p = conv(p,pR);
            }
        }
        else if(t[i] == '?')
        {
            cnt++;
            cnts[s[i]-'0']++;
            // vd tmp(13);
            // tmp[6 + s[i] - '0'] = 1;
            // tmp[6 - s[i] + '0'] = 1;
            // p = conv(p,tmp);
        }
        else
        {
            if(t[i] == 'L')
            {
                fixed -=s[i] - '0';
            }
            else
            {
                fixed += s[i] - '0';
            }
            fixed %= mod;
        }
    }
    pow(p1, cntx);
    pow(pL, cntl);
    pow(pR, cntr);
    p = conv(p, p1);
    p = conv(p, pL);
    p = conv(p, pR);
    
    rep(i,1,7)
    {
        vd tmp(13);
        tmp[6 + i] = 1;
        tmp[6 - i] = 1;
        pow(tmp, cnts[i]);
        p = conv(p, tmp);
    }
    ll ans = 0;
    rep(i,0,sz(p))
    {
        if(p[i] > EPS)
        {
            ll tmp = i - (6*cnt) % mod;
            tmp += mod;
            tmp %= mod;
            tmp += fixed;
            tmp %= mod;
            ans += (tmp*tmp)%mod;
            ans %= mod;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}

