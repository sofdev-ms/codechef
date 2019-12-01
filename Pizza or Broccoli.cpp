// https://www.codechef.com/problems/PIBRO

#include<bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while( t-- )
    {
        ll n , k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector < ll > sum;
        vector < int > start;
        int i = 0;
        int index[n];
        int size = 0;
        ll ans = 0;
        while(i < n )
        {
            char c = s[i];
            ll count = 0 ;
            start.push_back(i);
            while( i < n && s[i] == c)
            {
                index[i] = size;
                count ++;
                i++;
            }
            if(c == '0')
            sum.push_back(-1 * count);
            else
            {
                sum.push_back(count);
                ans = max(ans , count);
            }
            size ++;
        }

        i = 0 ;

        // int m = sum.size();
        // for(int i = 0; i < m ; i++ )
        // {
        //     cout << sum[i] << " " << start[i] <<endl;
        // }
        while( i < n)
        {
            if(s[i] == '0')
            {
                ll t1 = 0;
                if( i > 0 && s[i - 1] == '1')
                {
                    t1 += sum[index[ i - 1]];
                }

                if(i + k - 1 < n && s[ i + k - 1] == '0')
                {
                    if( i + k < n && s[i + k] == '1')
                    {
                        t1 += sum[index[ i + k]];
                    }
                    t1 += k;
                }
                else if( i + k - 1 < n)
                {
                    t1 += k;
                    t1 += sum[index[ i + k - 1]];
                    t1 -= i + k - start[index[ i + k - 1]];
                }
                else
                {
                    t1 += n - i;
                }
                ans = max(ans , t1);
            }

            i++;

        }
        cout << ans << endl;


    }
}
