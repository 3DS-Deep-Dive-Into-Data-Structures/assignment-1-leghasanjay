#include<bits/stdc++.h>
// #define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int,int>>
#define st set<int>
#define mst multiset<int>
#define ust unorderedset<int>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define all(x) (x.begin(),x.end())
using namespace std;
 
int main(){
    int n,sm;
    cin>>n>>sm;
    int a[n];
    vvi vt(n,vi(2));
   
    
    rep(i,0,n){
        cin>>a[i];
        vt[i][0]=a[i];
        vt[i][1]=i+1;
      
    }

    sort(vt.begin(),vt.end());
    int i;
    int count=0;
    for( i=0;i<n-2;i++){
        int l=i+1;
        int r=n-1;
        while(l<r){
            if(vt[i][0]+vt[l][0]+vt[r][0]==sm){ cout<<vt[i][1]<<" "<<vt[l][1]<<" "<<vt[r][1];count++;break;}

             else if(vt[i][0]+vt[l][0]+vt[r][0]<sm){
                l++;
        }
        else{
            r--;
        }
        }

        if(count==1) break;
    } 
       
    if(i==n-2) cout<<"IMPOSSIBLE";
    if(vt.size()==1){
        auto it=vt.begin();
        if(vt[0][0]!=sm) cout<<"IMPOSSIBLE";
    }

    return 0;
}



 
    
 
 
        
    
        
   
                




 
