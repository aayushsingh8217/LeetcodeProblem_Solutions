class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int check;
    SeatManager(int n) {
        check=1;
    }
    
    int reserve() {
        if(!pq.empty())
        {
            int reserve=pq.top();
            pq.pop();
            return reserve;
        }
        int reserve=check;
        check++;
        return reserve;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */