class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string,map<int,string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        if(m[key].empty()) return "";
        auto k=m[key].upper_bound(timestamp);
        if(k==m[key].begin()) return "";
        return (--k)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
