
vector<vector<int>> fourDirection = {{-1,0},{0,1},{1,0},{0,-1}};

//new co-ordinate must be valid
bool insideGrid(int x,int y,int n,int m){
	if(x>=0 && x<n && y>=0 && y<m)
		return true;
	return false;
}

/*will give the shortest path from sX,sY to all other co-ordinates
-1 : passage through the cell is prohibited*/
vector<vector<ll>> bfsGrid(int sX,int sY,int n,int m,vector<vector<ll>>&data){
	vector<vector<ll>> cost(n,vector<ll>(m));
	vector<vector<bool>> visited(n,vector<bool>(m));

	queue<pair<int,int>> que;
	que.push({sX,sY});
	visited[sX][sY]=true;
	cost[sX][sY]=data[sX][sY];

	while(!que.empty()){
		pair<int,int> my = que.front();
		que.pop();

		int x = my.first;
		int y = my.second;

		for(int i=0;i<4;i++){
			int nX = x+fourDirection[i][0];
			int nY = y+fourDirection[i][1];

			if(insideGrid(nX,nY,n,m) && data[nX][nY]!=-1){
				if(!visited[nX][nY]){
					visited[nX][nY] = true;
					cost[nX][nY] = cost[x][y]+data[nX][nY];

					que.push({nX,nY});
				}else if(cost[nX][nY]>(cost[x][y]+data[nX][nY])){
					cost[nX][nY] = cost[x][y]+data[nX][nY];
					que.push({nX,nY});
				}
			}	
		}
	}
	return cost;
}