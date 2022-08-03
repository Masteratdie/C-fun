#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {

    vector<int> randIndex;
    int random;
    srand(time(NULL));
    int key;

    while (randIndex.size() != 52) {
        random = rand() % 52 + 1;
        key = random;

        if (find(randIndex.begin(), randIndex.end(), key) != randIndex.end()) {

        }
        else {
            randIndex.push_back(random);
            cout << random << endl;
        }
    }
    
}