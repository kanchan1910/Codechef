#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
#define lli long long int 
#define endl '\n'
#define boost  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define pop pop_back
#define mod 1000000007
#define p_q priority_queue
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define maxi max_element
#define mini min_element
#define lcm(a,b) (a*b/__gcd(a,b))
#define set_bits(x) __builtin_popcountll(x)
#define mp make_pair
using namespace std;
lli no_of_divisors(lli n){ 
  lli count = 0; 
  for (lli i = 1; i <= sqrt(n); i++) { 
    if (n % i == 0){ 
    if(n/i==i)
      count=count+1;
    else
      count=count+2;
    }
  }
  return count; 
  } 
lli gcdExtended(lli a, lli b, lli *x, lli *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    lli x1, y1;
    lli gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
lli modInv(lli a, lli m){
    lli x, y;
    lli g = gcdExtended(a, m, &x, &y);
    lli res = (x%m + m) % m;
    return res;
}
lli mpower(lli x, lli y, lli p){
    lli res = 1;
    x = x % p;
    while(y > 0){
        if(y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

lli power(lli x, lli y){
    lli res = 1;
    while (y > 0){
        if (y & 1) res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}

bool isPrime(lli n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    lli p=sqrt(n);
    for(int i=5;i<=p;i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}
bool isVowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
        return true;
    }
    else{
        return false;
    }
}
bool is_upper(char ch){
    if(ch >= 'A'&&ch <= 'Z')
    {
        return true;
    }
    else{
      return false;   
    }
}
bool is_lower(char c){
    if(c >= 'a'&&c <= 'z') 
    {
        return true;
    }
    else 
    {
        return false;
    }
}
//to multiply two numbers with handling mod
lli mul(lli a,lli b){
 return (((a+mod)%mod)*((b+mod)%mod))%mod;
}
//to add two numbers with handling mod
lli add(lli a,lli b){
 return (((a+mod)%mod)+((b+mod)%mod))%mod;
}
int main(){
    boost;
   int t;
    cin>>t;
    while(t--){
  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i=1;i<=n;i++){
      cin>>arr[i];
  }
  int f[n+1];
  f[0]=0;
  f[1]=k;
  for(int i=2;i<=n;i++){
      f[i]=f[i-1]+k;
      int arguments=0;
      unordered_map<int,int>m;
      m[arr[i]]++;
      for(int j=i-1;j>=1;j--){
          m[arr[j]]++;
          if(m[arr[j]]==2){
              arguments+=2;
          }
          else if(m[arr[j]]>2){
              arguments+=1;
          }
          f[i]=min(f[i],f[j-1]+k+arguments);
      }
  }
  cout<<f[n]<<endl;
    }
}
//TC: O(N*N)
//SC: O(N)