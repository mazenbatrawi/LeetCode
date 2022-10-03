class LUPrefix {
public:
    set<int> s;
    set<int> waiting;
    LUPrefix(int n) {
        s.insert(0);
    }
    
    void upload(int video) {
        waiting.insert(video);
    }
    
    int longest() {
        while(true){
            if(waiting.empty()){
                break;
            }
            int next = *waiting.begin();
            if(next == *s.rbegin() + 1){
                waiting.erase(waiting.begin());
                s.insert(next);
            }
            else{
                break;
            }
        }
        return *s.rbegin();
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */