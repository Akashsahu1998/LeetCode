
// Question) 818. Race Car


// Implementation

// BFS Approach 
// Using Queue & Unordered Set
// Time Complexity : O(N * NlogN), where N is the Target
// Space Complexity : O(N)

// https://www.youtube.com/watch?v=_Fm9JZDLYHg

// creating this class bcz of the modularity of the code, otherwise we could have taken the queue with pair as well.
class CarAttributes{
private:
    int position, speed;
    
public:
    CarAttributes(int position, int speed){
        this->position = position;
        this->speed = speed;
    }
    
    void setPosition(int position){
        this->position = position;
    }
        
    int getPosition(){
        return position;   
    }
    
    void setSpeed(int speed){
        this->speed = speed;
    }
    
    int getSpeed(){
        return speed;   
    }
};

class Solution {
public:
    int racecar(int target) {
        int minNumberOfInstructionsCount = 0;
        
        queue<CarAttributes> bfsQueue;
        
        // to store the visited values
        unordered_set<string> visitedSet;
        
        string key = to_string(0) + ',' + to_string(1);
        visitedSet.insert(key);
        
        // position and speed
        bfsQueue.push(CarAttributes(0, 1));
        
        while(!bfsQueue.empty()){
            int size = bfsQueue.size();
            
            for(int i = 0; i < size; i++){
                CarAttributes front = bfsQueue.front();
                bfsQueue.pop();
                
                int curPosition = front.getPosition();
                int curSpeed = front.getSpeed();
                
                // if our car(curPosition of car) reached the target, then return the result
                if(curPosition == target){
                    return minNumberOfInstructionsCount;
                }
                
                // let's explore both possibilites, Accelerate & Reverse
                
                // Accelerate(A)
                int newPosition = curPosition + curSpeed;
                int newSpeed = curSpeed * 2;
                
                // let's check whether the newPosition & newSpeed is visited or not
                key = to_string(newPosition) + ',' + to_string(newSpeed);
                if(visitedSet.find(key) == visitedSet.end()){
                    
                    // checking if our new position is close to our target or not, bcz there is no sense of going beyond target, if we are going beyong we will never reach to target, bcz target will left back.
                    if(abs(target - newPosition) < target){
                        visitedSet.insert(key);
                        bfsQueue.push(CarAttributes(newPosition, newSpeed));
                    }                    
                }
                    
                    
                // Reverse(R)
                newPosition = curPosition;
                newSpeed = curSpeed < 0 ? 1 : -1;
                
                // let's check whether the newPosition & newSpeed is visited or not
                key = to_string(newPosition) + ',' + to_string(newSpeed);
                if(visitedSet.find(key) == visitedSet.end()){
                    
                    // checking if our new position is close to our target or not, bcz there is no sense of going very far from target, if we are going very far, we will never reach to target, bcz target will be far.
                    if(abs(target - newPosition) < target){
                        visitedSet.insert(key);
                        bfsQueue.push(CarAttributes(newPosition, newSpeed));
                    }  
                }
            }
            
            // if we didn't found the target in the one level of the queue, then we will increase the minNumberOfInstructionsCount
            minNumberOfInstructionsCount++;
        }
        
        return -1;
    }
};
