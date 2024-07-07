int numWaterBottles(int numBottles, int numExchange) {
    int consumedBottles = 0;
    while(numBottles>=numExchange){
        consumedBottles += numExchange;
        numBottles += 1 - numExchange;
    }

    return consumedBottles+numBottles;
}
