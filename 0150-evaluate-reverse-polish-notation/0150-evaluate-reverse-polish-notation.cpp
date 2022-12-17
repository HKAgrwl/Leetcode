class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long int> polish;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" ||tokens[i]=="-" ||tokens[i]=="*" ||tokens[i]=="/" ){
                long int second = polish.top();
                polish.pop();
                long int first = polish.top();
                polish.pop();
                if(tokens[i]=="+"){
                    long int ans = first+second;
                    polish.push(ans);
                }
                if(tokens[i]=="-"){
                    long int ans = first-second;
                    polish.push(ans);
                }
                if(tokens[i]=="*"){
                    long int ans = first*second;
                    polish.push(ans);
                }
                if(tokens[i]=="/"){
                    long int ans = first/second;
                    polish.push(ans);
                }
            }
            else{
                long int ans = stoi(tokens[i]);
                polish.push(ans);
            }
        }
        return polish.top();
    }
};