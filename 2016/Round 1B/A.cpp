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


	for(int i = 0; S[i]; i++) cnt[S[i] - 'A']++;


	for(int i = 0; i < 5; i++){
		pair<string, int>cur_pair = unique_str[i];
		int ind = cur_pair.second;

		if(cnt[cur_pair.first[0] - 'A'] > 0){
			
			int temp_cnt[26] = {0};
			
			for(char ch: digits[ind]){
				temp_cnt[ch - 'A']++;
			}
		

			int mx = n;

            // count the least appearance
			
			for(int j = 0; j < 26; j++){
				if(temp_cnt[j] > 0){
					mx = min(mx, cnt[j] / temp_cnt[j]);
				}
			}

            // subtract this minimum appearance from original cnt array

			for(int j = 0; j < 26; j++){
				if(temp_cnt[j] > 0){
					cnt[j] -= mx * temp_cnt[j];
				}
			}
		
			for(int j = 0;  j < mx; j++) ans.push_back(ind);

		}
	}

	//print();

	for(int i = 0; i < 5; i++){
		pair<string, int>cur_pair = unique_odd_str[i];
		int ind = cur_pair.second;

		if(cnt[cur_pair.first[0] - 'A'] > 0){
	
			int temp_cnt[26] = {0};
			
			for(char ch: digits[ind]){
				temp_cnt[ch - 'A']++;
			}

			int mx = n;
            // count the least appearance
			for(int j = 0; j < 26; j++){
				if(temp_cnt[j] > 0){
					mx = min(mx, cnt[j] / temp_cnt[j]);
				}
			}

            // subtract this minimum appearance from original cnt array
			for(int j = 0; j < 26; j++){
				if(temp_cnt[j] > 0){
					cnt[j] -= mx * temp_cnt[j];
				}
			}
			




			for(int j = 0;  j < mx; j++) ans.push_back(ind);

		}
	}

	//print();

	sort(ans.begin(), ans.end());

	for(int ind: ans){
		pc("%d", ind);
	}
	pc("\n");

	
	
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
