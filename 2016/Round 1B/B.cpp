#include <bits/stdc++.h>
using namespace std;

#define N 100
#define M 100002
#define sc scanf
#define pc printf
#define ll long long
#define eps 1e-9
#define INF 100000000000000

int T;
int n;
char C[18], J[18];

ll Abs(ll a, ll b)
{
	if(a < b) return b - a;
	return a - b;
}


void reset()
{
	
	n = 0;
	for(int i = 0; C[i]; i++) n++;
	
}

enum STATE{NORELATION, SMALLER, LARGER, EQUAL, BOTH_NONE, NONE_VAL, VAL_NONE, VAL_VAL};

STATE checkState(int pos)
{
	if(C[pos] == '?' && J[pos] == '?') return BOTH_NONE;
	else if(C[pos] == '?') return NONE_VAL;
	else if(J[pos] == '?') return VAL_NONE;
	else return VAL_VAL;
}

pair<ll, ll>doTheRest(int pos, STATE state, ll C_val, ll J_val) {
	//pc("up %lld %lld\n", C_val, J_val);
	char c,j;
	if(state == SMALLER){
		for(int i = pos; i < n; i++){
			c = C[i];
			j = J[i];
			if(c == '?' && j == '?') C_val = C_val * 10 + 9, J_val = J_val * 10 + 0;
			else if(c == '?') C_val = C_val * 10 + 9, J_val = J_val * 10 + (J[i] - '0');
			else if(j == '?') J_val = J_val * 10 + 0, C_val = C_val * 10 + (C[i] - '0');
			else C_val = C_val * 10 + (C[i] - '0'), J_val = J_val * 10 + (J[i] - '0');
		}
	}
	else if(state == LARGER){
		for(int i = pos; i < n; i++){
			c = C[i];
			j = J[i];
			if(c == '?' && j == '?') C_val = C_val * 10 + 0, J_val = J_val * 10 + 9;
			else if(c == '?') C_val = C_val * 10 + 0, J_val = J_val * 10 + (J[i] - '0');
			else if(j == '?') J_val = J_val * 10 + 9, C_val = C_val * 10 + (C[i] - '0');
			else C_val = C_val * 10 + (C[i] - '0'), J_val = J_val * 10 + (J[i] - '0');
		}
	}
	else{
		for(int i = pos; i < n; i++){
			c = C[i];
			j = J[i];
			switch (state)
			{
			case EQUAL:
				if(c == '?' && j == '?'){
					C_val = C_val * 10 + 0, J_val = J_val * 10 + 0;
				}
				else if(c == '?') C_val = C_val * 10 + (J[i] - '0'), J_val = J_val * 10 + (J[i] - '0');
				else if(j == '?') J_val = J_val * 10 + (C[i] - '0'), C_val = C_val * 10 + (C[i] - '0');
				else{
					if(c < j) state = SMALLER;
					else if(c > j) state = LARGER;
					C_val = C_val * 10 + (C[i] - '0'), J_val = J_val * 10 + (J[i] - '0');
				}
				break;
			case SMALLER:
				if(c == '?' && j == '?') C_val = C_val * 10 + 9, J_val = J_val * 10 + 0;
				else if(c == '?') C_val = C_val * 10 + 9, J_val = J_val * 10 + (J[i] - '0');
				else if(j == '?') J_val = J_val * 10 + 0, C_val = C_val * 10 + (C[i] - '0');
				else C_val = C_val * 10 + (C[i] - '0'), J_val = J_val * 10 + (J[i] - '0');
				break;
			case LARGER:
				if(c == '?' && j == '?') C_val = C_val * 10 + 0, J_val = J_val * 10 + 9;
				else if(c == '?') C_val = C_val * 10 + 0, J_val = J_val * 10 + (J[i] - '0');
				else if(j == '?') J_val = J_val * 10 + 9, C_val = C_val * 10 + (C[i] - '0');
				else C_val = C_val * 10 + (C[i] - '0'), J_val = J_val * 10 + (J[i] - '0');
				break;
			default:
				break;
			}
		}
	}

	return {C_val, J_val};
}

void updateAns(pair<ll,ll>ret, ll *ans, ll *fir, ll *sec)
{
	
	if(Abs(ret.first, ret.second) < *ans){
		*ans = Abs(ret.first, ret.second);
		*fir = ret.first;
		*sec = ret.second;
	}
	else if(Abs(ret.first, ret.second) == *ans){
		if(ret.first < *fir){
			*fir = ret.first;
			*sec = ret.second;
		}
		else if(ret.first == *fir && ret.second < *sec){
			*fir = ret.first;
			*sec = ret.second;
		}
		
	}
}

