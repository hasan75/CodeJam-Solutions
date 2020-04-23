#include <bits/stdc++.h>
using namespace std;
 
#define N 1000002
#define M 100002
#define sc scanf
#define pc printf
#define ll long long
 
int T;
int c,d,v;
int denominations[101];
 
void reset()
{
	
	
}
 

void solve()
{
	set<int>existing_vals;
	sc("%d%d%d", &c, &d,&v);
	for(int val = 1; val <= v; val++) existing_vals.insert(val);
	for(int i = 0; i < d; i++){
		sc("%d", &denominations[i]);
	}
	for(int mask = 1; mask < (1<<d); mask++){
		int value = 0;
		for(int j = 0; j < d; j++){
			if((mask & (1<<j))){
				value += denominations[j];
			}
		}
		if(value <= v && existing_vals.find(value) != existing_vals.end()){
			existing_vals.erase(value);
		}
	}

	int ans = 0;
	while(!existing_vals.empty()){
		int cur_val = *existing_vals.begin();
		existing_vals.erase(cur_val);
		denominations[d++] = cur_val;
		ans++;
		for(int mask = 1; mask < (1<<d); mask++){
			if( (mask & (1 << (d-1))) ){
				int value = 0;
				for(int j = 0; j < d; j++){
					if((mask & (1<<j))){
						value += denominations[j];
					}
				}
				if(value <= v && existing_vals.find(value) != existing_vals.end()){
					existing_vals.erase(value);
				}
			}
		}
	}

	pc("%d\n", ans );

}
 
 
int main()
{
 
	// freopen("sample_input.txt", "r", stdin);
	// freopen("sample_output.txt", "w", stdout);
	freopen("C-small-practice.in", "r", stdin);
	freopen("C-small-practice.out", "w", stdout);
	
	//cout << solve2(2, 3, 3, 0);
    sc("%d", &T);
 
 
    for(int Cas = 1; Cas <= T; Cas++){
		//ll ans = 0;
		pc("Case #%d: ", Cas);
        solve();
    }
 
 
 
 
    return 0;
}