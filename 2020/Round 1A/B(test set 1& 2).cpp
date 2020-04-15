#include <bits/stdc++.h>
using namespace std;

#define N 100002
#define M 100002
#define sc scanf
#define pc printf
#define ll long long

int T;
ll sum;

void reset()
{
}

void solve(int Case)
{
	sc("%lld", &sum);
	reset();
	pc("Case #%d:\n", Case);

	if(sum == 1){
		pc("1 1\n");
	}
	else if(sum == 2){
		pc("1 1\n2 1\n");
	}
	else{
		pc("1 1\n");
		sum--;
		int n = 1;
		int cur_row = 1;
		while(true){
			ll now = ( 1LL * n * (n + 1) ) / 2;
			if(now <= sum){
				cur_row = n;
			}
			else break;
			n++;

		}

		ll cur = 1;
		for(int i = 2; i <= cur_row + 1; i++){
			pc("%d %d\n", i, i - 1);
			sum -= cur;
			cur++;
		}

		while(cur_row + 1 >= 2 && sum > 0){
			pc("%d %d\n", cur_row + 1, cur_row + 1);
			sum--;
			cur_row--;
		}
	}
	
}


int main()
{
	//freopen("sample_input.txt", "r", stdin);
	//freopen("sample_output.txt", "w", stdout);
	

    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
		//ll ans = 0;
        solve(Cas);

		//pc("Case #%d: %lld\n", Cas, ans);
    }




    return 0;
}
