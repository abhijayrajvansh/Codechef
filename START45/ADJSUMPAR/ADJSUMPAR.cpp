/*    यो न हृष्यति न द्वेष्टि न शोचति न काङ्क्षति। शुभाशुभपरित्यागी भक्तिमान्यः स मे प्रियः॥
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *    author:   abhijayrajvansh
 *    created:  29.06.2022 21:19:48
**/
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define tatakae() int tests = 1; if (TT) cin >> tests; for (int i = 1; i <= tests; i++) { run_case(i);} 

constexpr char nl = '\n'; 

template<class Fun> class rajvansh
{
    Fun fun_;
public:
    template<class T> 
    explicit rajvansh(T &&fun): 
    fun_(std::forward<T>(fun)) {}

    template<class ...Args> 
    decltype(auto) operator()(Args &&...args) 
    { 
        return fun_(std::ref(*this), std::forward<Args>(args)...); 
    }
};

template<class Fun> 
decltype(auto) y_combinator(Fun &&fun) 
{ 
    return rajvansh<std::decay_t<Fun>>(std::forward<Fun>(fun)); 
}

template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) 
{ 
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename T_container, typename T = typename enable_if<!is_same

<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator<<(ostream &os, const T_container &v) 
{ 
    os << '{'; string sep; 

    for (const T &x : v) 
        os << sep << x, sep = ", "; 

    return os << '}'; 
}

void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) 
{ 
    cerr << ' ' << H; dbg_out(T...); 
}

#ifdef ABHIJAY_DEBUG
#define deb(...) cerr << "["<< #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__);
#else
#define deb(...)
#endif

bool TT = true;


void run_case(int tc){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    for (auto &each : a){
        cin >> each;
    }
    bool ans = true;

    b[0] = 1;
    for(int i = 0; i < n - 1; i++){
        
        if(a[i] == 1){
            if(b[i] == 1){
                b[i+1] = 0;
            }
            else{
                b[i+1] = 1;
            }
        }
        else{
            b[i+1] = b[i];
        }

    }
    // deb(b[n - 1] + b[0])
    // deb(a[n - 1])


    if(((b[n - 1] + b[0]) % 2) == a[n - 1]){
        cout << "YES" << nl;
    }
    else{
        cout << "NO" << nl;
    }
    
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
#ifndef ABHIJAY_DEBUG
    cin.tie(nullptr);
    freopen("debug.err", "w", stderr);
#endif
    tatakae();
}