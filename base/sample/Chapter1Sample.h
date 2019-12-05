//
// Created by y00455335 on 2019/12/5.
//

#ifndef ALGORITHMS_SEDGEWICK_CHAPTER1SAMPLE_H
#define ALGORITHMS_SEDGEWICK_CHAPTER1SAMPLE_H

#include <vector>

class Chapter1Sample {
public:
    void Run();

private:
    int Rank(int key, const std::vector<int> &v);

    int Log(int N);

    int LargesetCommonDivisor(int m, int n);
};


#endif //ALGORITHMS_SEDGEWICK_CHAPTER1SAMPLE_H
