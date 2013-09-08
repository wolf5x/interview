/**
 * What's the total volumn of water a 2D grid can contain at most.
 */
int waterTrap2D(vector<vector<int> > height) {
    int m = height.size(), n = m>0 ? height[0].size() : 0;
    if (n == 0)
        return 0;
    int dr[] = {0,1,0,-1};
    int dc[] = {1,0,-1,0};
    queue<pair<int,int> > que;
    vector<vector<int> > group(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j += (i>0 && i<m-1)?n-1:1) {
            que.push_back(make_pair(i,j));
            group[i][j] = -1;
        }
    }
    while(!que.empty()) {
        int r = que.front().first, c = que.front().second;
        que.pop_front();
        for (int k = 0; k < 4; k++) {
            int tr = r+dr[k], tc = c+dc[k];
            if (tr >= 0 && tr < m && tc >= 0 && tc < n
                    && group[tr][tc] == 0
                    && height[r][c] <= height[tr][tc]) {
                que.push_back(make_pair(tr,tc));
                group[tr][tc] = -1;
            }
        }
    }

    int group_count = 0;
    vector<int> wall;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (!isbound[i][j] && group[i][j] == 0) {
                wall.push_back(INT_MAX);
                ++group_count;
                que.push_back(make_pair(i,j));
                group[i][j] = group_count;
                while(!que.empty()) {
                    int r = que.front().first, c = que.front().second;
                    que.pop_front();
                    for(int k = 0; k < 4; k++) {
                        int tr = r+dr[k], tc = c+dc[k];
                        if (tr >= 0 && tr < m && tc >= 0 && tc < n) {
                            if (group[tr][tc] == 0) {
                                group[tr][tc] = group_count;
                                que.push_back(make_pair(tr,tc));
                            } else if (group[tr][tc] == -1) {
                                wall[group_count-1] = min(wall[group_count-1], height[tr][tc]);
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++) 
        for(int j = 0; j < n; j++)
            if (group[i][j] > 0 && height[i][j] < wall[group[i][j]-1])
                ans += wall[group[i][j]-1]-height[i][j];
    return ans;
}


