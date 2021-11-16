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

int n;
vi a;

vvi dp_n3_iter_vec;
int dp_n3_iter(){
    for(int i = 0; i < n; i++) a[i]++;
    dp_n3_iter_vec = vvi(n+1, vi(n+1));

    int ans = 0;
    for(int i = 0; i <= n; i++){
        dp_n3_iter_vec[i][n] = inf;
        dp_n3_iter_vec[0][i] = -inf;
    }
    for(int answer = 1; answer <= n; answer++){
        for(int pos = n-1; pos >= 0; pos--){
            int s = 0;
            int r = dp_n3_iter_vec[answer][pos+1] - a[pos];
            for(int i = 0; i < min(n-pos, answer); i++){
                s += a[i+pos];
                if(a[i+pos] >= a[pos] && i > 0) break; // optional pruning
                if(s-a[pos] >= r) break; // optional pruning
                r = min(r, s + max(dp_n3_iter_vec[answer-i-1][pos+i+1], -a[pos]));
            }
            dp_n3_iter_vec[answer][pos] = r;
        }
        if(dp_n3_iter_vec[answer][0] <= 0) ans = answer;
        else break;
    }

    for(int i = 0; i < n; i++) a[i]--;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	a = vi(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = dp_n3_iter();
	cout << ans << "\n";
}
