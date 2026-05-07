#include <unordered_map>
#include <string>

class Solution {
public:
    // The logic must go INSIDE this function
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> charCounts;
        
        // Count frequencies in the magazine
        for (char c : magazine) {
            charCounts[c]++;
        }
        
        // Subtract frequencies using the ransom note
        for (char c : ransomNote) {
            // If the character doesn't exist, it defaults to 0, then subtracts to -1
            if (--charCounts[c] < 0) {
                return false;
            }
        }
        
        return true;
    }
};