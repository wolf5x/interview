vector<pair<int,int> > outlineOfRectangleUnion(vector<pair<int,int> > topleft, vector<pair<int,int> > topright)
{
    assert(topleft.size() == topright.size() && "Point arrays' length not equal");
    vector<pair<int,int> > ans;
    int n = topleft.size();
    vector<pair<pair<int,int>, int> > po; // x,y,type
    multiset<int> ys;
    int cury;
    for (int i = 0; i < n; i++) {
        po.push_back(make_pair(make_pair(topleft[i].first, topleft[i].second), 0));
        po.push_back(make_pair(make_pair(topright[i].first, topright[i].second), 1));
    }
    po.insert(0);
    cury = 0;
    sort(po.begin(), po.end());
    for (int i = 0; i < po.size(); i++) {
        int j;
        for (j = i; 
                j < po.size() && po[j].first.first == po[i].first.first;
                j++) {
            if (po[j].second == 0) {
                ys.insert(po[j].first.second);
            } else {
                ys.remove(ys.find(po[j].first.second));
            }
        }
        int newy = *ys.rbegin();
        if (newy != cury) {
            ans.push_back(make_pair(po[i].first.first, cury));
            ans.push_back(make_pair(po[i].first.first, newy));
            cury = newy;
        }
        i = j-1;
    }
    return ans;
}

