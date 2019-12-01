//https://www.codechef.com/problems/APARTS

#include<bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while( t-- )
    {
        ll n , m ;
        cin >> n >> m;
        ll a[n][m];
        bool ans[n][m];
        ll mx[n][m];

        for(int i = 0 ; i  < n ;i ++)
        {
            for(int j = 0 ; j  < m ; j ++)
            {
                cin >> a[i][j];
                ans[i][j] = 1;
                mx[i][j] = a[i][j];
            }
        }

        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                if(j > 0 && i + 1 < n && mx[i][j] > a[i + 1][j - 1])
                {
                    ans[i + 1][j - 1] = 0;
                    mx[i + 1][j - 1] = max(mx[i + 1][j - 1] , mx[i][j]);
                }
                if(i + 1 < n && mx[i][j] > a[i + 1][j])
                {
                    ans[i + 1][j] = 0;
                    mx[i + 1][j] = max(mx[i + 1][j] , mx[i][j]);
                }
                if( j + 1 < m && i + 1 < n && mx[i][j] > a[i + 1][j + 1])
                {
                    ans[i + 1][j + 1] = 0;
                    mx[i + 1][j + 1] = max(mx[i + 1][j + 1] , mx[i][j]);
                }
                cout << ans[i][j];
            }
            cout << endl;
        }

    }
}
