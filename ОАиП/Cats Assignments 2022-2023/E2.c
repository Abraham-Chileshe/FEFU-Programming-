#include <stdio.h>

struct sodier_formation{
    float s_height; // soldier height
    char s_name[256]; // soldier name;
};

void Sort(struct sodier_formation  Arr[], int , int); //Merge Sort

//struck variables
struct sodier_formation Arr[100000];
struct sodier_formation ArrBuff[100000];
//---------

int main() {
    int cntsoldier; // count soldiers
    FILE *IN = fopen("input.txt", "r");
    FILE *OUT = fopen("output.txt", "w");

    fscanf(IN, "%d", &cntsoldier);
    for (int i = 0; i < cntsoldier; i++)
        fscanf(IN, "%f %s", &Arr[i].s_height, &Arr[i].s_name);

    Sort(Arr, 0, cntsoldier - 1);

    for (int i = 0; i < cntsoldier; i++)
        fprintf_s(OUT, "%s\n", Arr[i].s_name);


    return 0;
}


void Sort(struct sodier_formation  Arr[], int l, int r){
    if (l == r) return;
    int mid = (l + r) / 2;
    Sort(Arr, l, mid);
    Sort(Arr, mid + 1, r);
    int i = l; int j = mid + 1;
    for (int step = 0; step < r - l + 1; step++)
    {
        if ((j > r) || ((i <= mid) && (Arr[i].s_height >= Arr[j].s_height)))
        {
            ArrBuff[step] = Arr[i];
            i++;
        }
        else{
            ArrBuff[step] = Arr[j];j++;}
    }
    for (int step = 0; step < r - l + 1; step++) Arr[l + step] = ArrBuff[step];
}