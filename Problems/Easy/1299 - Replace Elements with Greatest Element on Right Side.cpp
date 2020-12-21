
// Question) 1299. Replace Elements with Greatest Element on Right Side.


// Implementation

// 1st Approach in C++
// Time Complexity = O(N^2), Space Complexity = O(1)

vector<int> replaceElements(vector<int>& arr) {
    if(arr.size() == 1) {
        arr[0] = -1;
        return arr;
    }
    int Max, itr, jtr, pos, flag = 0;
    for(itr = 0; itr < arr.size(); itr++){
        pos = itr;
        Max = arr[itr];
        for(jtr = itr+1; jtr < arr.size(); jtr++){
            if(arr[jtr] > Max){
                Max = arr[jtr];
                pos = jtr;
            }                
        }
        
       if(flag == 0){
           if(pos == itr+1){
               flag = 1;
               for(jtr = itr+1; jtr < arr.size(); jtr++){
                   arr[jtr-1] = arr[jtr];
               }
               arr[jtr-1] = -1;
           }
           else{
                arr[itr] = Max;
            }
       }
        else{
            arr[itr] = Max;
        }
    }
        return arr;
}


// 2nd Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

vector<int> replaceElements(vector<int>& arr) {
    int temp, Max = -1;
    for(int itr = arr.size()-1; itr > -1; itr--){
        // Max = max(Max, exchange(arr[itr], Max));
        temp = arr[itr];
        arr[itr] = Max;
        Max = max(Max, temp);
    }
    return arr;
}
