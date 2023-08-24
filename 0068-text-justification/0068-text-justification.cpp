class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> line;    // will store the words in a line
        int length = 0;         // will store the lengths of all words in a line + single spaces
        vector<string> ans;     // will store answer lines
        string temp = "";       // to build temperory answer

        // finding the number of words which can fit in a line and then adding them with the right amoutn of spaces in the 'ans' vector
        for(string word: words)
        {
            // if current 'word' can be added to current line
            if((length + word.length()) <= maxWidth)
            {
                length += word.length() + 1;   // wordLength + one space
                line.push_back(word);
            }
            else
            {
                length -= line.size();                  // removing the spaces we have counted
                int spaces = maxWidth - length;         // maxWidth - all lengths of words
                int spaceCount = line.size() - 1;       // positions to give space
                if(spaceCount == 0)                     // to prevent eachSpace from ZeroDivision
                    spaceCount = 1;                     
                int eachSpace = spaces / spaceCount;    // size of each slot of space
                int extraSpace = spaces % spaceCount;   // extra spaces in slot

                for(int i = 0; i < line.size(); i++)
                {
                    if(i != 0)      // if not the first word, so we will add spaces
                    {
                        int part = eachSpace;
                        if(extraSpace > 0)  // if we have extra space, add it to the left parts
                        {
                            part++;
                            extraSpace--;
                        }
                        while(part--)       // adding spaces in the slot
                            temp.push_back(' ');
                    }
                    temp.append(line[i]);   // appending the word in the temp answer
                }
                while(temp.length() < maxWidth)     // in the case of single word spaces will be left
                    temp.push_back(' ');
                
                // adding 'temp' answer in the 'ans' vector
                ans.push_back(temp);

                // clearning current line answer 'temp'
                temp.clear();

                // clearning current line words
                line.clear();

                // adding the word in the next line
                length = word.length() + 1;
                line.push_back(word);
            }
        }

        // adding the last line in the ans;
        for(int i = 0; i < line.size(); i++)
        {
            if(i != 0)
                temp.push_back(' ');
            temp.append(line[i]);
        }
        while(temp.length() < maxWidth)
            temp.push_back(' ');
        ans.push_back(temp);

        return ans;
    }
};