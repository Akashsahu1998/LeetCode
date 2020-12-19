
// Question) 1475. Final Prices With a Special Discount in a Shop.


// Implementation

// 1st Approach in C++
// Time Complexity = O(N^2), Space Complexity = O(1)

vector<int> finalPrices(vector<int>& prices) {
    for(int itr = 0; itr < prices.size(); itr++){
        for(int jtr = itr+1; jtr < prices.size(); jtr++){
            if(prices[itr] >= prices[jtr]){
                prices[itr] -= prices[jtr];
                break;
            }                    
        }
    }
    return prices;
}


// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

vector<int> finalPrices(vector<int>& prices) {
    vector<int> vect;
    for(int itr = 0; itr < prices.size(); itr++){
        while(vect.size() && prices[vect.back()] >= prices[itr]){
            prices[vect.back()] -= prices[itr];
            vect.pop_back();
        }
        vect.push_back(itr);
    }
    return prices;
}
