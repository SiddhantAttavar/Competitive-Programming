#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl '\n'
#define sz(x) ((ll)((x).size()))

//=======================================================------------------------------------------------------
void print(int t) {cout << t;} 
void print(string t) {cout << t;}
void print(char t) {cout << t;}
void print(double t) {cout << t;}
template <class T, class V> void print(pair <T, V> p);
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T, class V> void print(map <T, V> v);
template <class T> void print(multiset <T> v);
template <class T, class V> void print(pair <T, V> p) {cout << "{"; print(p.first); cout << ","; print(p.second); cout << "}";}
template <class T> void print(vector <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T> void print(set <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T> void print(multiset <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T, class V> void print(map <T, V> v) {cout << "[ "; for (auto i : v) {print(i); cout << " ";} cout << "]\n";}
//=======================================================------------------------------------------------------

ll check(string& s) {
    ll ans = 0;
    for(ll i = 0; i < sz(s); i++) {
        string a = s.substr(0, i+1);
        string b = a;
        reverse(b.begin(), b.end());

        if(a == b) {
            ans = max(ans, i+1);
        }
    }
    return ans;
}

ll make_palin(string s) {
    // pref
    ll ans = 0;
    ans = max(ans, check(s));
    reverse(s.begin(), s.end());
    ans = max(ans, check(s));
    // cout << s << " " << ans << endl;
	return 2 * sz(s) - ans;
}

ll solve(string& s, string& t) {

	for (int i = 0; i < sz(s) - sz(t) + 1; i++) {
		if (s.substr(i, sz(t)) == t) {
			return (make_palin(s));
		} 
	}

    ll len = 0;

    // cout << s << " " << t << endl;

    for(ll i = 0; i < min(sz(t), sz(s)); i++) { 
        string a = t.substr(0, i+1);
        string b = s.substr(sz(s) - i - 1);
        if(a == b) {
            len = i+1;
            break;
        }
    }

    // cheks suffix of s and pref of t
    // cout << len << endl;

    string new_s = s;
    if(len < sz(t)) {
        new_s += t.substr(len);
    }

    return make_palin(new_s);
}

void final_solve() {
    string s, t; cin >> s >> t;
    // if(sz(s) < sz(t)) { swap(s, t); }

    string revs = s;
    reverse(revs.begin(), revs.end());

    string revt = t;
    reverse(revt.begin(), revt.end());

    ll ns = sz(s);
    ll nt = sz(t);

    ll ans = ns + nt + nt + ns;
    ans = min(ans, solve(s, t));
    ans = min(ans, solve(t, s));
    ans = min(ans, solve(revs, t));
    ans = min(ans, solve(t, revs));
    ans = min(ans, solve(s, revt));
    ans = min(ans, solve(revt, s));
    ans = min(ans, solve(revs, revt));
    ans = min(ans, solve(revt, revs));


    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int TT = 1; 
    cin >> TT;
    while(TT--) {final_solve();}    
    return 0;
}

