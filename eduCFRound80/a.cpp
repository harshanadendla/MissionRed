Adilbek was assigned to a special project. For Adilbek it means that he has n days to run a special program and provide its results. But there is a problem: the program needs to run for d days to calculate the results.

Fortunately, Adilbek can optimize the program. If he spends x (x is a non-negative integer) days optimizing the program, he will make the program run in ⌈dx+1⌉ days (⌈a⌉ is the ceiling function: ⌈2.4⌉=3, ⌈2⌉=2). The program cannot be run and optimized simultaneously, so the total number of days he will spend is equal to x+⌈dx+1⌉.

Will Adilbek be able to provide the generated results in no more than n days?

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        int flag=0;
        ll n,d;
        cin>>n>>d;
        if(d<=n) printf("YES\n");
        else
        {
            for(ll i=1;i<n;i++)
            {
                ll k=ceil(((1.0)*d)/(i+1));
                if(n>=i+k)
                {
                    printf("YES\n");
                    flag=1;
                    break;
                }
            }
            if(flag!=1) printf("NO\n");
        }
    }
    return 0;
}
