#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int len = 3;
const int alp= 52;

int return_index(char CharElement) {
    if ('A' <= CharElement && CharElement <= 'Z')
        return (CharElement - 'A');

    return (CharElement - 'a' + 26);
}
void sort_wd(std::vector<std::string*> &Bucket, int Lvl) {
    if (Bucket.empty() || (Lvl == 0))
        return;

    std::vector<std::vector<std::string*>> NextLayer(alp);
    int Index = len - Lvl;

    for (auto &CharWord : Bucket) {
        NextLayer[return_index((*CharWord)[Index])].push_back(CharWord);
    }

    int Count = 0;
    for (int i = 0; i < alp; ++i) {
        sort_wd(NextLayer[i], Lvl - 1);

        for (auto &word : NextLayer[i]) {
            Bucket[Count] = word;
            ++Count;
        }
    }
}
void bucket_sort(std::vector<std::string> &Arr, int Size) {
    std::vector<std::string*> Pointers(Size);

    for (int i = 0; i < Size; ++i) {
        Pointers[i] = &Arr[i];
    }
    sort_wd(Pointers, len);
    std::vector<std::string> AnswersChars(Size);
    for (int i = 0; i < Size; ++i) {
        AnswersChars[i] = *Pointers[i];
    }

    for (int i = 0; i < Size; ++i) {
        Arr[i] = AnswersChars[i];
    }
}


int main() {
    int N;
    std::ifstream In("input.txt");
    std::ofstream Out("output.txt");
    In >> N;
    std::vector<std::string> arr(N);
    
    for (int i = 0; i < N; i++)
        In >> arr[i];

    bucket_sort(arr, N);

    for (int i = 0; i < N; i++)
        Out << arr[i] << std::endl;

    In.close();
    Out.close();
}
