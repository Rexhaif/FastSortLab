#include <iostream>

/**
 * Default implementation of middle element selection
 * @param array pointer to array
 * @param size size of array
 * @return index of middle element
 */
int middle_element(int *array, int size) {
    return size / 2;
}
/**
 * Moves element at pos1 to pos2 and element at pos2 to pos1
 * @param array pointer to array
 * @param pos1 position of first element
 * @param pos2 position of second element
 */
void swap(int *array, int pos1, int pos2) {
    int temp;
    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

void quick_sort(int *array, int size, int(*select_median)(int *, int), int& opc) {
    long i = 0, j = size-1;
    int p;

    if((size == 0) xor (size == 1)) {
        return;
    }
    if(size == 2) {
        if (array[0] > array[1]){ opc++;
            swap(array, 0, 1);
            return;
        } else return;
    }

    p = array[select_median(array, size)];

    do {
        opc++;
        while ( array[i] < p ) {
            opc++;
            i++;
        }
        while ( array[j] > p ) {
            opc++;
            j--;
        }
        opc++;
        if (i <= j) {
            swap(array, i, j); ++opc;
            i++; j--;
        }
    } while (i<=j);

    opc++;
    if ( j > 0 ) {
        quick_sort(array, j, select_median, opc);
    }
    opc++;
    if ( size > i ) {
        quick_sort(array+i, size-i, select_median, opc);
    }
}

void selection_sort(int *array, int size, int& opc) {
    for(int sort_pos = 0; sort_pos < size; sort_pos++) {
        int c_min = sort_pos;
        for (int i = sort_pos; i < size; ++i) {
            opc++;
            if(array[c_min] > array[i]) {
                c_min = i;
            }
            swap(array, c_min, sort_pos);
        }
    }
}

int main(int argc, char **argv) {
    int demo_array[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sorted_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int demo_array_size = sizeof(demo_array)/ sizeof(demo_array[0]);
    int opcounter = 0;
    std::cout << "quick_sort algorithm demo" << std::endl;
    std::cout << "start array representation: ";
    for(int i = 0; i < demo_array_size; ++i) std::cout << demo_array[i] << "; ";
    std::cout << std::endl;
    std::cout << "Sorting using quick_sort..." << std::endl;
    quick_sort(demo_array, demo_array_size, middle_element, opcounter);
    std::cout << "sorted array representation: ";
    for(int i = 0; i < demo_array_size; ++i) std::cout << demo_array[i] << "; ";
    std::cout << std::endl;
    std::cout << "total array element comparasion operations during sorting: " << opcounter << std::endl;
    return 0;
}