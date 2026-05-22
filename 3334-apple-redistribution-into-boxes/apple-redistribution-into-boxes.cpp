class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int totalApples = 0;

        // Total apples count
        for(int x : apple){
            totalApples += x;
        }

        // Sort capacities in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());

        int boxes = 0;
        int currentCapacity = 0;

        // Take biggest boxes first
        for(int cap : capacity){

            currentCapacity += cap;
            boxes++;

            if(currentCapacity >= totalApples){
                return boxes;
            }
        }

        return boxes;
    }
};