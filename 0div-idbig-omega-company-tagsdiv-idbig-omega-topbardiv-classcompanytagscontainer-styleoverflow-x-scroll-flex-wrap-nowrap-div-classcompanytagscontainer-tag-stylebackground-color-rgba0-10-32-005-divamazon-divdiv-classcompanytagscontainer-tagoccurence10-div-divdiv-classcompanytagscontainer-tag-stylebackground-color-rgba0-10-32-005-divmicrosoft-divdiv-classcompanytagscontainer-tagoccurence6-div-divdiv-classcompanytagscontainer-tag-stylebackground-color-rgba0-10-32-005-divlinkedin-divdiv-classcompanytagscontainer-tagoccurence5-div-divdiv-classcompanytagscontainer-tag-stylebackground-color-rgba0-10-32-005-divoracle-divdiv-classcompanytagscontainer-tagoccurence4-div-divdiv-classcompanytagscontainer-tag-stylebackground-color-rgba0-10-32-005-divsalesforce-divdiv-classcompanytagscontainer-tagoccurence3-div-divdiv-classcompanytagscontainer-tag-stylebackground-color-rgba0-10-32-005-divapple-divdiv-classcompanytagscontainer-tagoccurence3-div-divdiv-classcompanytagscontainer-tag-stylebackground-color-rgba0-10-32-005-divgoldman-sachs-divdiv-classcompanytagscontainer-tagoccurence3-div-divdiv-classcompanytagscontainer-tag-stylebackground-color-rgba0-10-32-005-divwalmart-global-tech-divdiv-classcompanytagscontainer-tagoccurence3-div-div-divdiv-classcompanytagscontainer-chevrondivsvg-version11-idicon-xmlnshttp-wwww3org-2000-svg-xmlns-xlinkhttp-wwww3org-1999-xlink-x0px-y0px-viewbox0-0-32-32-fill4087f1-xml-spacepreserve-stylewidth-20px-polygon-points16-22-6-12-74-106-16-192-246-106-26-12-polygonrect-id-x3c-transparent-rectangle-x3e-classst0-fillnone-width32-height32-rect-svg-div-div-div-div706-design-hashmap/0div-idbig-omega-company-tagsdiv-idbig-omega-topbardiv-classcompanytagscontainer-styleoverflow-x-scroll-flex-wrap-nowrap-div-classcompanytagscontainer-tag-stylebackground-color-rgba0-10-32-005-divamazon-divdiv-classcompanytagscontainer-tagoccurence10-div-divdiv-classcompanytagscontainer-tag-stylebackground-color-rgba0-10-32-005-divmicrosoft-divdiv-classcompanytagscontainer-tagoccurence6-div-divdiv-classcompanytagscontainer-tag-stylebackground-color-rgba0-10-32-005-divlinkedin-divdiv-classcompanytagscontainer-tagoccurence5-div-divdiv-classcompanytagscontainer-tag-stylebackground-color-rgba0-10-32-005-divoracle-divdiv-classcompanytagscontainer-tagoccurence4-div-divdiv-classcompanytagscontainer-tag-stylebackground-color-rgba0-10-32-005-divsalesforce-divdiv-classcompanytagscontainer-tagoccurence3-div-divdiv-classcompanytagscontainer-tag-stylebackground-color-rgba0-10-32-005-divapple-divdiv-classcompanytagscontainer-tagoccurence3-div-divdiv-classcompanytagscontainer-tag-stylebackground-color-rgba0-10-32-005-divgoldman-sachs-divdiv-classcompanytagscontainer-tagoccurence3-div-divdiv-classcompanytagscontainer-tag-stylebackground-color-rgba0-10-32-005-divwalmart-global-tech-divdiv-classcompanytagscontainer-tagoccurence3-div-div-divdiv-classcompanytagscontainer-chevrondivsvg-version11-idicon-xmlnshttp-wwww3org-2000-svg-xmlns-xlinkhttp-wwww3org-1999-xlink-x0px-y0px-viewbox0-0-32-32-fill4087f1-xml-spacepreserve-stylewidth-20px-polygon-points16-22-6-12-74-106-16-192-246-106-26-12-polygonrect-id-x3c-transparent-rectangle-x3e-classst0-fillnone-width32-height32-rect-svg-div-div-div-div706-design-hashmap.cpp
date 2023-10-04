class MyHashMap {
    private:
    vector<pair<int, int>> data;

    
public:
    
    MyHashMap() {
      
    }
    
    void put(int key, int value) {
                 for (auto &entry : data) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }
        data.push_back({key, value});
    }
    
    int get(int key) {
for (const auto &entry : data) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == key) {
                data.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */