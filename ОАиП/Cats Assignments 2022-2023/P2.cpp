#include <iostream>
#include <vector>
#include <algorithm>

struct Pair{
    int value;
    int count;
};

bool operator < (const long long value, const Pair &pair){
    return value < pair.value;
}
int main(){
    FILE *in;
    FILE *out;

    in = fopen("game.in", "r");
    int n,times;
    fscanf(in,"%d %d",&n, &times);
    std::vector<Pair> a(n, Pair{0,1});

    for(int i = 0; i<n; i++){
        fscanf(in,"%d", &a[i].value);
    }
    std::sort(a.begin(), a.end(), [](const Pair &left, const Pair &right){
        return left.value < right.value;
    });

    int dst = 0;
    for(int src = 1; src < (int)a.size(); src++){
        if(a[src].value == a[dst].value){
            a[dst].count += a[src].count;
        }else{
            dst++;
            a[dst]= a[src];
        }
    }

    a.resize(dst + 1);
    long long ans = 0;
    std::vector<Pair> a2;

    for(int i=0; i<(int)a.size(); i++){
        if(a[i].count >= 3){
            ans++;
        }
        if(a[i].count >= 2){
            a2.push_back(a[i]);
        }
    }

    //a b b
    for(int i=0; i < (int)a.size(); i++ ){ //low
        long long lo = a[i].value;
        long long hi = lo * times;
        ans += 3 * (std::upper_bound(a2.begin(), a2.end(), hi) - std::upper_bound(a2.begin(), a2.end(), lo));
    }

    //a a b
    for(int i=0; i < (int)a2.size(); i++ ){ //low
        long long lo = a2[i].value;
        long long hi = lo * times;
        ans += 3 * (std::upper_bound(a.begin(), a.end(), hi) - std::upper_bound(a.begin(), a.end(), lo));
    }

    for(int i=0; i < (int)a.size(); i++ ){ //low
        long long lo = a[i].value;
        long long hi = lo * times;
       long long len = (std::upper_bound(a2.begin(), a2.end(), hi) - std::upper_bound(a2.begin(), a2.end(), lo));

       if(len >= 2){
           ans += 6 *(len*(len-1)/2);
       }
    }
    fclose(in);

    out = fopen("game.out", "w");
    fprintf(out, "%d", ans);
    fclose(out);



    return 0;
}