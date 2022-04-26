#include <iostream>
#include <vector>
using namespace std;

class RandomNumberGen {
    int size;
    int last;
    vector<int> v;
public:
    RandomNumberGen(int n) {
        size = n;
        last = n - 1;
        v.resize(size);
        for (int i = 0 ; i < n; i++) {
            v[i] = i;
        }
    }
    int generate();
};

int RandomNumberGen::generate() {
    int idx = rand() % (last + 1);
    swap(v[idx], v[last]);
    int random = v[last--];
    if(last < 0) {
        last = size - 1;
    }
    return random;
}

int main() {
    int n = 10;
    RandomNumberGen rng(n);
    n *= 2;
    while(n--) {
        cout << rng.generate() << endl;
    }
    return 0;
}
