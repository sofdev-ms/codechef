// https://www.codechef.com/problems/DEADEND

#include<bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while( t-- )
    {
        ll n;
        cin >> n;
        vector < ll > v;
        for(int i = 0; i  < n ; i ++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin() , v.end());
        bool a[n] ={0};
        ll prev = -1;
        ll ans = 0;
        for(int i = 0 ; i< n ; i ++)
        {
            if(a[i])
            {
                if(i + 1 < n && v[i + 1] == v[i] + 1)
                {
                    a[i + 1] = true;
                }
            }
            else if(i + 1 < n && v[i + 1]!= v[i] + 1)
            {
                prev = v[i] + 1;
                ans ++;
                a[i] = true;
                if(prev + 1 == v[i + 1])
                a[i + 1] = true;
            }
            else if( i + 1 <  n)
            {
                a[i] = true;
                a[i + 1] = true;
            }
            else
            {
                ans ++;
            }
        }
        cout << ans << endl;
    }
}
