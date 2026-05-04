class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size()!=goal.size())return false;

        string st=s+s;
        int final=st.find(goal);

        if(final==-1)return false;
        return true;
    }
};