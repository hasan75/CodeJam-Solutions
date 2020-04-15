#include <bits/stdc++.h>
using namespace std;

#define N 100002
#define M 100002
#define sc scanf
#define pc printf
#define ll long long

int T;
int n;
char str[51][101];
int len[51];
char ans[10001];
int cnt;

void reset()
{
    cnt = 0;
}

void solve(int Case)
{
	
	sc("%d", &n);
    reset();

    pc("Case #%d: ", Case);

    for(int i = 0; i < n; i++){
        sc("%s", str[i]);

    }

    for(int i = 0; i < n; i++){
        len[i] = 0;
        for(int j = 0; str[i][j]; j++){
            len[i]++;
        }
    }

    for(int j = len[0] - 1; j > 0; j--){
        ans[cnt++] = str[0][j];
    }

    for(int i = 1; i < n; i++){
        int now = cnt;
        //pc("cnt %d\n", cnt);
        int ind = 0;
        for(int j = len[i] - 1; j > 0; j--){
            if(ind < cnt){
                if(ans[ind] != str[i][j]) {
                    //pc("%d %d %d\n", ind, i, j);
                    pc("*\n");
                    return;
                }
            }
            else{
                ans[cnt++] = str[i][j];
            }
            ind++;
        }
    }

    for(int i = cnt - 1; i >= 0; i--){
        pc("%c", ans[i]);
    }
    pc("\n");

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
