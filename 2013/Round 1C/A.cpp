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
int n;
char s[1000001];
int len;
// int consonant_cnt[101];
vector<int>consecutive_pos;

bool isConsonant(char ch)
{
	return !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void reset()
{
	len = 0;
	for(int i = 0; s[i]; i++) len++;
	consecutive_pos.clear();
}




void solve()
{
	
	/*
		consecutive_pos -> save the end positions i of substring where consecutive consonants count >= n.
		then for each position i, count valid substrings which start position is i.
	*/
	sc("%s", s);
	sc("%d", &n);
	reset();

	int cnt = 0;

	for(int i = 0; i < len; i++){
		if(isConsonant(s[i])) cnt++;
		else cnt = 0;
		if(cnt >= n) consecutive_pos.push_back(i);
	}

	consecutive_pos.push_back(len+1);

	ll ans = 0LL;

	for(int i = 0; i < len - n + 1; i++){
		int ind = lower_bound(consecutive_pos.begin(), consecutive_pos.end(), i + n - 1) - consecutive_pos.begin();
		int next_valid_pos = consecutive_pos[ind];
		if(next_valid_pos != len + 1){
			int total = (len - i) - n + 1;
			int not_valid = (next_valid_pos - i) - n + 1;
			if(total - not_valid > 0) ans += (total - not_valid);
		}
	}

	pc("%lld\n", ans);
	

	
    
	
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

		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
