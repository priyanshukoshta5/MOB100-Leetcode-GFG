// ~Editorial
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        // Add the counts of a, b and c in priority queue.
        if (a > 0) {
            pq.push({a, 'a'});
        }

        if (b > 0) {
            pq.push({b, 'b'});
        }

        if (c > 0) {
            pq.push({c, 'c'});
        }

        string ans = "";
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();
            int count = p.first;
            char character = p.second;
            // If three consecutive characters exist, pick the second most
            // frequent character.
            if (ans.length() >= 2 and ans[ans.length() - 1] == p.second and
                ans[ans.length() - 2] == p.second) {
                if (pq.empty()) break;

                pair<int, char> temp = pq.top();
                pq.pop();
                ans += temp.second;
                if (temp.first - 1 > 0) {
                    pq.push({temp.first - 1, temp.second});
                }
            } else {
                count--;
                ans = ans + character;
            }

            // If count is greater than zero, add it to priority queue.
            if (count > 0) {
                pq.push({count, character});
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     string longestDiverseString(int a, int b, int c) {
//         priority_queue<pair<int, char>> maxH;
//         if(a != 0) maxH.push({a, 'a'});
//         if(b != 0) maxH.push({b, 'b'});
//         if(c != 0) maxH.push({c, 'c'});

//         // while(!maxH.empty())
//         // {
//         //     cout<<maxH.top().first<<" "<<maxH.top().second<<endl;
//         //     maxH.pop();
//         // }

//         string ans = ".";

//         while(!maxH.empty())
//         {
//             pair<int, char> one = maxH.top(); maxH.pop();
//             if(maxH.size() == 0)
//             {
//                 if(ans.back() != one.second)
//                 {
//                     for(int i = 0; i < one.first; i++)
//                         ans.push_back(one.second);
//                 }
//                 break;
//             }

//             pair<int, char> two = maxH.top(); maxH.pop();
            
//             cout<<one.first<<one.second<<" "<<two.first<<two.second<<endl;

//             if(ans[ans.length() - 1] != one.first)
//             {
//                 cout<<"YO\n";
//                 if(one.first >= 2)
//                 {
//                     ans.push_back(one.second);
//                     ans.push_back(one.second);
//                     one.first -= 2;
//                     if(one.first != 0)
//                         maxH.push(one);
//                 }
//                 else
//                 {
//                     ans.push_back(one.second);
//                 }
//                 maxH.push(two);
//             }
//             else
//             {
//                 cout<<"YOYO\n";
//                 if(two.first >= 2)
//                 {
//                     ans.push_back(two.second);
//                     ans.push_back(two.second);
//                     two.first -= 2;
//                     if(two.first != 0)
//                         maxH.push(two);
//                 }
//                 else
//                 {
//                     ans.push_back(two.second);
//                 }
//                 maxH.push(one);
//             }
//         }
        
//         return ans;
//     }
// };