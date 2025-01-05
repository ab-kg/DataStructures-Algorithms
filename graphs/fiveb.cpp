#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
bool vis[N];
vector<int> g[N];

// its so beautiful to see recursion working on dfs . 
void dfs(int i , int j  ,int iColor , int nColor , vector<vector<int>>& image)
{	
	int n = image.size();
	int m = image[0].size();
	if(i <0 || j < 0)	 return ;
	if(i >= n || j >= m) return ;
	if(image[i][j] != iColor) return ; 

	image[i][j] = nColor;

	dfs(i-1 ,  j   , iColor , nColor , image );
	dfs(i+1 ,  j   , iColor , nColor , image);
	dfs(i   ,  j-1 , iColor , nColor , image );
	dfs(i   ,  j+1 , iColor , nColor , image);

	// vis[vertex] = true ;
	// for(int child : g[vertex])
	// {
	// 	if(!vis[child])
	// 	{
	// 		dfs(child);
	// 	}
	// }

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	int iColor = image[sr][sc];
	if(iColor != color){ 
		dfs(sr , sc , iColor , color , image);
	}
	return image ;
}

int main()
{
	int n , e ;
	cin >> n >> e ;

	for(int i = 0 ;i < e ; ++i)
	{
		int x , y ;
		cin >> x >> y ;
		g[x].push_back(y);
		g[y].push_back(x);
	}

}