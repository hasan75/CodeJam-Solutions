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
int P[26];
vector<string>cur_ans, final_ans;
int masks[650], total_comb;
int vis[650][1001];
int cur_test_case;

void reset()
{
    
    cur_ans.clear();
    final_ans.clear();
}

void rec(int pos, int rest_total)
{
    //pc("rec %d %d\n", pos, rest_total);
    if(vis[pos][rest_total] == cur_test_case) return;
    if(rest_total == 1){
        return;
    }
    if(rest_total == 0) {
        if(final_ans.empty() && !cur_ans.empty()){
            final_ans = cur_ans;
        }
        return;
    }
    if(pos == total_comb){
        if(rest_total == 0 ){
            if(final_ans.empty() && !cur_ans.empty()){
                final_ans = cur_ans;
            }
        }

        return;
    }

    int mask = masks[pos];
    vis[pos][rest_total] = cur_test_case;

    
    bool isPossible = true;
    int total_cnt = rest_total;
    for(int i = 0; i < n; i++){
        if((mask & (1<<i))){
            if(P[i] == 0){
                isPossible = false;
                break;
            }
            else{
                total_cnt--;
            }
        }
    }

    if(isPossible && total_cnt > 0){
        int half = (total_cnt / 2) + 1;
        for(int i = 0; i < n; i++){
            if((mask & (1<<i)) && (P[i] - 1) >= half){
                isPossible = false;
                break;
            }
            else if( !(mask & (1<<i)) && P[i] >= half){
                isPossible = false;
                break;
            }
        }
    }

    if(isPossible){
        string str = "";
        for(int i = 0; i < n; i++){
            if((mask & (1<<i))){
                P[i]--;
                rest_total--;
                str += 'A' + i;
            }
        }

        cur_ans.push_back(str);

        for(int j = 0; j < total_comb; j++){
            rec(j, rest_total);
        }

        for(int i = 0; i < n; i++){
            if((mask & (1<<i))){
                P[i]++;
                rest_total++;
            }
        }

        cur_ans.pop_back();

    }

    //for(int j = 0; j < total_comb; j++){
    rec(pos + 1, rest_total);
    //}

}


void solve()
{
    //priority_queue<tuple<int, int>>pq;
    //vector<string>ans;
    reset();
    sc("%d", &n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        sc("%d", &P[i]);
        //pq.push({-P[i], i});
        cnt += P[i];
    } 

    total_comb = 0;
    for(int i = 0; i < n; i++){
        masks[total_comb++] = (1<<i);
        for(int j = i + 1; j < n; j++){
            masks[total_comb++] = ((1<<i) | (1<<j));
        }
    }

    
    rec(0, cnt);

    for(string str: final_ans){
        cout << " " << str;
    }
    cout << endl;
    
    
	
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

		pc("Case #%d:", Cas);
		solve();
    }




    return 0;
}
