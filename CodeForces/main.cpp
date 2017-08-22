///
//find the divisors of every number
//for every number we have it's common divisors
//to be sure that it is the greatest common divisor we will exclude all the other greater common divisors
///
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll power(ll a,ll b,ll mod)
{
	if(b==0)
		return 1ll;
	ll ans=1;
	if(b%2)
		return ans=(power(a,b-1,mod)*a)%mod;
	ans=(power(a,b/2,mod)%mod);
	return ((ans*ans)%mod);
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int>div(1000005,0);
    for(ll i=0; i<n; i++)
    {
        ll a;
        scanf("%lld",&a);
        div[a]++;
        for(ll j=2; j*j<=a; j++)
        {
            if(a%j==0)
            {
                int x=j;
                int y=a/j;
                if(x!=y)
                    div[y]++;
                div[x]++;
            }
        }
    }

    ll ans=0;
    vector<ll>tmp(1000005,0);
    for(ll i=1000000; i>=2; i--)
    {
        ll divcnt=div[i];
        if(divcnt==0)
            continue;
        divcnt=divcnt*power(2,divcnt-1,1e9+7);
        divcnt%=ll(1e9+7);
        ll curr=divcnt;
        for(ll j=i+i; j<=1000000; j+=i)
        {
            curr-=tmp[j];
            curr%=ll(1e9+7);
            curr+=ll(1e9+7);
            curr%=ll(1e9+7);
        }
        tmp[i]=curr;
        ans+=(curr*i)%ll(1e9+7);
        ans%=ll(1e9+7);
    }
    printf("%lld\n",ans);
    return 0;
}
