class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        string prev = folder[0];
        for(int i = 1; i < folder.size(); i++)
        {
            string path = folder[i];
            if(path.substr(0, prev.length()) != prev)
            {
                ans.push_back(prev);
                prev = path;
            }
            else if(path.size() > prev.size() && path[prev.size()] != '/')
            {
                ans.push_back(prev);
                prev = path;
            }
        }
        ans.push_back(prev);
        return ans;
    }
};