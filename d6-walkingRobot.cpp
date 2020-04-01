//if s[i] is 0...elago step cant be retained..so simply check if a can be decremented.
//ledaaa.....if s[i] is 1...if we have bs' remaining.....we can retain that step using b...as a will incremented...if not simply decrement a
//edge case entante....if idx successfully is able to cross the entire array print n
//and s[i] is 1 case lo...onyl go for b if a can be incremented...lekapothe enduku bokka
//AC in 2 gos.....sonthaga vachina idea

/*
	YES PAIN YES GAIN
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

//int pow[N]
const int N=1e5;
const int mod=1e9+7;

void solve()
{
	int n,b,a,a_limit,idx;
	cin>>n>>b>>a;

	a_limit=a;

	int s[n+1];

	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}

	for(idx=1;idx<=n;idx++)
	{
		if(s[idx]==0)
		{
			if(a!=0) a--; 
			else
			{
				if(b!=0) b--;
				else break;
			}
		}
		else
		{
			if(b!=0)
			{
				if(a<a_limit)
				{
					b--;
					a++;
				}
				else a--;
			}
			else
			{
				if(a!=0) a--;
				else break;
			}
		}
		if(a==0 && b==0) break;
	}

	(idx<=n) ? cout<<idx : cout<<n;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif

	clock_t t1,t2;
	t1=clock();

	int t=1;
	//cin>>t;

	while(t--)
	{
		solve();
	}

	#ifndef ONLINE_JUDGE
	t2=clock();
	cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
	#endif

	return 0;
}