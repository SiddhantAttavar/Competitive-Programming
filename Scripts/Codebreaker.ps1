# Run this script in the Competitive-Programming directory to add a new codebreaker file
$template = @'
// https://codebreaker.xyz/problem/${problem}
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	
}
'@

# Open folder
cd Codebreaker
$root = Get-Location
$problem = $args[0]

# Create file
$file = "$root\$problem.cpp"
New-Item -Type File -Path $file | Out-Null

# Write to file
$FileContent = $ExecutionContext.InvokeCommand.ExpandString($template)
$Utf8NoBomEncoding = New-Object System.Text.UTF8Encoding $False
[System.IO.File]::WriteAllLines($file, $FileContent, $Utf8NoBomEncoding)

# Open file
code -r $file
