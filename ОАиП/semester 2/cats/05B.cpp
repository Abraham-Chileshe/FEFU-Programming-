#include <iostream>
#include <fstream>

void heapify(int *array, int count, int index){

    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if(left < count && array[left] > array[largest])
        largest = left;
    if(right < count && array[right] > array[largest])
        largest = right;
    if(largest != index){
        std::swap(array[index], array[largest]);
        heapify(array,count,largest);
    }
}

void heap(int *array, int count){
    for(int i = count / 2 - 1; i >= 0; i--)
        heapify(array,count,i);
}

void changeMax(int *array, int count){
    array[0] /= 10;
    heapify(array,count,0);
}

int main() {
    std::ifstream Input("input.txt");
    std::ofstream Output("output.txt");
    
    int ChildCnt;
    int drinkCnt;
    Input >> ChildCnt >> drinkCnt;
    
    int *thrust = new int [ChildCnt];
    for(int i = 0; i < ChildCnt; i++)
        Input >> thrust[i];
    heap(thrust,ChildCnt);
    
    
    for(int i = 0; i < drinkCnt; i++)
        changeMax(thrust,ChildCnt);
    
    uint64_t sum = 0;
    for(int i = 0; i < ChildCnt; i++)
        sum += thrust[i];
    
    Output << sum;
    return 0;
}
