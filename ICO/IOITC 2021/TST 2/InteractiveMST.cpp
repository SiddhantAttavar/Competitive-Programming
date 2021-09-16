#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int> query(vector<int> W);//Do not change this line

// Do NOT read anything from stdin or write something to stdout/stderr
//You are free to add variables and functions at global scope here
// If you use global variables, remember to initialize them in the findHiddenPermutation() function.

// If it is impossible to determine the hidden permutation, this function must return {}
vector<int> findHiddenPermutation(int m){
    // your code goes here
    // for example vector<int> mst_edges = query({3, 4, 2, 3, 1});
    vi res(m);
    range(i, 0, m) {
        vi a(m, 1);
        a[i] = 2;
        
        vi b = query(a);
        vector<bool> taken(m, false);
        for (int j : b) {
            taken[j] = true;
        }
        range(j, 0, m) {
            if (!taken[j]) {
                res[i] = j;
            }
        }
    }
    return res;
}