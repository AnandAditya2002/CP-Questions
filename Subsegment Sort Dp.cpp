#include<bits/stdc++.h>
using namespace std;
#define ll long long
int f(int n, vector<int>arr){ 
    vector<int>dp(n+1,-1);            /*Here the ith element of dp array represent the nearest smaller
                                        element of the corresponding ith element of ith element of given 
                                        arrray */ 
    dp[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        dp[i] = min(dp[i+1], arr[i]);
    }
    int ans =1;
    int xxx = -1;
    for(int i=0;i<n-1;i++){
        xxx = max(xxx,arr[i]);        /*variable xxx keeps track of max elemnent so far*/
        if(xxx <= dp[i+1]){           /*if the max element so far is less than the nearest smallest 
                                         element of next element then we have to include this element
                                         in the next partiton */
                    
            ans++;  
        }
    }
    return ans;
}
int main(){
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int >arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<f(n,arr)<<endl;
    }
	return 0;
}