/*#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define pip pair<int, ii>
#define mp make_pair
#define fi first
#define se second

int A, B, C;
char H[31][31][31];
int da[6] = {1,0,0,-1,0,0},
    db[6] = {0,1,0,0,-1,0},
    dc[6] = {0,0,1,0,0,-1};

int solve(pip toaDoS, pip toaDoE) {
    queue < pip > q;
    q.push(toaDoS);

    int visit[A][B][C] = {0};
    visit[toaDoS.fi][toaDoS.se.fi][toaDoS.se.se] = 1;

    while (!q.empty()) {
        pip t = q.front(); q.pop();
        
        if (t == toaDoE) 
            return visit[t.fi][t.se.fi][t.se.se] - 1;

        for (int i=0; i<6; i++) {
            //set new coordinates
            int x = t.fi + da[i];
            int y = t.se.fi + db[i];
            int z = t.se.se + dc[i];

            if (x<A && y<B && z<C && x>=0 && y>=0 && z>=0 && H[x][y][z]!='#' && visit[x][y][z]==0) {
                q.push(pip(x,ii(y,z)));
                visit[x][y][z] = visit[t.fi][t.se.fi][t.se.se] + 1;
            }
        }
    }
    return -1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> A >> B >> C;
        pip toaDoS, toaDoE;
        for (int i=0; i<A; i++) {
            for (int j=0; j<B; j++) {
                for (int k=0; k<C; k++) {
                    cin >> H[i][j][k];
                    if (H[i][j][k] == 'S') toaDoS = pip(i, ii(j, k));
                    if (H[i][j][k] == 'E') toaDoE = pip(i, ii(j, k));
                }
            }
        }
        cout << solve(toaDoS, toaDoE) << endl;
    }
    return 0;
}
k hieu vi sao sai
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

int a, b, c;
int dd[31][31][31];
char in[31][31][31];

void init(){
	for (int i=0; i<a; i++){
		for (int j=0; j<b; j++){
			for (int k=0; k<c; k++) dd[i][j][k]=0;
		}
	}
}

bool check(int x, int y, int z){
	if (x>=0 && x<a && y>=0 && y<b && z>=0 && z<c && in[x][y][z]!='#' && !dd[x][y][z]) return 1;
	return 0;
}

void BFS(iii s){
	int da[] = {1, 0, 0, -1, 0, 0};
	int db[] = {0, 1, 0, 0, -1, 0};
	int dc[] = {0, 0, 1, 0, 0, -1};
	queue <iii> q;
	q.push(s);
	dd[s.first][s.second.first][s.second.second] = 1;
	while (!q.empty()){
		iii v = q.front();
		q.pop();
		for (int i=0; i<6; i++){
			int x = v.first + da[i];
			int y = v.second.first + db[i];
			int z = v.second.second + dc[i];
			if (check(x, y, z)){
				q.push(iii(x, ii(y, z)));
				dd[x][y][z] = dd[v.first][v.second.first][v.second.second] + 1;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>a>>b>>c;
		iii S, E;
		init();
		for (int i=0; i<a; i++){
			for (int j=0; j<b; j++){
				for (int k=0; k<c; k++){
					cin>>in[i][j][k];
					if (in[i][j][k]=='S') S = iii(i, ii(j, k));
					if (in[i][j][k]=='E') E = iii(i, ii(j, k));
				}
			}
			char tmp;
			scanf("%c", &tmp);
		}
		BFS(S);
		int tmp = dd[E.first][E.second.first][E.second.second];
		if (tmp!=0) cout<<tmp-1<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
