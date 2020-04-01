
//mudu priority queue implement chesa...adi tuss andi...coz...i pushed into pq first checking f and then s...(after swapping)....but missed that.....
//anni bills will not necessarily fit to each other.....MDOLLS type lo avutundemo anukunna.....no...simple ga just maintained max(a,b) in them....AC
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
	int max_a=0,max_b=0;

	char type;
	int n,a,b;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>type;

		if(type=='+')
		{
			cin>>a>>b;
			if(a>b)
			{
				int t=a;
				a=b;
				b=t;
			}

			max_a=max(max_a,a);
			max_b=max(max_b,b);
		}
		else
		{
			cin>>a>>b;
			if(a>b)
			{
				int t=a;
				a=b;
				b=t;
			}

			(max_a<=a && max_b<=b) ? cout<<"YES\n" : cout<<"NO\n" ;
		}
	}
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