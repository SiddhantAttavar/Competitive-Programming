#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        int ms = (int)log2(c);
        int ans = 1e18 + 1;
        for(int x = 0; x<=(ms + 1); x++){
            int temp = x*a;
            int p = (1<<x);
            temp += ((c + p-1)/p) * b;
            ans = min(ans, temp);

        }
        cout << ans << "\n";
    }
}
