#include <bits/stdc++.h>
using namespace std;

#define N 100001
#define M 100002
#define sc scanf
#define pc printf
#define ll long long
#define eps 1e-9
#define INF 1000
#define mp make_pair

int T;
int n, m, w;
// pos, Y cnt, mask

void reset()
{
    
    
}

ll Abs(ll val)
{
    if(val < 0) return -val;
    return val;
}


void solve()
{
    
    sc("%d%d%d", &n, &m, &w);
    if(m % w == 0){
        pc("%d\n", (m / w + w - 1) + (n-1) * (m / w) );
    }
    else{
        pc("%d\n", (m / w + w) + (n-1) * (m / w));
    }
	
}


int main()
{
	// freopen("sample_input.txt", "r", stdin);
	// freopen("sample_output.txt", "w", stdout);
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	

    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);


		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
