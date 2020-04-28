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
int n,m;
ll dp[100][100];
ll a[101],b[101];
int A[101], B[101];
// type, ind
ll sumA[101][101], sumB[101][101];
ll ans;

void reset()
{
	
    for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			dp[i][j] = 0;
			sumA[i][j] = 0;
			sumB[i][j] = 0;
		}
	}
    
}

void rec()  
{  

      
    ans = 0;

    for (int i = 0; i <= n; i++)  
    {  
        for (int j = 0; j <= m; j++)  
        {  
			if (i == 0 || j == 0) {
				dp[i][j] = 0; 
			}  
		
			else if (A[i - 1] == B[j - 1])  {
				
				ll ret = 0;
				int type = A[i-1];
				for(int p = 0; p < i; p++){
					for(int q = 0; q < j; q++){
						ret = max(ret, dp[p][q] + 
						min(sumA[type][i] - sumA[type][p], sumB[type][j] - sumB[type][q]));
					}
				}

				//pc("first %d %d %lld\n", i, j, ret);

				dp[i][j] = ret;
				
			}
			else{
				
				ll ret = 0;
				for(int p = 1; p < i; p++){
					for(int q = 1; q < j; q++){
						ret = max(ret, dp[p][q]);
					}
				}

				//pc("first %d %d %lld\n", i, j, ret);

				dp[i][j] = ret;
				//pc("second %d %d %lld\n", i, j, dp[i][j]);
			}

			ans = max(ans, dp[i][j]);
				
        }  
    }  
          
     
}


void solve()
{
	

	sc("%d%d", &n, &m);
	reset();

	for(int i = 0; i < n; i++){
		sc("%lld %d", &a[i], &A[i]);
		//mx_typeA = max(mx_typeA, A[i]);
	}

	for(int i = 0; i < m; i++){
		sc("%lld %d", &b[i], &B[i]);
		//mx_typeB = max(mx_typeB, B[i]);
	}

	for(int i = 1; i <= n; i++){
		sumA[A[i-1]][i] = a[i-1];
	}

	for(int i = 1; i <= m; i++){
		sumB[B[i-1]][i] = b[i-1];
	}

	for(int type = 1; type <= 100; type++){
		for(int ind = 1; ind <= 100; ind++){
			sumA[type][ind] = sumA[type][ind] + sumA[type][ind-1];
			sumB[type][ind] = sumB[type][ind] + sumB[type][ind-1];
		}
	}

	// for(int type = 1; type <= 2; type++){
	// 	pc("type %d\n", type);
	// 	for(int ind = 1; ind <= n; ind++){
	// 		pc("%lld ", sumA[type][ind]);
	// 	}
	// 	pc("\n");
	// }

	// for(int type = 1; type <= 2; type++){
	// 	pc("type %d\n", type);
	// 	for(int ind = 1; ind <= m; ind++){
	// 		pc("%lld ", sumB[type][ind]);
	// 	}
	// 	pc("\n");
	// }

    rec();

	pc("%lld\n", ans);
    
	
}


int main()
{
	// freopen("sample_input.txt", "r", stdin);
	// freopen("sample_output.txt", "w", stdout);
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	


    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);
        //cur_test_case = Cas;

		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
