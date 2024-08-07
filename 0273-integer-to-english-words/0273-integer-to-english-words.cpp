// class Solution {
// private:
//     map<string, string> singleDigit = {{"1", "One"},
//                                     {"2", "Two"},
//                                     {"3", "Three"},
//                                     {"4", "Four"},
//                                     {"5", "Five"},
//                                     {"6", "Six"},
//                                     {"7", "Seven"},
//                                     {"8", "Eight"},
//                                     {"9", "Nine"}};
//     map<string, string> doubleDigit = {{"10", "Ten"},
//                                     {"11", "Eleven"},
//                                     {"12", "Twelve"},
//                                     {"13", "Thirteen"},
//                                     {"14", "Fourteen"},
//                                     {"15", "Fifteen"},
//                                     {"16", "Sixteen"},
//                                     {"17", "Seventeen"},
//                                     {"18", "Eightteen"},
//                                     {"19", "Nineteen"},
//                                     {"2", "Twenty"},
//                                     {"3", "Thirty"},
//                                     {"4", "Forty"},
//                                     {"5", "Fifty"},
//                                     {"6", "Sixty"},
//                                     {"7", "Seventy"},
//                                     {"8", "Eighty"},
//                                     {"9", "Ninty"}};

//     int countDigits(int n){
//         int cnt = 0;
//         while(n > 0)
//         {
//             n = n / 10;
//             cnt++;
//         }
//         return cnt;
//     }

// public:
//     string numberToWords(int num) {
//         int n = countDigits(num);
//         string number = to_string(num);

//         string ans = "";
//         if(n == 1)
//         {
//             ans = singleDigit[number.substr(n - 1, 1)];
//         }
//         else if(n == 2)
//         {
//             if(doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + doubleDigit[number.substr(n - 2, 2)];
//             else
//                 ans = ans + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];
//         }
//         else if(n == 3)
//         {
//             ans = ans + singleDigit[number.substr(n - 3, 1)] + " " + "Hundred";
//             if(number.substr(n - 2, 1) != "0" && doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];
//         }
//         else if(n == 4)
//         {
//             ans = ans + singleDigit[number.substr(n - 4, 1)] + " " + "Thousand";

//             if(number.substr(n - 3, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 3, 1)] + " " + "Hundred";

//             if(number.substr(n - 2, 1) != "0" && doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];
//         }
//         else if(n == 5)
//         {
//             if(number.substr(n - 5, 1) != "0" && doubleDigit.find(number.substr(n - 5, 2)) != doubleDigit.end())
//                 ans = ans + doubleDigit[number.substr(n - 5, 2)];
//             else if(number.substr(n - 5, 1) != "0" )
//                 ans = ans + doubleDigit[number.substr(n - 5, 1)];
            
//             if(number.substr(n - 4, 1) != "1" && number.substr(n - 4, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 4, 1)];

//             ans = ans + " " + "Thousand";

//             if(number.substr(n - 3, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 3, 1)] + " " + "Hundred";

//             if(number.substr(n - 2, 1) != "0" && doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];
//         }
//         else if(n == 6)
//         {
//             if(number.substr(n - 6, 1) != "0")
//                 ans = ans + singleDigit[number.substr(n - 6, 1)] + " " + "Hundred";

//             if(number.substr(n - 6, 1) != "0" && doubleDigit.find(number.substr(n - 6, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 6, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 6, 1)];
            
//             if(number.substr(n - 6, 1) != "1" && number.substr(n - 5, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 5, 1)];

//             ans = ans + " " + "Thousand";

//             if(number.substr(n - 3, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 3, 1)] + " " + "Hundred";

//             if(number.substr(n - 2, 1) != "0" && doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];
//         }
//         else if(n == 7)
//         {
//             ans = ans + singleDigit[number.substr(n - 6, 1)] + " " + "Million";

//             if(number.substr(n - 6, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 6, 1)] + " " + "Hundred";

//             if(number.substr(n - 6, 1) != "0" && doubleDigit.find(number.substr(n - 6, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 6, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 6, 1)];
            
