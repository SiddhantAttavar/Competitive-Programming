#include <iostream>
#include <vector>

using namespace std;

int nums[200005], pos[200005]; // nums[i] represent where the number i is, and pos[i] represent what number is at position i.

int main(){
    int n, m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        nums[a]=i;
        pos[i]=a;
    }
    int ans=1;
    for (int i=2;i<=n;i++){
        if (nums[i-1]>nums[i]) ans++;
    }
    for (int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        a--;b--;
        int num1=min(pos[a], pos[b]), num2=max(pos[a], pos[b]);
        if (nums[num1]<nums[num1-1]) ans--; // comparing x to x-1
        if (nums[num1]>nums[num1+1]) ans--;// comparing x to x+1
        if (num2-num1!=1&&nums[num2]<nums[num2-1]) ans--; // comparing y to y-1, don't count twice
        if (num2!=n&&nums[num2]>nums[num2+1]) ans--; // comparing y to y+1
        swap(nums[pos[a]], nums[pos[b]]);
        swap(pos[a], pos[b]);
        if (nums[num1]<nums[num1-1]) ans++;
        if (nums[num1]>nums[num1+1]) ans++;
        if (num2-num1!=1&&nums[num2]<nums[num2-1]) ans++;
        if (num2!=n&&nums[num2]>nums[num2+1]) ans++;
        cout<<ans<<endl;
    }
}