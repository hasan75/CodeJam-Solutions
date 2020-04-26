#include <bits/stdc++.h>
using namespace std;

#define N 100
#define M 100002
#define sc scanf
#define pc printf
#define ll long long
#define eps 1e-9
#define INF 100000000000000
#define mp make_pair

int T;
int n;
char S[2001];
int cnt[26];
/*
    this two variables are to distinguish 0 -> 9 with unique character so that we
    can correctly generate our answer!
*/

pair< string, int>unique_str[] = { mp("Z", 0), mp("W", 2), mp("U", 4), mp("X", 6), mp("G", 8)};
pair< string, int>unique_odd_str[] = { mp("O", 1), mp("T", 3), mp("F", 5), mp("S", 7), mp("I", 9)};


string digits[11] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<int>ans;

ll Abs(ll a, ll b)
{
	if(a < b) return b - a;
	return a - b;
}


void reset()
{
	
	n = 0;
	for(int i = 0; S[i]; i++) n++;
	for(int i = 0; i < 26; i++) cnt[i] = 0;
	
	ans.clear();
}


void print()
{
	for(int ind: ans){
		printf("%d\n", ind);
	}
	printf("\n");
}
void solve()
{
	sc("%s", S);
	reset();


	

	
	
}


int main()
{
	// freopen("sample_input.txt", "r", stdin);
	// freopen("sample_output.txt", "w", stdout);
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	
    

    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);
        

		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
