#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

bool comp(string& f, string& s){
    if(f.size() == s.size()){
        return f<s;
    } else{
        return f.size() < s.size();
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<string> v;
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), comp);
    // for(auto it : v){
    //     cout << it << endl;
    // }
    set<string> c;
    int ans = 0;
    for(auto &s : v){
        if(s.length() == 1){
            ans = max(ans, 1ll);
            c.insert(s);
        } else{
            string t1 = s.substr(0, s.length()-1);
            string t2 = s.substr(1, s.length()-1);
            if(c.find(t1) != c.end() && c.find(t2) != c.end()){
                ans = max(ans, (long long)s.length());
                c.insert(s);
            }
        }
    }
    cout << ans << endl;
}
