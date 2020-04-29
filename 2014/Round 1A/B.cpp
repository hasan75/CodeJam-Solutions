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
vector<int>adj[1000];

void reset()
{
	for(int i = 0; i < n; i++) adj[i].clear();
}

int dfs(int u, int w)
{
	//pc("cur %d\n", u);
	if(w == -1){
		if(adj[u].size() < 2){
			//pc("fir1\n");
			return 1;
		}
		else{
			//pc("sec1\n");
			int ret1 = -1, ret2 = -1;
			for(int v : adj[u]){
				if(v != w) {
					int cur = dfs(v, u);
					if(cur > ret1){
						ret2 = ret1;
						ret1 = cur;
					}
					else if(cur > ret2){
						ret2 = cur;
					}
				}
			}

			assert(ret1 >= 0 && ret2 >= 0);
			return ret1 + ret2 + 1;
		}
	}
	else{
		if(adj[u].size() - 1 < 2){
			//pc("fir2\n");
			return 1;
		}
		else{
			//pc("sec2\n");
			int ret1 = -1, ret2 = -1;
			for(int v : adj[u]){
				if(v != w) {
					int cur = dfs(v, u);
					if(cur > ret1){
						ret2 = ret1;
						ret1 = cur;
					}
					else if(cur > ret2){
						ret2 = cur;
					}
				}
			}

			assert(ret1 >= 0 && ret2 >= 0);
			return ret1 + ret2 + 1;
		}
	}
	
}


void solve()
{
	

	sc("%d", &n);
	reset();

	for(int i = 0; i < n - 1; i++){
		int u,v;
		sc("%d%d", &u, &v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if(n == 1){
		pc("0\n");
		return;
	}

	int ans = n;
	
	for(int root = 0; root < n; root++){
		int max_size = dfs(root, -1);
		//pc("\n%d %d\n\n", root, max_size);
		ans = min(ans, n - max_size);
	}
	pc("%d\n", ans);
    
	
}


int main()
{
	// freopen("sample_input.txt", "r", stdin);
	// freopen("sample_output.txt", "w", stdout);
	// freopen("B-small-practice.in", "r", stdin);
	// freopen("B-small-practice.out", "w", stdout);
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	


    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);
        //cur_test_case = Cas;

		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
