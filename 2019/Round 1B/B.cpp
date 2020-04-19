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

int T, W;
int n;
char result[15];
char verdicts[][15] = {"CORRECT",  "WRONG_ANSWER", "TOO_SMALL", "TOO_BIG"};

void reset()
{

	
}



bool solve()
{
	int n;
	int day[7] = {0};
    
	for(int i = 1; i <= W; i++){
		switch (i)
		{
		case 1:
			pc("%d\n", i);
			fflush(stdout);
			sc("%d", &n);
			day[i] = n;
			break;
		case 2:
			pc("%d\n", i);
			fflush(stdout);
			sc("%d", &n);
			day[i] = n;
			break;

		case 3:
			pc("%d\n", i);
			fflush(stdout);
			sc("%d", &n);
			day[i] = n;
			break;

		case 4:
			pc("%d\n", i);
			fflush(stdout);
			sc("%d", &n);
			day[i] = n;
			break;

		case 5:
			pc("%d\n", i);
			fflush(stdout);
			sc("%d", &n);
			day[i] = n;
			break;

		case 6:
			pc("%d\n", i);
			fflush(stdout);
			sc("%d", &n);
			day[i] = n;
			break;
		
		default:
			break;
		}
	}

	int cnt[7] = {0};

	for(int cnt_one = 0; cnt_one <= day[1]; cnt_one++){
		cnt[1] = cnt_one;
		bool is = true;
		for(int i = 2; i <= 6; i++){
			if(i == 2){
				int ret = (day[i] - day[i-1] - cnt[1] * 2);
				if(ret >= 0 ){
					cnt[i] = ret;
				}
				else{
					is = false;
					break;
				}
			}
			else if(i == 3){
				int ret = (day[i] - day[i-1] - cnt[1] * 4);
				if( ret >= 0){
					cnt[i] = ret;
				}
				else{
					is = false;
					break;
				}
			}
			else if(i == 4){
				int ret = (day[i] - day[i-1] - cnt[1] * 8 - cnt[2] * 2);
				if( ret >= 0 ){
					cnt[i] = ret;
				}
				else{
					is = false;
					break;
				}
			}
			else if(i == 5){
				int ret = (day[i] - day[i-1] - cnt[1] * 16);
				if( ret >= 0 ){
					cnt[i] = ret;
				}
				else{
					is = false;
					break;
				}
			}
			else{
				int ret = (day[i] - day[i-1] - cnt[1] * 32 - cnt[2] * 4 - cnt[3] * 2);
				if( ret >= 0){
					cnt[i] = ret;
				}
				else{
					is = false;
					break;
				}
			}
		}

		if(is){
			int total = 0;
			for(int i = 1; i <= 6; i++) total += cnt[i];
			if(is && total + cnt[1] != day[1]){
				is = false;
			} 
		}
		

		if(is) break;
	}

	for(int i = 1; i <= 6; i++){
		if(i == 6){
			pc("%d\n", cnt[i]);
		}
		else{
			pc("%d ", cnt[i]);
		}
	}
	fflush(stdout);
	sc("%d", &n);

	if(n == -1){
		return false;
	}

    

    return true;

}


int main()
{
	//freopen("sample_input.txt", "r", stdin);
	//freopen("sample_output.txt", "w", stdout);
	// freopen("A-large-practice.in", "r", stdin);
	// freopen("A-large-practice.out", "w", stdout);
	
    

    //cin >> T;
    sc("%d%d", &T, &W);

    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);
        //cur_test_case = Cas;

		//pc("Case #%d: ", Cas);
		if(!solve()) return 0;
    }




    return 0;
}
