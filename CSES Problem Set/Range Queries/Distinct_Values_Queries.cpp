#include <bits/stdc++.h>
using namespace std;
#define z vector
#define y int
void u(y x,y v,z<y>&b){for(x++;x<size(b);x+=x&(-x))b[x]+=v;}
y main(){y n,q;cin>>n>>q;z<y>a(n),s(q),b(n+1);z<z<pair<y, y>>>v(n);for(y&i:a)cin>>i;for(y i=0;i<q;){y a,b;cin>>a>>b;v[a-1].push_back({b-1,i++});};map<y,y>l;for(y i=n-1;i+1;){y f=a[i];if(l.count(f))u(l[f],-1,b);l[f]=i;u(i,1,b);for(auto g:v[i--]){for(y x=g.first+1;x;x-=x&(-x)){s[g.second]+=b[x];}}}for(y a:s)cout<<a<<'\n';}
