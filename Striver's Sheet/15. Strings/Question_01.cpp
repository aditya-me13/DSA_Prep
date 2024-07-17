class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int j = 0;
        string temp, ans;

        while(j < s.size()){
            if(s[j]==' '){
                j++;
                continue;
            }
            temp = "";
            while(s[j] != ' ' && j < s.size()){
                temp += s[j];
                j++;
            }
            st.push(temp);
        }

        ans = st.top();
        st.pop();
        while(!st.empty()){
            ans = ans + ' ' + st.top();
            st.pop();
        }

        return ans;
    }
};