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
int k, l, s;
char K[8], L[8];
char temp[8];
int Count[8];

void reset()
{

	for(int i = 0; i < 8; i++) Count[i] = 0;
	
}

int targetCount()
{
	//pc("temp %s\n", temp);
	int cnt = 0;
	for(int i = 0; i + l - 1 < s; i++){
		int found = 1;
		for(int j = 0;  j < l; j++){
			if(temp[i+j] != L[j]) {
				found = 0;
				break;
			}
		}
		//pc("yes %d\n", found);
		cnt += found;
	}

	return cnt;
}

void rec(int pos) {
	if(pos == s){
		temp[s] = '\0';
		Count[targetCount()]++;
		return;
	}

	for(int j = 0 ; j < k; j++){
		temp[pos] = K[j];
		rec(pos+1);
	}
}




void solve()
{
	reset();

	sc("%d%d%d", &k, &l, &s);
	sc("%s",K);
	sc("%s",L);

	rec(0);

	double total_count = 0;
	for(int i = 0; i <= s; i++) total_count += Count[i];
	double max_banana = 0;

	for(int i = s;  i >= 0; i--){
		if(Count[i]){
			max_banana = i;
			break;
		}
	}
	

	double banana_given = 0;

	//pc("%lf %lf\n", max_banana, total_count);
	
	for(int i = 0; i <= s; i++){
		banana_given += i * (Count[i] / total_count) ;
	}

	pc("%0.09lf\n", max_banana - banana_given);
	
}


int main()
{
	// freopen("sample_input.txt", "r", stdin);
	// freopen("sample_output.txt", "w", stdout);
	freopen("B-small-practice.in", "r", stdin);
	freopen("B-small-practice.out", "w", stdout);
	
    

    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){

		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
