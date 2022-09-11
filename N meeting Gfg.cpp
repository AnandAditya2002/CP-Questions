#include<bits/stdc++.h>
using namespace std;
class meeting{
    public : 
       int start;
       int end;
       int pos;

};
bool comparator(meeting a, meeting b){
    if(a.end < b.end){
        return true;
    }
    else if(a.end > b.end){
        return false;
    }
    // else if(a.pos < b.pos){
    //     return true;
    // }
    return false;
}
void maximumMeetings(vector<int> &s, vector<int> &e) {
    // Write your code here.
    int n = s.size();
    meeting arr[n];
    for(int i=0;i<n;i++){
        arr[i].start = s[i];
        arr[i].end = e[i];
        arr[i].pos = i+1;
    }
    sort(arr,arr+n , comparator);
    vector<int>ans;
    int prev = arr[0].end;
    ans.push_back(arr[0].pos);
    for(int i=1;i<n;i++){
        if(arr[i].start > prev){
            ans.push_back(arr[i].pos);
            prev = arr[i].end;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;cin>>n;
        vector<int>s;
        vector<int >e;
        for(int i=0;i<n;i++){
            int d;
            cin>>d;
            s.push_back(d);
        }
        for(int i=0;i<n;i++){
            int d;
            cin>>d;
        e.push_back(d);
        }
        maximumMeetings(s,e);
    }
    return 0;
}