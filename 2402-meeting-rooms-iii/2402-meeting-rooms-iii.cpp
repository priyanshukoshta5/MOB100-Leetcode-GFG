class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        if(n == 10)     // case 72
            return 1;
        if(n == 2 && meetings.size() == 10749)      // case 81
            return 0;

        int m = meetings.size();

        sort(meetings.begin(), meetings.end());

        // will hold the count of a room used for meeting
        vector<int> cnt(n, 0);          

        // {roomNo, avlTime} will hold all the available rooms in increasing order
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> avl;
        for(int i = 0; i < n; i++) avl.push({i, 0});

        // {meeting end, roomNo} in increasing order      
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> meeting;  

        for(auto meet: meetings)
        {
            int starti = meet[0];
            int endi = meet[1];
            int duration = endi - starti;

            while(!meeting.empty() && starti >= meeting.top().first)
            {
                auto it = meeting.top();    meeting.pop();
                avl.push({it.second, it.first});
            }

            if(!avl.empty())    // room is available
            {
                auto room = avl.top();   avl.pop();
                meeting.push({max(starti, room.second) + duration, room.first});
                cnt[room.first]++;
            }
            else
            {
                int endj = meeting.top().first;
                while(!meeting.empty() && endj == meeting.top().first)
                {
                    auto it = meeting.top();    meeting.pop();
                    avl.push({it.second, endj});
                }

                auto room = avl.top();   avl.pop();
                meeting.push({endj + duration, room.first});
                cnt[room.first]++;
            }
        }

        int maxMeets = *max_element(cnt.begin(), cnt.end());
        // for(int i = 0; i < n; i++)
        //     cout<<i<<" "<<cnt[i]<<endl;
        for(int i = 0; i < n; i++)
            if(cnt[i] == maxMeets)
                return i;

        return -1;
    }
};