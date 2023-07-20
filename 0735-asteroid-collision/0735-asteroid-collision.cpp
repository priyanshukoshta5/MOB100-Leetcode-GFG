class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;    // using it like a stack

        for(int ast: asteroids)
        {
            ans.push_back(ast);
            while(ans.size() > 1)
            {
                int right = ans.back(); ans.pop_back();
                int left = ans.back(); ans.pop_back();
                if((right < 0 && left < 0) || (right > 0 && left > 0) || (right > 0 && left < 0))
                {
                    ans.push_back(left);
                    ans.push_back(right);
                    break;
                }
                else   // they will colloid as left is moving rightwards and right is moving leftwards
                {
                    if(abs(right) > abs(left)) 
                        ans.push_back(right);
                    else if(abs(right) < abs(left)) 
                        ans.push_back(left);
                }
            }
        }

        return ans;
    }
};