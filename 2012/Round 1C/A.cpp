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
bool vis[1000];
bool isExist;

void reset()
{
	
   for(int i = 0; i < n; i++) adj[i].clear(), vis[i] = false;
   isExist = false;
    
}

/*
from problem description, we can infer that graph has no cycle, may be disconnected
corner case:
5
2 2 3
0
1 4
0
1 4
correct output: No

*/

 
void dfs(int u)
{
	if(vis[u]){
		isExist = true;
		return;
	}
	
	vis[u] = true;

	for(int v: adj[u]){
		dfs(v);
	}

}


void solve()
{
	

	sc("%d", &n);
	reset();

	for(int i = 0; i < n; i++){
		int m;
		int v;
		sc("%d", &m);
		for(int j = 0; j < m; j++){
			sc("%d", &v);
			v--;
			adj[i].push_back(v);
		}
	}

	for(int i = 0; i < n; i++){
		isExist = false;
		dfs(i);
		if(isExist) {
			pc("Yes\n");
			return;
		} 
		for(int i = 0; i < n; i++) vis[i] = false;

	}
	pc("No\n");
    
	
}


int main()
{
	// freopen("sample_input.txt", "r", stdin);
	// freopen("sample_output.txt", "w", stdout);
	// freopen("A-small-practice.in", "r", stdin);
	// freopen("A-small-practice.out", "w", stdout);
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	


    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);
        //cur_test_case = Cas;

		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
