class SnapshotArray {
public:
    
    vector < vector < pair < int, int > > > arr;
    int count = -1;
    
    SnapshotArray(int length) {
        
        arr.resize(length, vector < pair < int, int > >(1, {0, 0}));
    }
    
    void set(int index, int val) {
        
        arr[index].push_back({count+1, val});
    }
    
    int snap() {
        count++;
        return count;
    }
    
    int get(int index, int snap_id) {
     
        int l = 0, r = arr[index].size()-1, ans;
        while(l <= r){
            
            int mid = (l+r)/2;
            if(arr[index][mid].first <= snap_id){
                ans = arr[index][mid].second;
                l = mid+1;
            }
            else r = mid - 1;
        }
        
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */