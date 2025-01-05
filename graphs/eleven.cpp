// How to find shortest Path using BFS 

#include <bits/stdc++.h>
using namespace std;

const int N =  1e^5 + 10 ;
vector<int> g[N];

int vis[8][8];
int level[8][8];

int getX(string s){
	return s[0]- 'a';
}

int getY(string s){
	return s[1]-'1';
}
t
bool isValid(int x , int y){
	return x >= 0 && y >= 0 && x < 8 && y < 8 ;
}

vector<pair<int ,int>> movements = {
	{-1 , 2} , { 1 , 2} ,
	{ -1 , -2 } , { 1 , -2} , 
	{2 , -1} , { 2 , 1},
	{ -2 , -1} , { -2 , 1}
}

int bfs(string source , string destination){
	int sourceX = getX(source);
	int sourceY = getY(source);
	int destX = getX(destination);
	int destY = getY(destination);
	queue<pair<int , int>> q;
	q.push({sourceX , sourceY});
	vis[sourceX][sourceY] = 1;

	while(!q.empty()){
		pair<int , int> v = q.front();
		q.pop();
		int x = v.first , y = v.second ;
		
		for(auto movement : movements){
			int childX = movement.first + x ;
			int childY = movement.second + y ;
			if(!isValid(childX , childY)) continue;
			if(!vis[childX][childY]){
				q.push({childX , childY});
				lev[childX][childY] = lev[x][y]+1 ;
				vis[childX][childY] = 1 ;
			}
		}
	}

	return lev[destX][destY];

}

void reset(){
	for(int i = 0 ; i < 8 ; ++i){
		for(int j = 0 ; j < 8 ; ++j){
			lev
		}
	}
}

int main()
{
	int n ;
	cin>> n ;
	while(n--){
		string s1 , s2 ;
		cin >> s1 >> s2 ;
		cout << bfs(s1 , s2);
	}
}