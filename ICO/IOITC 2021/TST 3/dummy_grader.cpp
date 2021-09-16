#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cerr << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cerr << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

namespace{
    int N;
    const int QMAX = 120;
    int a, b, asked;
}

bool doesPathExist(const vector<string> &M);

pair<int, int> findHiddenCell(int n) {
    int x = -1, y = -1;

    vector<string> a(n);
    range(i, 0, n) {
        range(j, 0, n) {
            a[i] += '1';
        }
    }

    // Check for rows 2 and 48
    vector<string> curr0 = a;
    range(i, 0, n) {
        curr0[1][i] = '0';
    }
    if (doesPathExist(curr0)) {
        x = 1;
    }
    curr0 = a;
    range(i, 0, n) {
        curr0[48][i] = '0';
    }
    if (doesPathExist(curr0)) {
        x = 48;
    }

    if (x == 1 || x == 48) {
        int low = 1, high = n - 2;
        while (low < high) {
            int mid = (low + high) / 2;
            
            vector<string> curr = a;
            range(j, 0, n) {
                curr[x][j] = '0';
            }
            range(j, x + 1, n) {
                curr[j][mid] = '0';
            }

            if (doesPathExist(curr)) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        y = low;

        return {x, y};
    }
    
    range(k, 0, 4) {
        vector<string> base(n);
        range(i, 0, n) {
            range(j, 0, n) {
                base[i] += '0';
            }
        }

        range(i, 0, n - 1) {
            base[0][i] = '1';
        }
        base[0][n - 1] = '0';
        for (int i = k; i < n; i += 4) {
            base[1][i] = '1';
        }
        range(j, 2, n - 2) {
            range(i, 0, n / 2) {
                if (k % 2 == 1) {
                    base[j][2 * i] = '0';
                    base[j][2 * i + 1] = '1';
                }
                else {
                    base[j][2 * i] = '1';
                    base[j][2 * i + 1] = '0';
                }
            }
        }
        for (int i = (k + 2) % 4; i < n; i += 4) {
            base[n - 2][i] = '1';
        }

        int l = 0;
        for (int i = k + 1; i < n; i += 4) {
            l++;
        }

        /*for (string i : base) {
            print(i);
        }*/
        //print(k, l);

        int low = 0, high = l - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (high - low == 1) {
                mid++;   
            }
            //print(low, mid, high);

            vector<string> curr = base;
            int s = k + 1 + 4 * mid;
            range(i, s, n) {
                curr[n - 1][i] = '1';
            }

            if (high - low == 1) {
                if (doesPathExist(curr)) {
                    y = s;
                    break;
                }
                else {
                    curr = base;
                    mid--;
                    int s = k + 1 + 4 * mid;
                    range(i, s, n) {
                        curr[n - 1][i] = '1';
                    }
                    /*for (auto i : curr) {
                        print(i);
                    }*/
                    //print(doesPathExist(curr));
                    if (doesPathExist(curr)) {
                        y = s;
                    }
                    break;
                }
            }

            if (doesPathExist(curr)) {
                low = mid;
                y = s;
            }
            else {
                high = mid - 1;
            }
        }

        if (y != -1) {
            break;
        }
    }

    int low = 1, high = n - 2;
    while (low < high) {
        int mid = (low + high) / 2;
        
        vector<string> curr = a;
        range(j, 0, n) {
            curr[j][y] = '0';
        }
        range(j, y + 1, n) {
            curr[mid][j] = '0';
        }

        if (doesPathExist(curr)) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    x = low;

    return {x, y};
}

bool doesPathExist(const vector<string> & M){
    if(asked == QMAX){
        cerr << "Asked too many queries" << endl;
        exit(0);
    }
    if((int)M.size() != N){
        cerr << "Invalid query" << endl;
        exit(0);
    }
    for(int i = 0; i < N; i++){
        if((int)M[i].length() != N){
            cerr << "Invalid query" << endl;
            exit(0);
        }
        for(int j = 0; j < N; j++){
            if(M[i][j] != '0' && M[i][j] != '1'){
                cerr << "Non 0-1 character in M" << endl;
                cout << 0 << endl;
                exit(0);
            }
        }
    }
    asked++;
    vector<vector<bool>> dp(N, vector<bool>(N, false));
    dp[0][0] = M[0][0] == '1';
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) if(i + j && (M[i][j] == '1' || (i == a && j == b))){
            if(i && dp[i - 1][j]) dp[i][j] = true;
            if(j && dp[i][j - 1]) dp[i][j] = true;
        }
    }
    return dp[N - 1][N - 1];
}

int main(){
    int Q = 0;
    int T; cin >> T;
    while(T--) {
        print(T);
        N = 50;
        a = rand() % 48 + 1, b = rand() % 48 + 1;
        //cin >> N;
        //cin >> a >> b;
        print(N, a, b);
        asked = 0;
        pair<int, int> P = findHiddenCell(N);
        
        if(P != make_pair(a, b)){
            cerr << "Incorrect output!" << endl;
            cerr << "Expected: " << "(" <<a<<", " << b << ")" << endl;
            cerr << "Got: " << "(" <<P.first<<", " << P.second << ")" << endl;
            exit(0);
        }
        cerr << "Correct output!" << endl;
        cerr << "Queries asked = " << asked << endl;
        Q = max(Q, asked);
    }

    cerr << "Score: ";
    if (Q > 120) {
        print(0);
    }
    else if (Q > 60) {
        print(9);
    }
    else if (Q > 50) {
        print(24);
    }
    else {
        print(100);
    }
    print("Queries: ", Q);
}