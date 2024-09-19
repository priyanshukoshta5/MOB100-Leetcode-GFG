// ~ Editorial

class Solution {
private:
    vector<int> solve(int i, int open, string &expression, vector<int> &ans){
        if(expression[i] == ')')
            return {};
        
        vector<int> res;

        return res;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        if (expression.length() == 0) 
            return ans;

        if (expression.length() == 1) 
        {
            ans.push_back(stoi(expression));
            return ans;
        }

        if (expression.length() == 2 && isdigit(expression[0])) {
            ans.push_back(stoi(expression));
            return ans;
        }

        // expression = "(" + expression + ')';
        // solve(1, 1, expression, ans);

        // Recursive case: iterate through each character
        for (int i = 0; i < expression.length(); i++) 
        {
            char currentChar = expression[i];

            // Skip if the current character is a digit
            if (isdigit(currentChar)) continue;

            // Split the expression into left and right parts
            vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
            vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));

            // Combine results from left and right parts
            for (int leftValue : leftResults) 
            {
                for (int rightValue : rightResults) 
                {
                    int computedResult = 0;

                    // Perform the operation based on the current character
                    switch (currentChar) 
                    {
                        case '+':
                            computedResult = leftValue + rightValue;
                            break;
                        case '-':
                            computedResult = leftValue - rightValue;
                            break;
                        case '*':
                            computedResult = leftValue * rightValue;
                            break;
                    }

                    ans.push_back(computedResult);
                }
            }
        }

        return ans;
    }
};