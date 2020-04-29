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
int n, m;
char tiles[50][51];


void reset()
{
	
}

bool check(int row, int col)
{
	return tiles[row][col] == '#' && tiles[row][col+1] == '#' &&
	tiles[row+1][col] == '#' && tiles[row+1][col+1] == '#';
}

void solve()
{
	

	sc("%d%d", &n, &m);
	reset();
	for(int i = 0; i < n; i++) sc("%s", tiles[i]);

	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < m - 1; j++){
			if(check(i, j)){
				int row = i;
				int col = j;
				//pc("%d %d\n", i ,j);

				tiles[row][col] = '/';
				tiles[row][col+1] = '\\';
				tiles[row+1][col] = '\\';
	 			tiles[row+1][col+1] = '/';
			}
			//for(int i = 0; i < n; i++) pc("%s\n", tiles[i]);
		}
	}

	bool is_possible = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(tiles[i][j] == '#'){
				pc("Impossible\n");
				return;
			}
		}
	}

	for(int i = 0; i < n; i++) pc("%s\n", tiles[i]);
	
	
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

		pc("Case #%d:\n", Cas);
		solve();
    }




    return 0;
}
