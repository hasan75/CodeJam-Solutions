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
int n;
int W[N];
int dp[100][6001];
int vis[100][6001];
int cur_test_case;


void reset()
{

	
}


int rec(int pos, int max_weight)
{
	
	if(pos < 0){
		return 0;
	}

	if(vis[pos][max_weight] == cur_test_case) return dp[pos][max_weight];
	vis[pos][max_weight] = cur_test_case;

	int ret = -INF;

	ret = rec(pos - 1, max_weight);
	if(max_weight >= W[pos]) ret = max(ret, rec(pos - 1, min(6 * W[pos], max_weight - W[pos])) + 1);

	return dp[pos][max_weight] = ret;
}


void solve()
{
	sc("%d", &n);
	
	reset();
	int mx_weight = 0;
	for(int i = 0; i < n; i++){
		sc("%d", &W[i]);
		mx_weight = max(mx_weight, W[i]);
	}

	int ans = 1;
	for(int i = 0; i < n; i++){
		int weight = W[i];
		ans = max(ans, rec(i - 1, 6 * weight) + 1);
	}

	

	

	pc("%d\n", ans);

	
	
}


int main()
{
	freopen("sample_input.txt", "r", stdin);
	freopen("sample_output.txt", "w", stdout);
	// freopen("A-large-practice.in", "r", stdin);
	// freopen("A-large-practice.out", "w", stdout);
	
    

    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);
        cur_test_case = Cas;

		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
