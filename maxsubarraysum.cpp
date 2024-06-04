#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    multiset<int> s;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    int count = 0;
    auto itr = s.begin();
    while (count < n - (b - a) - 1)
    {
        count++;
        itr++;
    }
    int sum = 0;
    while (itr != s.end())
    {
        sum += *itr;
        itr++;
    }
    cout << sum << endl;

    return 0;
}
