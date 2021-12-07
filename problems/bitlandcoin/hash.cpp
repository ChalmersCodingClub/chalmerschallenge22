#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int inf = 0x3f3f3f3f;
const ll linf = 1234567890123456789;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << (x) << endl
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int i = (a); i < int(b); i++)
#define trav(x, a) for(auto& x : a)
typedef unsigned long long ull; 

vi tolist(ull x){
    vi r(64);
    for(int i = 0; i < 64; i++){
        r[63-i] = x&1;
        x >>= 1;
    }
    return r;
}

ull toint(vi x){
    ull r = 0;
    for(int i = 0; i < 64; i++){
        r <<= 1;
        r |= x[i];
    }
    return r;
}

ull Hash(ull x){
    vi X = tolist(x);
    for(int i = 0; i < 512; i++){
        int y = 4*X[i%64] + 2*X[(i+2)%64] + X[(i+10)%64];
        X[i%64] = (y == 0 || y == 1 || y == 4 || y == 5 || y == 7);
    }
    x = toint(X);

    for(int i = 0; i < 32; i++){
        X = tolist(x);
        reverse(all(X));
        __int128_t tmp = (__int128_t)x+toint(X);
        tmp ^= 12157665459056928801ull;
        if(tmp >= (((__int128_t)1)<<64)) tmp >>= 1;
        x = (ull)tmp;
    }

    return x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cout << Hash(12345678901234567890) << endl;
}
