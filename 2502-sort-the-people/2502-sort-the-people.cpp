class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights){
        int n = names.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(heights[j] > heights[i])
                {
                    swap(heights[j], heights[i]);
                    swap(names[j], names[i]);
                }
            }
        }

        return names;
    }
};