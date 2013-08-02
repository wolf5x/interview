// 20min, 1WA
// "/.." => "/"
// http://leetcode.com/onlinejudge#question_71
class Solution {
public:
    string simplifyPath(string path) {
        if(path.length() == 0 || path[0] != '/')
            return "";
        path += "/";
        vector<string> dirs;
        for(int p = 1, q; p < path.length(); p = q+1) {
            q = p;
            while(path[q] != '/')
                q++;
            string dir = path.substr(p, q-p);
            if("" == dir || "." == dir) {
                continue;
            } else if(".." == dir) {
                if(!dirs.empty()) {
                   dirs.pop_back();
                }
            } else {
                dirs.push_back(dir);
            }
        }
        if(dirs.empty())
            return "/";
        string ans = "";
        for(int i = 0; i < dirs.size(); i++)
            ans += "/" + dirs[i];
        return ans;
    }
};

