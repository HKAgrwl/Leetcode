class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maxAltitude = 0;
        for(auto x : gain){
            altitude = altitude + x;
            if(altitude > maxAltitude) maxAltitude = altitude;
        }
        return maxAltitude;
    }
};