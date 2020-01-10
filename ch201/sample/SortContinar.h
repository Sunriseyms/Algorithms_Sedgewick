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

    static vector<T> MergeSort(vector<T> list);

    static vector<T> MergeBuSort(vector<T> list);

private:
    static vector<T> auxiliaryVec;

    static void Merge(vector<T> &list, int lowPostion, int midPostion, int highPostion);

    static void MergeSort(vector<T> &list, int lo, int hi);
};

template<class T> vector<T> SortContinar<T>::auxiliaryVec;

// 选择排序
template<class T>
vector<T> SortContinar<T>::ChooseSort(vector<T> list) {
    vector<T> result(list);
    for (int i = 0; i < result.size(); ++i) {
        int min = i;
        for (int j = i + 1; j < result.size(); ++j) {
            // 找到最小的元素下标
            if (less<T>()(result[j], result[min])) {
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
        h = h / 3;
    }
    return result;
}

/**
 * 归并排序： 合并操作
 * @tparam T
 * @param list
 * @param lowPostion
 * @param midPostion
 * @param highPostion
 */
template<class T>
void SortContinar<T>::Merge(vector<T> &list, int lowPostion, int midPostion, int highPostion) {
    int i = lowPostion, j = midPostion + 1;
    for (int k = lowPostion; k <= highPostion; k++) {
        auxiliaryVec[k] = list[k];
    }

    for (int k = lowPostion; k <= highPostion; k++) {
        if (i > midPostion) { // 当左边元素已都排序到原容器中，直接将右半边部分剩余的元素添加到原容器中。
            list[k] = auxiliaryVec[j++];
        } else if (j > highPostion) { // 当右边元素已都排序到原容器中，直接将左半边部分剩余的元素添加到原容器中。
            list[k] = auxiliaryVec[i++];
        } else if (less<T>()(auxiliaryVec[j], auxiliaryVec[i])) { // 将小的元素更新到原容器中。
            list[k] = auxiliaryVec[j++];
        } else {
            list[k] = auxiliaryVec[i++];
        }
    }
}

/**
 * 归并排序： 归并排序，递归函数
 * @tparam T
 * @param list
 * @param lo
 * @param hi
 */
template<class T>
void SortContinar<T>::MergeSort(vector<T> &list, int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int mid = lo + (hi - lo) / 2;
    MergeSort(list, lo, mid);
    MergeSort(list, mid + 1, hi);
    Merge(list, lo, mid, hi);
}

/**
 *  归并排序： 递归归并(自顶向下归并排序)
 * @tparam T
 * @param list
 * @return
 */
template<class T>
vector<T> SortContinar<T>::MergeSort(vector<T> list) {
    vector<T> result(list);
    auxiliaryVec.clear();
    auxiliaryVec.insert(auxiliaryVec.end(), list.begin(), list.end());
    MergeSort(result, 0, result.size() - 1);
    return result;
}

/**
 * 归并排序： 非递归排序（自底向上归并排序）
 * @tparam T
 * @param list
 * @return
 */
template<class T>
vector<T> SortContinar<T>::MergeBuSort(vector<T> list) {
    auxiliaryVec.clear();
    auxiliaryVec.insert(auxiliaryVec.end(), list.begin(), list.end());
    vector<T> result(list);

    // 1 2 4 8的顺序进行归并
    for (int i = 1; i <= auxiliaryVec.size(); i = i + i) {
        for (int lo = 0; lo < auxiliaryVec.size(); lo = lo + i + i) {
            int high = (lo + i + i - 1) > (auxiliaryVec.size() - 1) ? (auxiliaryVec.size() - 1) : (lo + i + i - 1);
            Merge(result, lo, lo + i - 1, high);
        }
    }
    return result;
}


#endif //ALGORITHMS_SEDGEWICK_SORTCONTINAR_H
