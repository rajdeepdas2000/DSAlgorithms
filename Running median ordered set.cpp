#include<bits/stdc++.h>
#define Imposter ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
using namespace __gnu_pbds;
#define Ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;
#define f(n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define endl "\n"
#define vll vector<ll>
#define vlll vector<vll>
#define all(x) x.begin(),x.end()
ll power(ll x, ll y, ll p) {
    ll res = 1;    x = x % p;
    while(y > 0) {
        if(y & 1) res = (res*x) % p;
        y = y>>1;    x = (x*x) % p;
    } return res;
}
const int N=100005;
bool prime[N]; 
void SieveOfEratosthenes() 
{ 
    
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=N; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=N; i += p) 
                prime[i] = false; 
        } 
    } 
}
void findMedian(int arr[], int n, 
                int k) 
{ 
  
    Ordered_set s; 
    ll sum=0;
 
    for (int i = 0; i < k; i++) 
    {
        s.insert(arr[i]); 
        sum+=arr[i];
    }
  
    ll c=0;
    int flag=1;
    if(k&1)
    flag=0;
        ll ans = *s.find_by_order(k / 2- flag); 
        ll avg=sum/k;
        //cout<<avg<<" "<<ans<<endl;
        if((prime[avg] and prime[ans]) or (!prime[avg] and !prime[ans]))
         {
             if(avg>=ans)
             c++;
         }
  
        for (int i = 0; i < n - k; i++) { 
  
            s.erase(s.find_by_order( 
                s.order_of_key( 
                    arr[i]))); 
  
            s.insert(arr[i + k]); 
  
            ans = *s.find_by_order(k / 2 -flag); 
            sum+=arr[i+k]-arr[i];
            avg=sum/k;
            //cout<<avg<<" "<<ans<<endl;
            if((prime[avg] and prime[ans]) or (!prime[avg] and !prime[ans]))
         {
             if(avg>=ans)
             c++;
         }
        } 
        cout <<c<< endl;
} 
inline void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    input(a,n);
    findMedian(a, n, k); 
} 

int main()
{
    Imposter
    
    int t=1;
    cin>>t;
    SieveOfEratosthenes();
    while(t--)
    {
        solve();

    }
    return 0;
}
