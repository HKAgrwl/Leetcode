class TimeMap {
public:
    map<string,vector<pair<int,string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int,string> x = {timestamp,value};
        m[key].push_back(x);
    }
    
    string get(string key, int timestamp) {
        if(m.count(key)==0) return "";
        int start = 0;
        int end = m[key].size()-1;
        int mid;
        while(start <= end){
            mid = (start+end)/2;
            // cout<<m[key][mid].first<<" "<<timestamp<<endl;
            if(m[key][mid].first == timestamp) return m[key][mid].second;
            else if(m[key][mid].first < timestamp){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        if(end < 0) return "";
        return m[key][end].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */