class Solution {
public:
  int candy(vector<int>& ratings) {
    // number of children
    int n = ratings.size(); 

    int minRating = ratings[0];
    for(int i: ratings)
      minRating = min(i, minRating);

    // map will store the ratings, will all child with that rating
    // map will be ordered, means smallest rating to largest rating
    map<int, vector<int>> pos;  // {rating, {positions of that rating}}
    for(int i = 0; i < n; i++)
    {
      if(ratings[i] != minRating)       // only child with rating greater than minRaring
        pos[ratings[i]].push_back(i);
    }

    vector<int> candies(n, 1);  // initially distributing 1 candy to all

    // x.first will be sorted in increasing order
    for(auto x: pos)
    {
      int rating = x.first;     // rating
      for(int cur: x.second)    // all child with above rating
      {
        int left = cur - 1;     // postion of left child
        int right = cur + 1;    // position of right child

        // leftRating, if left child is not presnt, rating equal to current child
        int lRating = rating;    
        if(left >= 0)
          lRating = ratings[left];

        // rightRating, if right child is not presnt, rating equal to current child
        int rRating = rating;
        if(right < n)
          rRating = ratings[right];

        // Calculating candies of current child, by observing ratings of left and right child

        if(ratings[cur] > lRating && ratings[cur] > rRating)   // if greater than both left and right ratings
          candies[cur] = 1 + max(candies[left], candies[right]);

        else if(ratings[cur] > lRating) // greater than left rating
          candies[cur] = 1 + candies[left];

        else if(ratings[cur] > rRating) // greater than right rating
          candies[cur] = 1 + candies[right];

        else   // smaller than both left and right ratings
          continue;
      }
    }

    // sum up of all the candies distributed
    int totalCandies = 0;
    for(int candy: candies)
      totalCandies += candy;
    
    return totalCandies;
  }
};