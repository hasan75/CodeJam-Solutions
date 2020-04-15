#include <bits/stdc++.h>
using namespace std;

#define N 100
#define M 100002
#define sc scanf
#define pc printf
#define ll long long
#define eps 1e-9
#define INF 100000000000000

int T;
int n, q;
double horse_max_dis[N], horse_speed[N];
double dis[N][N], Time[N][N];
bool vis[N][N];

void reset()
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) Time[i][j] = 0, vis[i][i] = true;
			else Time[i][j] = INF, vis[i][j] = false;
	
		}
	}
}

double dfs(int start, int fin)
{
	if(start == fin) return 0;

	if(vis[start][fin]) return Time[start][fin];
	double cur_speed = horse_speed[start];
	double mn_time = INF;
	vis[start][fin] = true;
	
	if(fabs(cur_speed) > eps){
		horse_speed[start] = 0;
		
		if(fabs(dis[start][fin] + 1) < eps || dis[start][fin] > horse_max_dis[start]) {}
		else{
			double cur_t = dis[start][fin] / cur_speed;
			if(cur_t < mn_time) mn_time = cur_t;
		}
		for(int k = 0; k < n; k++){
			if(k == start || fabs(dis[start][k] + 1) < eps) continue;
			else{
				if(fabs(dis[start][k] - horse_max_dis[start]) < eps || dis[start][k] < horse_max_dis[start]){
					double cur_time = dis[start][k] / cur_speed + dfs(k, fin);
					if(cur_time < mn_time) mn_time = cur_time;
				}
			}
			

		}
		horse_speed[start] = cur_speed;
	}


	
	

	return Time[start][fin] = mn_time;
	
	
	
}


void solve()
{

	sc("%d %d", &n, &q);
	reset();

	for(int i = 0 ;i < n; i++){
		sc("%lf%lf", &horse_max_dis[i], &horse_speed[i]);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sc("%lf", &dis[i][j]);
		}
	}



	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) {dis[i][j] = 0; continue;}
			for(int k = 0; k < n; k++){
				if(dis[i][k] > 0 && dis[k][j] > 0){
					if( fabs( dis[i][j] + 1) < eps ) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
					else if(dis[i][j] > dis[i][k] + dis[k][j]){
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
				
			}
		}
	}

	

	int u, v;
	for(int i = 0; i < q; i++){
		sc("%d%d", &u, &v);
		u--;
		v--;
		double ans = dfs(u,v);
		if(i == q - 1) pc("%0.09lf\n", ans);
		else pc("%0.09lf ", ans);
	}
	

}


int main()
{
	// freopen("sample_input.txt", "r", stdin);
	// freopen("sample_output.txt", "w", stdout);
	freopen("C-small-practice.in", "r", stdin);
	freopen("C-small-practice.out", "w", stdout);
	
    //init();

    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);
        

		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
