#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	cin>>num;
	for(int i=0;i<num;i++){
	    int n,fin=0;
	    cin>>n;
	    int blah=false;
	    
	    int arr[n],count;
	    for(int k=0;k<n;k++){
	        cin>>arr[k];
	    }
	    
	    for(int j=0;j<n;j++){
	        int u=0;
	        int blah=false;
	        // to check if the sum of digits is even of not.
	        for(int cc=0;cc<=j;cc++){
	            
	            int sum =0;
	            int o=n-j;
	            // checking "o" elements at a time.
	            while(o!=0){
    	            sum = sum+ arr[u];
    	            u++;
    	            o--;
    	        }
    	        // cycle breaks when we find arr with even sum.
    	        if(sum%2==0){
        	            blah =true;
        	            fin = n-j;
        	            break;
        	        }else {
        	            // shifting to next "o" elements
        	            u= u-n+j+1;
        	        }
	        }
	        
	        if(blah){
	            cout<<fin<<endl;
	            break;
	        }
	    }
	    if (!blah) {cout << 0 << endl;}
	}
}
