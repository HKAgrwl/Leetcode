class BrowserHistory {
private:
    int curr;
    vector<string> history;
    stack<string> historyHelper;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        int n = history.size()-1;
        while(n>curr){
            history.pop_back();
            n--;
        }
        history.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        while(curr>0 && steps>0){
            curr--;
            steps--;
        }
        return history[curr];
    }
    
    string forward(int steps) {
        while(curr < history.size()-1 && steps>0){
            curr++;
            steps--;
        }
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */