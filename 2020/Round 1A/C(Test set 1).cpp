#include <bits/stdc++.h>
using namespace std;

#define N 100002
#define M 100002
#define sc scanf
#define pc printf
#define ll long long

int T;
int n, m;
ll cur_grid[N];
set<int>rows[N], cols[N], cur_cells;

void reset()
{
	for(int i = 0 ;i  < n; i++) rows[i].clear();
	for(int j = 0; j < m; j++) cols[j].clear();
	cur_cells.clear();
}

ll solve()
{
	sc("%d%d", &n, &m);
	reset();
	ll ans = 0LL;
	
	ll grid_sum = 0LL;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ll val;
			sc("%lld", &val);
			rows[i].insert(j);
			cols[j].insert(i);
			cur_cells.insert(i * m + j);
			cur_grid[i * m + j] = val;
			grid_sum += val;
		}
	}

	bool is_continue = true;
	set<int>::iterator it;

	while(is_continue && !cur_cells.empty()){
		ans += grid_sum;
		vector<int>deleted_cells;

		for(int cell: cur_cells){
			int row = cell / m;
			int col = cell % m;
			// up down left right
			ll neighbors[4] = {0};
			int neighbors_cell[4] = {-1};
			int neighbors_cnt = 0;
			ll neighbors_sum = 0LL;

			// up
			if(*cols[col].begin() < row){
				it = cols[col].lower_bound(row);
				it--;
				int up_row = (*it);
				neighbors_sum += cur_grid[up_row * m + col];
				neighbors_cnt++;
			}

			// down
			it = cols[col].upper_bound(row);
			if(it != cols[col].end()){
				int down_row = (*it);
				neighbors_sum += cur_grid[down_row * m + col];
				neighbors_cnt++;
			}

			// left
			if(*rows[row].begin() < col){
				it = rows[row].lower_bound(col);
				it--;
				int left_col = (*it);
				neighbors_sum += cur_grid[row * m + left_col];
				neighbors_cnt++;
			}

			// right
			it = rows[row].upper_bound(col);
			if(it != rows[row].end()){
				int right_col = (*it);
				neighbors_sum += cur_grid[row * m + right_col];
				neighbors_cnt++;
			}

			if(neighbors_cnt > 0 && cur_grid[row * m + col] * neighbors_cnt < neighbors_sum){
				deleted_cells.push_back(row * m + col);
				grid_sum -= cur_grid[row * m + col];
			}

		}

		if(!deleted_cells.empty()){
			for(int cell: deleted_cells){
				int row = cell / m;
				int col = cell % m;

				it = rows[row].find(col);
				if(it != rows[row].end()) rows[row].erase(col);

				it = cols[col].find(row);
				if(it != cols[col].end()) cols[col].erase(row);

				cur_cells.erase(cell);
			}
		}
		else{
			break;
		}
	}
	
	return ans;
}


int main()
{
	//freopen("sample_input.txt", "r", stdin);
	//freopen("sample_output.txt", "w", stdout);
	

    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
		//ll ans = 0;
        ll ans = solve();

		pc("Case #%d: %lld\n", Cas, ans);
    }




    return 0;
}