//             if(number.substr(n - 6, 1) != "1" && number.substr(n - 5, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 5, 1)];

//             ans = ans + " " + "Thousand";

//             if(number.substr(n - 3, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 3, 1)] + " " + "Hundred";

//             if(number.substr(n - 2, 1) != "0" && doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];
//         }
//         else if(n == 8)
//         {
//             if(doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + doubleDigit[number.substr(n - 2, 2)];
//             else
//                 ans = ans + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];

//             ans = ans + " " + "Million";

//             if(number.substr(n - 6, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 6, 1)] + " " + "Hundred";

//             if(number.substr(n - 6, 1) != "0" && doubleDigit.find(number.substr(n - 6, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 6, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 6, 1)];
            
//             if(number.substr(n - 6, 1) != "1" && number.substr(n - 5, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 5, 1)];

//             ans = ans + " " + "Thousand";

//             if(number.substr(n - 3, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 3, 1)] + " " + "Hundred";

//             if(number.substr(n - 2, 1) != "0" && doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];
//         }
//         else if(n == 9)
//         {
//             if(number.substr(n - 9, 1) != "0")
//                 ans = ans + singleDigit[number.substr(n - 3, 1)] + " " + "Hundred";

//             if(doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 2)];
//             else
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];

//             ans = ans + " " + "Million";

//             if(number.substr(n - 6, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 6, 1)] + " " + "Hundred";

//             if(number.substr(n - 6, 1) != "0" && doubleDigit.find(number.substr(n - 6, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 6, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 6, 1)];
            
//             if(number.substr(n - 6, 1) != "1" && number.substr(n - 5, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 5, 1)];

//             ans = ans + " " + "Thousand";

//             if(number.substr(n - 3, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 3, 1)] + " " + "Hundred";

//             if(number.substr(n - 2, 1) != "0" && doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];
//         }
//         else if(n == 10)
//         {
//             ans = ans + singleDigit[number.substr(n - 3, 1)] + " " + "Billion";

//             if(number.substr(n - 9, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 3, 1)] + " " + "Hundred";

//             if(doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 2)];
//             else
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];

//             ans = ans + " " + "Million";

//             if(number.substr(n - 6, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 6, 1)] + " " + "Hundred";

//             if(number.substr(n - 6, 1) != "0" && doubleDigit.find(number.substr(n - 6, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 6, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 6, 1)];
            
//             if(number.substr(n - 6, 1) != "1" && number.substr(n - 5, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 5, 1)];

//             ans = ans + " " + "Thousand";

//             if(number.substr(n - 3, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 3, 1)] + " " + "Hundred";

//             if(number.substr(n - 2, 1) != "0" && doubleDigit.find(number.substr(n - 2, 2)) != doubleDigit.end())
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 2)];
//             else if(number.substr(n - 2, 1) != "0" )
//                 ans = ans + " " + doubleDigit[number.substr(n - 2, 1)];
            
//             if(number.substr(n - 2, 1) != "1" && number.substr(n - 1, 1) != "0")
//                 ans = ans + " " + singleDigit[number.substr(n - 1, 1)];
//         }

//         return ans;
//     }
// };


// ~ Editorial

class Solution {
public:
    // Mapping of numeric values to their corresponding English words
    vector<pair<int, string>> numberToWordsMap = {
        {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"},
        {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
        {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"},
        {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"},
        {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"},
        {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"},
        {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"},
        {2, "Two"}, {1, "One"}
    };

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        for (auto& [value, word] : numberToWordsMap) {
            // Check if the number is greater than or equal to the current unit
            if (num >= value) {
                // Convert the quotient to words if the current unit is 100 or greater
                string prefix = (num >= 100) ? numberToWords(num / value) + " " : "";

                // Get the word for the current unit
                string unit = word;

                // Convert the remainder to words if it's not zero
                string suffix = (num % value == 0) ? "" : " " + numberToWords(num % value);

                return prefix + unit + suffix;
            }
        }

        return "";
    }
};