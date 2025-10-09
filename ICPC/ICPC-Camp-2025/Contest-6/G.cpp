#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int h, w;
int ri, ci;
bool check(int i, int j){
    if(i<0 || i >=h || j < 0 || j>=w){
        return false;
    } else{
        return true;
    }
}
bool check1(int i, int j){
    if(i<ri || i >=h || j < 0 || j>=w){
        return false;
    } else{
        return true;
    }
}
void solve(){
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            cin >> grid[i][j];
        }
    }
    queue<pair<int,int>> q;
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, 1, -1};

    for(int j = 0; j<w; j++){
        if(grid[0][j] == '.'){
            q.push({0, j});
        }
        if(grid[h-1][j] == '.'){
            q.push({h-1, j});
        }
    }
    for(int i = 1; i<h-1; i++){
        if(grid[i][0] == '.'){
            q.push({i, 0});
        }
        if(grid[i][w-1] == '.'){
            q.push({i, w-1});
        }
    }

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        grid[i][j] = 'L';
        for(int k = 0; k<4; k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(check(ni, nj) && grid[ni][nj] == '.'){
                q.push({ni, nj});
            }
        }
    }
    // for(int i = 0; i<h; i++){
    //     for(int j = 0; j<w; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    bool found = false;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            if(grid[i][j] == '.'){
                // cout << i << " " << j << endl;
                ri = i - 1;
                ci = j;
                found = true;
                break;
            }
        }
        if(found){
            break;
        }
    }
    // cout << ri << " " << ci << endl;
    // q.clear();
    vector<vector<pair<int,int>>> parent(h, vector<pair<int,int>>(w, {-1ll, -1ll}));
    grid[ri][ci] = 'P';
    pair<int, int> def = {-1ll, -1ll};

    for(int k = 0; k<4; k++){
        if(k == 2){
            continue;
        }
        int ni = ri + di[k];
        int nj = ci + dj[k];
        if(check1(ni, nj) && grid[ni][nj] == '#'){
            // cout << ni << " " << nj << endl;
            q.push({ni, nj});
            if(parent[ni][nj] == def){
                parent[ni][nj] = {ri, ci};
            }
        }
    }
    // cout << endl;
    int rf = -1, cf = -1;
    while(!q.empty() && rf == -1 ){
        auto [i, j] = q.front();
        // cout << i << " " << j << endl;
        q.pop();
        grid[i][j] = 'P';
        for(int k = 0; k<4; k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(k != 2 && ni == ri && nj == ci){
                // cout << i << " " << j << endl;
                rf = i;
                cf = j;
                break;
            }
            if(check1(ni, nj) && grid[ni][nj] == '#' && parent[ni][nj] == def){
                q.push({ni, nj});
                parent[ni][nj] = {i, j};
            }
        }
    }
    // set<pair<int,int>> actuals;
    vector<vector<int>> actuals(h, vector<int>(w, 0));
    while(!(rf == ri && cf == ci)){
        // cout << rf << " " << cf << endl;
        // cout << parent[rf][cf].first << " " << parent[rf][cf].second << endl;
        // cout << endl;
        actuals[rf][cf] = 1;
        int nr = parent[rf][cf].first;
        int nc = parent[rf][cf].second;
        rf = nr;
        cf = nc;
    }
    actuals[rf][cf] = 1;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            if(actuals[i][j] == 0){
                grid[i][j] = '.';
            } else{
                grid[i][j] = '#';
            }
        }
    }

    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}

