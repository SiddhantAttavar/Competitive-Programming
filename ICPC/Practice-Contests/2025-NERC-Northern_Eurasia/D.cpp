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

void solve() {
	int n; cin >> n;
    vi type(n+1);
    rep(i, 1, n+1){
        string s; cin >> s;
        string t; cin >> t;
        int to, from;
        if(s == "set"){
            from = 1;
        } else{
            from = 0;
        }
        if(t == "false"){
            to = from;
        } else {
            to = 1- from;
        }
        if(to == 0 && from == 0){
            type[i] = 0;
        } else if(to == 0){
            type[i] = 1;
        } else if(from == 0){
            type[i] = 2;
        } else {
            type[i] = 3;
        }
    }
    vi ans;
    int m; cin >> m;
    vi adjL[n+1];
    vi indegree(n+1, 0);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        adjL[a].push_back(b);
        indegree[b]++;
    }
    queue<int> qa[4];
    for(int i = 1; i<=n; i++){
        if(indegree[i] == 0){
            qa[type[i]].push(i);
        }
    }
    while(!qa[0].empty()){
        int node = qa[0].front();
        qa[0].pop();
        ans.push_back(node);
        for(auto v : adjL[node]){
            indegree[v]--;
            if(indegree[v] == 0){
                qa[type[v]].push(v);
            }
        }
    }
    if(qa[1].size() == 0){
        if(ans.size() == n){
            for(auto it : ans){
                cout << it << " ";
            }cout << endl;
        } else{
            cout << -1 << endl;
        }
        return;
    }
    if(qa[1].size() >= 2){
        cout << -1 << endl;
        return;
    }
    int node = qa[1].front();
    qa[1].pop();
    ans.push_back(node);
    for(auto v : adjL[node]){
        indegree[v]--;
        if(indegree[v] == 0){
            qa[type[v]].push(v);
        }
    }
    while(!qa[3].empty()){
        int node = qa[3].front();
        qa[3].pop();
        ans.push_back(node);
        for(auto v : adjL[node]){
            indegree[v]--;
            if(indegree[v] == 0){
                qa[type[v]].push(v);
            }
        }
    }
    if(qa[2].size() == 0){
        if(ans.size() == n){
            for(auto it : ans){
                cout << it << " ";
            }cout << endl;
        } else{
            cout << -1 << endl;
        }
        return;
    }
    if(qa[2].size() >= 2){
        cout << -1 << endl;
        return;
    }
    node = qa[2].front();
    qa[2].pop();
    ans.push_back(node);
    for(auto v : adjL[node]){
        indegree[v]--;
        if(indegree[v] == 0){
            qa[type[v]].push(v);
        }
    }
    while(!qa[0].empty()){
        int node = qa[0].front();
        qa[0].pop();
        ans.push_back(node);
        for(auto v : adjL[node]){
            indegree[v]--;
            if(indegree[v] == 0){
                qa[type[v]].push(v);
            }
        }
    }
    if(ans.size() == n){
        for(auto it : ans){
            cout << it << " ";
        }cout << endl;
        // cout << "ans vec" << endl;
    } else{
        cout << -1 << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
