#include <bits/stdc++.h>
#define ll long long
#define d double
using namespace std;

vector<vector<int>> maxtable;
vector<vector<int>> mintable;

void buildSparseTable(int arr[], int n) 
{  
  
      int x= ceil(log2(n))+1;

  maxtable.assign(n,vector<int>(x + 1,0));
  mintable.assign(n,vector<int>(x + 1,0));

    for (int i = 0; i < n; i++){ 
        mintable[i][0] = arr[i];  
        maxtable[i][0] = arr[i];
    }

    for (int j = 1;  j <= x; j++) { 
        for (int i = 0; (i + (1 << j) ) <= n; i++) { 
            maxtable[i][j]= max(maxtable[i][j-1],maxtable[i+(1 << (j-1))][j-1]);
            mintable[i][j]= min(mintable[i][j-1],mintable[i+(1 << (j-1))][j-1]);

        } 
    } 
} 

int minquery(int L, int R) 
{
    int j = (int)log2(R - L + 1); 
   return min(mintable[L][j],mintable[R - (1<<j)+1][j]);
}

int maxquery(int L, int R) 
{
    int j = (int)log2(R - L + 1); 
   return max(maxtable[L][j],maxtable[R - (1<<j)+1][j]);
 }

int main()
{
  int n,q;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++){
    cin>>a[i];
  }
   buildSparseTable(a,n);

  cin >> q;
  for (ll i = 0; i < q; i++)
  {
    int l, r;
  cin >> l >> r;
      d t1=(d)minquery(l,r);
    d t2=(d)maxquery(l,r);
    
    d t3=0;

    if(l>0){
      if(r<n-1){
    if(maxquery(0,l-1)>maxquery(r+1,n-1)) t3=(d)maxquery(0,l-1);
    else t3=(d)maxquery(r+1,n-1);
       t1=(d)minquery(--l,++r);
    }

    else{

       t3=(d)maxquery(0,l-1);
    }
    }
    else{

      if(r<n-1){
   
     t3=(d)maxquery(r+1,n-1);
    }

    else{

       t3=0.0;
    }
    }

    d ans = t1 + max((t2 - t1) / 2, t3);
       printf("%.1f\n",ans); 
  }

  return 0;
}


    





      


  

