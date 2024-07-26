int candy(vector<int>& ratings) {
    vector<int> candies(ratings.size(), 1);
    // left neighbour
    for(int i = 1; i<ratings.size(); i++){
        if(ratings[i-1]<ratings[i]){
            candies[i] = candies[i-1] + 1;
        }
    }
    // Right neighbour
    for(int i = ratings.size()-2; i>=0; i--){
        if(ratings[i]>ratings[i+1]){
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }
    int totalCandies = 0;
    for(int candy:candies){
        totalCandies+=candy;
    }

    return totalCandies;
}
