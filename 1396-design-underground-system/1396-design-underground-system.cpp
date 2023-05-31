class UndergroundSystem {
private:
    map<int, int> id_time;
    map<int, string> id_start;
    map<string, pair<double,int>> stationAvg; // {start->end, {avg, no of records}};
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        id_time[id] = t;
        id_start[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        int time_taken = t - id_time[id];
        string path = id_start[id] + "->" + stationName;
        
        if(stationAvg.find(path) == stationAvg.end())
        {
            stationAvg[path] = {time_taken, 1};
        }
        else
        {
            int nos = stationAvg[path].second;
            double total_time = time_taken + stationAvg[path].first * nos;
            nos++;
            stationAvg[path] = {total_time / (double)nos, nos};
        }
        
        id_time.erase(id);
        id_start.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path = startStation + "->" + endStation;
        return stationAvg[path].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */