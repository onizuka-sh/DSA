class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer;
        int depth=0;

        for(auto x:s){
            if(x=='('){
                if(depth>0)answer+=x;
                depth++;
            }else{
                depth--;
                if(depth>0)answer+=x;
            } 
        }
        return answer; 
    }
};