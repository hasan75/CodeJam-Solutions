#include <bits/stdc++.h>
using namespace std;
 
#define N 1000002
#define M 100002
#define sc scanf
#define pc printf
#define ll long long
 
int T;
int n,m;
 
void reset()
{
	
	
}
 
bool check(vector<int>temp)
{
	int rank = 0;
	for(int cell : temp){
		if(cell < rank) return false;
		else rank = cell;
	}
	return true;
}
void print(vector<int>vec)
{
	for(int val : vec){
		pc("%d ", val);
	}
	pc("\n");
}
 
void solve()
{
	
	
	sc("%d%d", &n, &m);
	// if(Map.find({n,m}) != Map.end()){
	// 	vector<pair<int,int>>final_ans = Map[{n,m}];
	// 	pc("%d\n", (int)final_ans.size());
	// 	for(pair<int,int>order: final_ans){
	// 		pc("%d %d\n", order.first, order.second);
	// 	}
	// 	return;
	// }

	reset();


	vector<int>src, des;
	int ind = 0;
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			src.push_back(i);
		}
	}

	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			des.push_back(i);
		}
	}

	//print(src);
	//print(des);
	

	map<vector<int>, int>dis;
	map<int, int>par;
	map<int, pair<int,int>>ops;
	map<int, vector<int>>vec_save;
	int index = 0;
	queue<int>qu;

	qu.push(0);
	par[0] = -1;
	ops[0] = {0,0};
	vec_save[0] = src; 
	

	int final_index = -1;

	//int total_cnt = 4;

	while(!qu.empty() ){
		//pc("yes\n");
		int par_index = qu.front();
		qu.pop();
		vector<int>par_sol = vec_save[par_index];
		//pc("parent\n");
		//print(par_sol);

		//total_cnt--;
		for(int j = 1; j < n * m; j++){
			
			for(int k = 1; k + j <= n *m; k++){
				vector<int>temp_vec;
				for(int l = j; l < j + k; l++) temp_vec.push_back(par_sol[l]);
				for(int l = 0; l < j; l++) temp_vec.push_back(par_sol[l]);
				for(int l = j + k; l < par_sol.size(); l++) temp_vec.push_back(par_sol[l]);

				//pc("child %d %d\n", j ,k);
				//print(temp_vec);

				if(dis.find(temp_vec) == dis.end()){
					index++;
					par[index] = par_index;
					ops[index] = {j, k};

					if(check(temp_vec)){
						final_index = index;
						break;
					}

					vec_save[index] = temp_vec;
					dis[temp_vec] = index;
					qu.push(index);
				}
			}
			if(final_index != -1) break;

			
		}

		if(final_index != -1) break;
	}

	//pc("final id %d\n", final_index);
	
	vector<pair<int,int>>temp_ans;
	while(par[final_index] != -1){
		temp_ans.push_back(ops[final_index]);
		final_index = par[final_index];
	}

	reverse(temp_ans.begin(), temp_ans.end());

	//Map[{n,m}] = temp_ans;

	pc("%d\n", (int)temp_ans.size());
	for(pair<int,int>pi : temp_ans){
		pc("%d %d\n", pi.first, pi.second);
	}

	
	
 
}
 
 
int main()
{
 
	freopen("sample_input.txt", "r", stdin);
	freopen("sample_output.txt", "w", stdout);
	
	//cout << solve2(2, 3, 3, 0);
    sc("%d", &T);
 
 
    for(int Cas = 1; Cas <= T; Cas++){
		//ll ans = 0;
		pc("Case #%d: ", Cas);
        solve();
    }
 
 
 
 
    return 0;
}