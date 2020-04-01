//gfg lo longest subsequence with gcd > 1 sum
    //base entante.....gcd is nthg but prime factors
    //mundu pre lo lpf seive rayali for prime factorisation
    //ippudu entire thing lies in how many times you see a prime as a factor in the array
    //max of this "how many times you see a prime as a factor in the array" is the answer
    //adi ela chestamante.
        //first get its lpf O(1) using seive
        //increment the frequency of this prime in freq[]
        //now remove this factor from the arrey element
        //idi ela ante
            //while(a[i]%p==0) a[i]/=p;
    //ila do this until the element becomes 1...ante....extract all its prime factors and increment their freq
    //whenever the freq[] is updated...ans kooda update...ans=max(ans,freq[p])
    //ila ans becomes the most number of times you see a prime as a factor in the array
    //makes sense....endukante...read 1st point
//coming back to this question....ikkada entante...largest subseq with gcd greater that totalGCD....to obtain it..what is the 
    //minimum number of elements you need to remove
//now first cal totalGCD during input
//imp step: ikkada for every element in array....same paina sum lage...we count frequencies...but without total gcd....
//so..divide each element with totalGCD...and continue same paina process
//see 4 16 64..mamulga gcd 4...and freq lo u find freq[2]=3(lpf kabatti)...now when u divide with gcd(4)...array is 1 4 16...ante...we made the 4-factor disapper
//ippudu freq[2]=2....and further continue
//the ans obtained is the longest subseq with gcd > toalGCD....manaki kavalsindi...minimumnumber of elements to be removed to obtain it
//so print n-ans....if at all ans is still 0 .....daani ardam all elements in the given array are same ani..then print -1 as per qstn

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
const int N=1.5e7+7;
const int M=3e5+5;
const int mod=1e9+7;

int a[M],lpf[N],freq[N];

void pre()
{
	for(int i=0;i<N;i++) lpf[i]=i;

	for(int i=4;i<N;i+=2)
	{
		lpf[i]=2;
	}

	for(int i=3;i<N;i+=2)
	{
		if(lpf[i]==i)
		{
			for(int j=i*i;j<N;j+=i)
			{
				lpf[j]=i;
			}
		}
	}
}

void solve()
{
	pre();

	int n,gcd=0,ans=0;
	cin>>n;

	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		gcd=__gcd(gcd,a[i]);
	}

	for(int i=0;i<n;i++)
	{
		a[i]/=gcd;

		while(a[i]!=1)
		{
			int p=lpf[a[i]];

			while(a[i]%p==0) a[i]/=p;

			freq[p]++;

			ans=max(ans,freq[p]);
		}
	}

	(ans!=0) ? cout<<n-ans : cout<<"-1" ;
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