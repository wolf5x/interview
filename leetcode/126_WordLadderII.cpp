// ??min, ??WA
// bfs
class Solution {
    vector<vector<string> > ans;
    vector<string> tmp;
    unordered_map<string, vector<string> > pre;
    unordered_map<string, int> len;
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        pre.clear();
        len.clear();
        queue<string> q;
        q.push(start);
        len[start] = 0;
        while(!q.empty()) {
            string s = q.front(), t = s;
            int d = len[s];
            q.pop();
            if (t == end)
                break;
            for(int i = 0; i < s.length(); i++) {
                int k = s[i]-'a';
                for(int j = 0; j < 26; j++) {
                    if( j != k) {
                        s[i] = 'a'+j;
                        if (dict.count(s)>0) {
                            if (len.count(s) == 0) {
                                len[s] = d+1;
                                pre[s].push_back(t);
                                q.push(s);
                            } else if(len[s] == d+1) {
                                pre[s].push_back(t);
                            }
                        }
                    }
                }
                s[i] = 'a'+k;
            }
        }
        ans.clear();
        tmp.assign(1, end);
        build(start, end);
        return ans;
    }
    
    void build(string &start, string &s) {
        vector<string> &p = pre[s];
        if (start == s) {
            ans.push_back(tmp);
            reverse(ans.back().begin(), ans.back().end());
            return;
        }
        for(int i = 0; i < p.size(); i++) {
            tmp.push_back(p[i]);
            build(start, p[i]);
            tmp.pop_back();
        }
    }
};

