
// Question) 1710. Maximum Units on a Truck


// Implementation

// 1st Approach in C++

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    for(int itr = 0; itr < boxTypes.size()-1; itr++){
        for(int jtr = itr+1; jtr < boxTypes.size(); jtr++){
            if(boxTypes[itr][1] < boxTypes[jtr][1]){
                int t1 = boxTypes[itr][0]; 
                int t2 = boxTypes[itr][1];
                
                boxTypes[itr][0] = boxTypes[jtr][0];
                boxTypes[itr][1] = boxTypes[jtr][1];
                
                boxTypes[jtr][0] = t1;
                boxTypes[jtr][1] = t2;
            }
        }
    }
    
    int count = 0, ans = 0;
    for(int itr = 0; itr < boxTypes.size(); itr++){
        if(count+boxTypes[itr][0] <= truckSize){
            count += boxTypes[itr][0];
            ans += boxTypes[itr][0]*boxTypes[itr][1];
        }
        else{
            int temp = truckSize - count;
            count += temp;
            ans += temp*boxTypes[itr][1];
        }
        if(count == truckSize) break;
    }
    return ans;
}


// 2nd Approach in C++

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &first, vector<int> &second){
        return first[1]>second[1];
    });
    
    int count = 0, ans = 0;
    for(int itr = 0; itr < boxTypes.size(); itr++){
        if(count+boxTypes[itr][0] <= truckSize){
            count += boxTypes[itr][0];
            ans += boxTypes[itr][0]*boxTypes[itr][1];
        }
        else{
            int temp = truckSize - count;
            count += temp;
            ans += temp*boxTypes[itr][1];
        }
        if(count == truckSize) break;
    }
    return ans;
}



