#include <stdlib.h>
#include <stdio.h>

struct Soldier {
    float height;
    char name[256];
};

struct Soldier *ArrBuff;

long long _mergeSort(struct Soldier arr[], struct Soldier ArrBuff[], int left, int right);
long long merge(struct Soldier arr[], struct Soldier ArrBuff[], int left, int mid, int right);
long long mergeSort(struct Soldier arr[], int array_size);

int main() {
    FILE *InPut = fopen("input.txt", "r");
    FILE *OutPut = fopen("output.txt", "w");

    int CountSoldier;
    fscanf(InPut, "%d", &CountSoldier);

    struct Soldier *Arr = (struct Soldier *) malloc(sizeof(struct Soldier) * CountSoldier);

    for (int i = 0; i < CountSoldier; i++) {
        fscanf(InPut, "%f %s", &Arr[i].height, Arr[i].name);
    }

    long long ans = mergeSort(Arr, CountSoldier);

    fprintf(OutPut, "%lld", ans);

    free(Arr);
    free(ArrBuff);
    fclose(InPut);
    fclose(OutPut);

    return 0;
}

long long mergeSort(struct Soldier arr[], int array_size) {
    ArrBuff = (struct Soldier *) malloc(sizeof(struct Soldier) * array_size);
    return _mergeSort(arr, ArrBuff, 0, array_size - 1);
}

long long _mergeSort(struct Soldier arr[], struct Soldier ArrBuff[], int left, int right) {
    int mid;
    long long inv_count = 0;

    if (right > left) {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, ArrBuff, left, mid);
        inv_count += _mergeSort(arr, ArrBuff, mid + 1, right);
        inv_count += merge(arr, ArrBuff, left, mid + 1, right);
    }

    return inv_count;
}

long long merge(struct Soldier arr[], struct Soldier ArrBuff[], int left, int mid, int right) {
    int i, j, k;
    long long inv_count = 0;
    i = left;
    j = mid;
    k = left;

    while (i <= mid - 1 && j <= right) {
        if (arr[i].height >= arr[j].height) {
            ArrBuff[k++] = arr[i++];
        } else {
            ArrBuff[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }

    while (i <= mid - 1) {
        ArrBuff[k++] = arr[i++];
    }

    while (j <= right) {
        ArrBuff[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = ArrBuff[i];
    }

    return inv_count;
}
