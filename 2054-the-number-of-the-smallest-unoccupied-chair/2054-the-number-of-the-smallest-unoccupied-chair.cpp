// ~Editorial

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>>
            events;  // To store both arrival and leave events

        // Populate events with {arrival, friendIndex} and {leave, -friendIndex}
        for (int i = 0; i < n; i++) {
            events.push_back({times[i][0], i});   // Friend arrives
            events.push_back({times[i][1], ~i});  // Friend leaves
        }

        sort(events.begin(), events.end());  // Sort events by time

        priority_queue<int, vector<int>, greater<int>>
            availableChairs;  // Min-heap for available chairs
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            occupiedChairs;  // Min-heap to track when chairs will be vacated

        for (int i = 0; i < n; i++)
            availableChairs.push(i);  // Initially all chairs are free

        for (auto& event : events) {
            int time = event.first;
            int friendIndex = event.second;

            // Free up chairs when friends leave
            while (!occupiedChairs.empty() &&
                   occupiedChairs.top().first <= time) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            if (friendIndex >= 0) {  // Friend arrives
                int chair = availableChairs.top();
                availableChairs.pop();
                if (friendIndex == targetFriend) return chair;
                occupiedChairs.push(
                    {times[friendIndex][1],
                     chair});  // Mark when the chair will be vacated
            }
        }

        return -1;  // Should never reach here
    }
};

// class Solution {
// public:
//     int smallestChair(vector<vector<int>>& times, int targetFriend) {
//         vector<int> friendTime = times[targetFriend];
//         sort(times.begin(), times.end());

//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> used;
//         priority_queue<int, vector<int>, greater<int>> available;
//         available.push(0);
//         for(auto t: times)
//         {
//             while(!used.empty() && used.top().first <= t[0])
//             {
//                 available.push(used.top().second);
//                 used.pop();
//             }
//             if(t == friendTime)
//                 return available.top();
            
//             if(available.size() == 1)
//             {
//                 used.push({t[1], available.top()});
//                 available.push(available.top() + 1);
//             }
//             available.pop();
//         }
//         return -1;
//     }
// };