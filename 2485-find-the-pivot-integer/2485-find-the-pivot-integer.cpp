// class Solution {
// public:
//     int pivotInteger(int n) {
//         int left = 0;
//         int right = (n * (n + 1)) / 2;
//         int i = 1;
//         while(left < right)
//         {
//             left += i;
//             // cout<<i<<" "<<left<<" "<<right<<endl;
//             if(left == right)
//                 return i;
//             right -= i;
//             i++;
//         }
//         return -1;
//     }
// };

class Solution {
 public:
  int pivotInteger(int n) {
        const int sum = (n * (n + 1) / 2);
        const int pivot = sqrt(sum);
        // If pivot * pivot is equal to sum (pivot found) return pivot, else return -1
        return pivot * pivot == sum ? pivot : -1;
  }
};