void solve()
{

	sc("%s %s", C, J);
	reset();

	STATE state = NORELATION;
	ll cur_C = LLONG_MAX;
	ll cur_J = LLONG_MAX;
	ll cur_mn = LLONG_MAX;

	

	for(int pos = 0; pos < n; pos++){
		
		//pc("yes\n");
		ll C_val = 0;
		ll J_val = 0;

		for(int prev_pos = 0; prev_pos < pos ; prev_pos++){
			char c = C[prev_pos];
			char j = J[prev_pos];
			if(c == '?' && j == '?'){
				C_val = C_val * 10 + 0, J_val = J_val * 10 + 0;
			}
			else if(c == '?') C_val = C_val * 10 + (J[prev_pos] - '0'), J_val = J_val * 10 + (J[prev_pos] - '0');
			else if(j == '?') J_val = J_val * 10 + (C[prev_pos] - '0'), C_val = C_val * 10 + (C[prev_pos] - '0');
			else{
				C_val = C_val * 10 + (C[prev_pos] - '0'), J_val = J_val * 10 + (J[prev_pos] - '0');
			}
		}

		char c = C[pos];
		char j = J[pos];

		pair<ll, ll> ret;
		if(c == '?' && j == '?'){
			
			ret = doTheRest(pos+1, SMALLER, C_val * 10 + 0, J_val * 10 + 1);
			updateAns(ret, &cur_mn, &cur_C, &cur_J);

			ret = doTheRest(pos+1, LARGER, C_val * 10 + 1, J_val * 10 + 0);
			updateAns(ret, &cur_mn, &cur_C, &cur_J);

			ret = doTheRest(pos+1, EQUAL, C_val * 10 + 0, J_val * 10 + 0);
			updateAns(ret, &cur_mn, &cur_C, &cur_J);
		}
		else if(c == '?'){

			for(int next = 0; next < 10; next++){
				char nx = '0' + next;
				if(nx == j){
					ret = doTheRest(pos+1, EQUAL, C_val * 10 + (nx -'0'), J_val * 10 + (j - '0'));
				}
				else if(nx < j){
					ret = doTheRest(pos+1, SMALLER, C_val * 10 + (nx - '0'), J_val * 10 + (j - '0'));
				}
				else{
					ret = doTheRest(pos+1, LARGER, C_val * 10 + (nx - '0') , J_val * 10 + (j - '0'));
				}
				updateAns(ret, &cur_mn, &cur_C, &cur_J);
			}
			
		}
		else if(j == '?'){
			for(int next = 0; next < 10; next++){
				char nx = '0' + next;
				if(nx == c){
					ret = doTheRest(pos+1, EQUAL, C_val * 10 + (c -'0'), J_val * 10 + (nx - '0'));
				}
				else if(c < nx){
					ret = doTheRest(pos+1, SMALLER, C_val * 10 + (c - '0'), J_val * 10 + (nx - '0'));
				}
				else{
					ret = doTheRest(pos+1, LARGER, C_val * 10 + (c - '0') , J_val * 10 + (nx - '0'));
				}
				updateAns(ret, &cur_mn, &cur_C, &cur_J);
			}
		}
		else{
			if(c < j){
				ret = doTheRest(pos+1, SMALLER, C_val * 10 + (c -'0'), J_val * 10 + (j - '0'));
				state = SMALLER;
			}
			else if(c > j){
				ret = doTheRest(pos+1, LARGER, C_val * 10 + (c -'0'), J_val * 10 + (j - '0'));
				state = LARGER;
			}
			else{
				ret = doTheRest(pos+1, EQUAL, C_val * 10 + (c -'0'), J_val * 10 + (j - '0'));
			}
			updateAns(ret, &cur_mn, &cur_C, &cur_J);
			//pc("%d\n", state);
		}

		if(state != NORELATION){
			// once we sure that both won't be equal again, we don't need to check further! wow!!
			break;
		}

	}

	//pc("%lld %lld %lld\n", cur_mn, cur_C, cur_J);

	for(int i = n - 1; i >= 0; i--){
		C[i] = '0' + (cur_C % 10);
		J[i] = '0' + cur_J % 10;
		cur_C /= 10;
		cur_J /= 10;
	}
	pc("%s %s\n", C, J);
	
}


int main()
{
	// freopen("sample_input.txt", "r", stdin);
	// freopen("sample_output.txt", "w", stdout);
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	
    

    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);
        

		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
