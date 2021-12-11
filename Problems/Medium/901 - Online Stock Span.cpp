
// Question) 901. Online Stock Span


// Implementation

// Using Stack
// Time Complexity = O(N), Space Complexity = O(N)
class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while(!s.empty() && s.top().first <= price){
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};
