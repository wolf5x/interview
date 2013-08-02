// 20min
// O(26mn): bfs
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dict.insert(end); // Must be here!
        queue<pair<string,int> > q;
        q.push(make_pair(start, 1));
        while(!q.empty()) {
            string s = q.front().first;
            int d = q.front().second;
            q.pop();
            if (s == end)
                return d;
            for(int i = 0; i < s.length(); i++){
                int k = s[i]-'a';
                for(int j = 0; j < 26; j++) {
                    if (j != k) {
                        s[i] = 'a'+j;
                        if (dict.count(s) > 0) {
                            dict.erase(s);
                            q.push(make_pair(s, d+1));
                        }
                    }
                }
                s[i] = 'a'+k;
            }
        }
        return 0;
    }
};

