/*
    problem link: https://codeforces.com/contest/5/problem/C
    problem rating: 1900
    my rating today: 1072
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define sz(x) x.size()
#define rep(j,a,b) for(int j=a;j<b;j++) 
#define debug(x) cerr << #x <<" = "<<x<<"\n"
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

/*
|^^^^^^^^^^^\||____
| The STFU Truck |||""'|""\__,_
| _____________ l||__|__|__|)
...|(@)@)"""""""**|(@)(@)**|(@)

*/

// --------MATHS OPERATIONS---------

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
ll fact[N], inv[N], invfact[N];
void factInverse() {
    fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
    for (long long i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD);
        invfact[i] = (inv[i] * invfact[i - 1]) % MOD;
    }
}
 
int add(int a, int b) {
    if ((a += b) >= MOD)
        a -= MOD;
    else if (a < 0)
        a += MOD;
    return a;
}
 
ll mul(int x, int y) {
    return (1LL * x * y) % MOD;
}
 
ll nCr(int n, int r) {
    if (r > n)
        return 0;
    return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}

long long pow(long long a, long long b, long long m=MOD) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// --------XXXXXXXXX---------

void yash()
{
    string s;
    cin>>s;
    s=")"+s;
    int n=s.length();
    int maxi=0,cnt=0;
    stack<int> unclosed;
    unclosed.push(0);
    rep(i,1,n)
    {
        if(s[i]=='(')
        {
            unclosed.push(i);
            continue;
        }
        if(s[unclosed.top()]=='(')
        {
            unclosed.pop();
            int l=i-unclosed.top();
            maxi=max(maxi,l);
            continue;
        }
        unclosed.push(i);
    }
    if(!maxi) {cnt=1; goto print;}
    while(unclosed.size()) unclosed.pop();
    unclosed.push(0);
    rep(i,1,n)
    {
        if(s[i]=='(')
        {
            unclosed.push(i);
            continue;
        }
        if(s[unclosed.top()]=='(')
        {
            unclosed.pop();
            int l=i-unclosed.top();
            if(l==maxi) cnt++;
            continue;
        }
        unclosed.push(i);
    }
    print:
    cout<<maxi<<" "<<cnt;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    //factInverse();
    while(t--){
        yash();
    }
}
