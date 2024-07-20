class StockSpanner {
private:
    stack<pair<int, int>> st; // value, span
public:
    StockSpanner() { 
    }
    
    int next(int price) {
        // by default 1 becuase we consider today's day
        int span = 1;

        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};