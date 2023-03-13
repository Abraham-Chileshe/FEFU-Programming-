#include <iostream>
#include <algorithm>
#include <fstream>

struct IndexObject {
    std::string Number;
    int StraightLinesInNum;
    int SlopingLinesInNum;
};

bool find_String(std::string &Fstring, std::string &Sstring);

int main() {
    std::fstream IN("input.txt");
    std::ofstream OUT("output.txt");

    int StraightLines;
    int SlopingLines;

    IN >> StraightLines;
    IN >>SlopingLines;

    auto **Otvet = new std::string *[StraightLines + 1];

    for (int i = 0; i <= StraightLines; i++) {
        Otvet[i] = new std::string[SlopingLines + 1];
        fill(&Otvet[i][0], &Otvet[i][SlopingLines + 1], "-1");
    }

    IndexObject LinsSlant[8] = {
            {"0", 6, 0},
            {"1", 2, 1},
            {"2", 3, 1},
            {"3", 2, 2},
            {"4", 4, 0},
            {"5", 5, 0},
            {"6", 4, 1},
            {"8", 7, 0},
    };

    for (auto &Digit: LinsSlant) {
        if (Digit.Number == "0")
            continue;
        if (Digit.StraightLinesInNum <= StraightLines && Digit.SlopingLinesInNum <= SlopingLines)
            Otvet[Digit.StraightLinesInNum][Digit.SlopingLinesInNum] = Digit.Number;
    }

    for (int i = 0; i <= StraightLines; i++) {
        for (int j = 0; j <= SlopingLines; j++) {
            std::string NewValue = Otvet[i][j];
            for (auto &Digit: LinsSlant) {
                int prev_y = i - Digit.StraightLinesInNum, prev_x = j - Digit.SlopingLinesInNum;
                if (prev_y >= 0 && prev_x >= 0) {
                    auto PrevNum = Otvet[prev_y][prev_x];
                    auto this_num = PrevNum + Digit.Number;
                    if (PrevNum != "-1" && (NewValue == "-1" or find_String(this_num, NewValue)))
                        NewValue = this_num;
                }
            }
            Otvet[i][j] = NewValue;
        }
    }

    if (Otvet[StraightLines][SlopingLines] == "-1")
        OUT << "Wrong";
    else
       OUT << Otvet[StraightLines][SlopingLines];


    return 0;

}


bool find_String(std::string &Fstring, std::string &Sstring) {
    if (Fstring.size() < Sstring.size())
        return true;
    else if (Sstring.size() < Fstring.size())
        return false;

    for (int i = 0; i < Fstring.size(); i++) {
        if (int(Fstring[i]) < int(Sstring[i]))
            return true;
        else if (int(Fstring[i]) > int(Sstring[i]))
            return false;
    }
    return false;
}
