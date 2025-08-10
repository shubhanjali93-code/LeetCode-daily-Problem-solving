Problem link: https://leetcode.com/problems/reordered-power-of-2/?envType=daily-question&envId=2025-08-06
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = countDigits(n);
        for (int i=0; i < 30;i++){
            if (countDigits(1 << i) == target)
            return true;
        }
        return false;
    }
    private:
        string countDigits(int num){
            string count(10, '0');
            while(num) {
                count[num % 10 ]++;
                num /=10;
            }
            return count;
        }
};
