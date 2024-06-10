#include <bits/stdc++.h>
using namespace std;
#define ll long long
 int main() {
    ll n, a, b;
    cin >> n >> a >> b;
     vector<ll> psum(n+1,0);
    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        psum[i] = psum[i-1] + x;
    }

    ll mxsum=*max_element(psum.begin()+ a , psum.begin()+ (b+1));
    ll i=1;
    while(a!=b+1){

        if((a+i)!=n+1){
        mxsum=max(mxsum,psum[a+i]-psum[i]);
        i++;
        }
        else{
            a++;
            i=1;
        }
    }
    cout<<mxsum<<endl;
    return 0;
}


    

    


    



    




