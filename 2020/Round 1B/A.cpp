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
queue<pair<int,int >>qu;
//map<pair<ll,ll>, int>Map;
int dirx[] = {0,0, 1, -1}, diry[] = {1,-1,0,0};
pair<ll,ll>coordinates[4*100003];
int par[4*100003];
ll Pow[32];
char ans[100003];
// N S E W


void reset()
{
    while(!qu.empty()) qu.pop();
    //Map.clear();
    
}

ll Abs(ll val)
{
    if(val < 0) return -val;
    return val;
}

void solve()
{
    ll X, Y;
	
    sc("%lld%lld", &X, &Y);

    if( Abs(X + Y)  % 2 == 0){
        pc("IMPOSSIBLE\n");
        return;
    }
	
	reset();
	
    int cnt = 1;
	qu.push({1, -1});
    //Map[{0,0}] = cnt;

    coordinates[cnt] = {0,0};
    par[cnt] = -1;

    int final_ind = -1;
    int total_iteration = 10000;

    while(!qu.empty() && total_iteration > 0){
        pair<int, int>u = qu.front();
        int parent_ind = u.first; 
        int parent_step = u.second;
        qu.pop();

        if(parent_step == 31) continue;
        
        total_iteration--;

        pair<ll, ll>par_co = coordinates[parent_ind];
        //pc("par %lld %lld\n",par_co.first, par_co.second);
        //pc("next_step %lld\n", Pow[parent_step + 1]);

        for(int d = 0; d < 4; d++){
            ll vx = par_co.first + Pow[parent_step + 1] * dirx[d];
            ll vy = par_co.second + Pow[parent_step + 1] * diry[d];
            //pc("child %lld %lld\n", vx, vy);

            //if(Map.find({vx, vy}) == Map.end()){
               // Map[{vx, vy}] = ++cnt;
            coordinates[++cnt] = {vx, vy};
            par[cnt] = parent_ind;
            if(vx == X && vy == Y){
                //pc("yes\n");
                final_ind = cnt;
                break;
            }
            qu.push({cnt, (parent_step + 1)});
            //}

            
        }
        //pc("\n");
        if(final_ind != -1) break;

    }

    if(final_ind == -1){
        pc("IMPOSSIBLE\n");
    }
    else{
        
        int ans_ind = 0;
        while(par[final_ind] != -1){
            pair<ll, ll> cur = coordinates[final_ind];
            pair<ll, ll> par_cur = coordinates[par[final_ind]];

            if(cur.first == par_cur.first){
                if(par_cur.second < cur.second) ans[ans_ind++] = 'N';
                else ans[ans_ind++] = 'S';
            }
            else if(cur.second == par_cur.second){
                if(par_cur.first < cur.first) ans[ans_ind++] = 'E';
                else ans[ans_ind++] = 'W';
            }

            final_ind = par[final_ind];
        }
        ans[ans_ind] = '\0';
        
        for(int i = 0; i < ans_ind / 2; i++){
            swap(ans[i], ans[ans_ind - i - 1]);
        }

        pc("%s\n", ans);

    }


	
	
}


int main()
{
	freopen("sample_input.txt", "r", stdin);
	freopen("sample_output.txt", "w", stdout);
	// freopen("A-large-practice.in", "r", stdin);
	// freopen("A-large-practice.out", "w", stdout);
	
    Pow[0] = 1;
    for(int i = 1; i <= 31; i++){
        Pow[i] = Pow[i-1] * 2;
    }

    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);


		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
