#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define pb push_back
#define For(i, a, n) for (int i = a; i < n; i++)
#define all(x) ((x).begin(), (x).end())
#define si set<int>
#define msi multiset<int,int>
 
void solve()
{
    int n,a,b;
    cin >> n >> a >> b;
    vi v(n+1);
    For(i,1,n+1)
    {
        cin >> v[i];
    }
    vi pre(n+1,0);
    pre[0]=0;
    For(i,1,n+1) pre[i]=pre[i-1]+v[i];
    deque<int> dq;
    vi add(n+1,0);
    int sum=0;
    dq.push_back(pre[a]);
    for(int i=a+1;i<=b;i++)
    {
        while(!(dq.empty()) && dq.back()<pre[i]) dq.pop_back();
        dq.push_back(pre[i]);
    }
    // add[a]=max(0ll,sum);
    add[a]=dq.front();
    for(int i=b+1;i<=n;i++)
    {
        if(dq.front() == pre[i-b+a-1]) dq.pop_front();
        while(!(dq.empty()) && dq.back()<pre[i]) dq.pop_back();
        dq.push_back(pre[i]);
        // sum += v[i];
        // sum -= v[i-b+a];
        // add[i-b+a]=max(0ll,sum);
        add[i-b+a]=dq.front();
    }
    // for(int i=n-b+a+1;i<=n;i++)
    // {
    //     // sum -= v[i];
    //     // add[i] = max(0ll,sum);
    //     if(dq.front() == pre[i]) dq.pop_front();
    //     if(!(dq.empty())) add[i]=dq.front();
    //     else add[i]=pre[i];
    // }
    int m = pre[n];
    for(int i=n;i>=n-b+a+1;i--)
    {
        m=max(m,pre[i]);
        add[i]=m;
    }
    // cout << sum;
    int ans=pre[a];
    for(int i=0;(i+a)<=n;i++)
    {
        // cout << ans << "\n";
        ans = max(ans,add[i+a]-pre[i]);
    }
    cout << ans;
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}