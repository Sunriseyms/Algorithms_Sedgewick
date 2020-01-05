//
// Created by summer on 2020/1/5.
//

#ifndef ALGORITHMS_SEDGEWICK_SORTCONTINAR_H
#define ALGORITHMS_SEDGEWICK_SORTCONTINAR_H

#include <vector>
#include <functional>

using namespace std;

template <class T>
class SortContinar {
public:
    static vector<T> ChooseSort(vector<T> list);
    static vector<T> InsertSort(vector<T> list);
    static vector<T> ShellSort(vector<T> list);
};

// 选择排序
template<class T>
vector<T> SortContinar<T>::ChooseSort(vector<T> list) {
    vector<T> result(list);
    for(int i = 0; i < result.size(); ++i) {
        int min = i;
        for (int j = i+1; j < result.size(); ++j) {
            // 找到最小的元素下标
            if (less<T>()(result[j], result[min])){
                min = j;
            }
        }
        // 与当前元素交换
        swap(result[i], result[min]);
    }
    return result;
}

// 插入排序,当大部分有序时，采用改方法
template<class T>
vector<T> SortContinar<T>::InsertSort(vector<T> list) {
    vector<T> result(list);
    for(int i = 0; i < result.size(); ++i) {
        // 将当前元素插入到合适位置
        for (int j =  i; j > 0; --j) {
            if (less<T>()(result[j], result[j-1])) {
                swap(result[j-1], result[j]);
            } else {
                break;
            }
        }
    }
    return result;
}

// 希尔排序
// 插入排序的改进版本，先按照步长为h进行插入排序，避免插入排序只能相邻交换
// h有序数组：h个互相独立的有序数组编织在一起组成的一个数组
template<class T>
vector<T> SortContinar<T>::ShellSort(vector<T> list) {
    vector<T> result(list);
    int h = 1;
    // 这里使用的是实时步长，也可以使用静态的数组来替代（这个也叫递增序列）
    while (h < result.size()/3) {
        h = 3*h +1;
    }

    while (h >= 1) {
        // 使用步长h，进行排序；最后步长降为为1时，整个序列也就是有序的了。
        for(int i = h; i < result.size(); ++i) {
            for (int j=i; j >= h ; j -= h) {
                if (less<T>()(result[j], result[j-h])) {
                    swap(result[j-h], result[j]);
                } else {
                    break;
                }
            }
        }
        h = h/3;
    }
    return result;
}


#endif //ALGORITHMS_SEDGEWICK_SORTCONTINAR_H
