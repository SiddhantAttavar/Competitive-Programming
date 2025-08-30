#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("java2016.in", "r", stdin);
    freopen("java2016.out", "w", stdout);

    int n;
    cin >> n;

    if (n == 0) {
        cout << "?/?/?";
        return 0;
    }

    string res;
    res += "a=? max ?\n";
    res += "b=a max a\n";
    res += "c=b max b\n";
    res += "d=c max c\n";
    res += "e=d max d\n";
    res += "f=e max e\n";
    res += "g=f max f\n";
    res += "h=g max g\n";
    res += "i=h max h\n";
    res += "j=i max i\n";
    res += "k=j max j\n";
    res += "l=k max k\n";
    res += "m=l max l\n";
    res += "n=m max m\n";
    res += "o=n max n\n";
    res += "p=o max o\n";
    res += "q=p max p\n";
    res += "r=q/q\n";
    res += "s=r+r\n";
    res += "t=s*s\n";
    res += "u=s*t\n";
    res += "v=t*t\n";
    res += "w=t*u\n";
    res += "x=u*u\n";
    res += "y=u*v\n";
    res += "z=v*v\n";

    rep(i, 0, 8) {
        if (n & (1 << i)) {
            res += 'r' + i;
            res += '+';
        }
    }
    res.back() = '\n';
    assert(res.size() <= 256);
    cout << res;
}
