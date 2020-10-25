#include <iostream>
#include <cmath>

int collectNeededFood(int neededFood, int n, int price) {
    int roundCount = 0;
    int minRoundCount = 0;
    int foodCollected = 0;
    while (foodCollected < neededFood && roundCount <= minRoundCount) {
        roundCount++;
        foodCollected += n;
        if (roundCount + std::ceil((neededFood - foodCollected) / n) < minRoundCount || minRoundCount == 0) {
            minRoundCount = roundCount + std::ceil((double)(neededFood - foodCollected) / n);
        }
        n += foodCollected / price;
        foodCollected = foodCollected % price;
    }
    minRoundCount = std::min(roundCount, minRoundCount);
    return minRoundCount;
}

int main() {
    std::cout << collectNeededFood(5, 2, 1) << std::endl;
    system("pause");
}