#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > pawn,white,black;
bool queen,rook,knight,bishop;
pair<int,int> king;
int ans = 0;

int dist(int x1,int y1,int x2,int y2){
	int d1 = (y2-y2)*(y2-y2) - (x2-x1)*(x2-x1);
	return d1;
}

void check_for_knight(int x,int y){
	if((abs(x-king.first)==1 && abs(y-king.second)==2) || (abs(x-king.first)==2 && abs(y-king.second)==1)){
		if(!bishop){ans++;}
	}
}
void check_for_rook(int x,int y){
	if(!rook){
		bool flag=true;
		if((x==king.first) && (y==king.second)){
			for(int i=0;i<(int)white.size();i++){
				if(white[i] == make_pair(x+1,y)){continue;}
				if(x==king.first && x==white[i].first && (king.first-white[i].first > 0)){
					flag=false;break;
				}
			}
			for(int i=0;i<(int)black.size();i++){
				if(black[i] == make_pair(x+1,y)){continue;}
				if(x==king.first && x==black[i].first && (king.first-black[i].first > 0)){
					flag=false;break;
				}
			}
			if(flag){
				ans++;
				if(!queen){ans++;}
			}
		}
	}
}

void check_for_bishop(int x,int y){
	if(!bishop){
		bool flag=true;
		if(abs(x-king.first) == abs(y-king.second)){
			for(int i=0;i<(int)white.size();i++){
				if(white[i] == make_pair(x+1,y)){continue;}
				if(white[i].first==x || white[i].second==y){continue;}
				int slope1 = (y-white[i].second)/(x-white[i].first);
				int slope2 = (y-king.second)/(x-king.first);
				if((slope2==slope1) && (dist(x,y,white[i].first,white[i].second)<dist(x,y,king.first,king.second))){
					flag=false;break;
				}
			}
			for(int i=0;i<(int)black.size();i++){
				if(black[i] == make_pair(x+1,y)){continue;}
				if(black[i].first==x || black[i].second==y){continue;}
				int slope1 = (y-black[i].second)/(x-black[i].first);
				int slope2 = (y-king.second)/(x-king.first);
				if((slope2==slope1) && (dist(x,y,black[i].first,black[i].second)<dist(x,y,king.first,king.second))){
					flag=false;break;
				}
			}
			if(flag){
				ans++;
				if(!queen){ans++;}
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin>>t;
    
    while(t--){
        char arr[8][8];
        queen=false,rook=false,knight=false,bishop=false;
        pawn.clear();white.clear();black.clear();
        ans=0;
        for(int i=0;i<8;i++){
            cin>>arr[i];
            for(int j=0;j<8;j++){
                if(arr[i][j]>='a' && arr[i][j]<='z'){
                    black.push_back(make_pair(i,j));
                }else if(arr[i][j]>='A' && arr[i][j]<='Z'){
                    white.push_back(make_pair(i,j));
                }
                if(i==1){
                    if(arr[i][j]=='P'){
                        pawn.push_back(make_pair(i,j));
                    }
                }
                if(arr[i][j]=='Q'){queen=true;}
                if(arr[i][j]=='N'){knight=true;}
                if(arr[i][j]=='B'){bishop=true;}
                if(arr[i][j]=='R'){rook=true;}
                if(arr[i][j]=='k'){king = make_pair(i,j);}
            }
        }
        int n = (int)pawn.size();
        for(int i=0;i<n;i++){
        	int x = pawn[i].first;
        	int y = pawn[i].second;
        	bool flag=false;
        	for(int j=0;j<(int)white.size();j++){
        		if(white[j] == make_pair(x-1,y)){flag=true;break;}
        	}
        	if(flag){continue;}
        	for(int j=0;j<(int)black.size();j++){
        		if(black[j] == make_pair(x-1,y)){flag=true;break;}
        	}
        	if(flag){continue;}

        	int nx = x-1,ny = y;
        	check_for_bishop(nx,ny);
        	check_for_rook(nx,ny);
        	check_for_knight(nx,ny);
        }
        cout<<ans<<endl;
    }
}