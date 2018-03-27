#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    cout << "6 8 1 7 C 4 9 2" << endl;
    string map;
    int i;
    int mana;
    char deck[4];
    int mana_need[4];
    int number_tower;
    int tower_hp[6];
    int tower_case;
    int route = 1;

    while(1) {
        getline(cin,map);

        if(map == "BEGIN") {
            while(1) {
                cin >> map;
                if (map == "END") {
                    break;
                }
                if (map == "MANA") {
                    cin >> mana;
                }
                if (map == "DECK") {
                    for(i=0; i<4; i++) cin >> deck[i];
                }
                if (map == "TOWER") {
                    cin >> number_tower;
                    cin >> tower_hp[number_tower];
                }
            }
        }
        i = 0;
        while(i < 4) {
            switch(deck[i]) {
            case '1':
                mana_need[i] = 5;
                break;
            case '7':
                mana_need[i] = 8;
                break;
            case '8':
                mana_need[i] = 5;
                break;
            case 'C':
                mana_need[i] = 7;
                break;
            case '4':
                mana_need[i] = 6;
                break;
            case '9':
                mana_need[i] = 3;
                break;
            case '6':
                mana_need[i] = 4;
                break;
            case '2':
                mana_need[i] = 3;
                break;
            }
            if (i == 3 && mana_need[i] > mana) cout << "0" << endl;
            if (mana_need[i] <= mana) {
                if (deck[i] == '9') {
                    cout << "1 9 1 1" << endl << "0" << endl;
                    mana -= mana_need[i];
                }
                if (deck[i] != '9') {
                    route += 1;

                    if (tower_hp[1] > 90 && tower_hp[2] > 90 && tower_hp[3] >90) tower_case = 0;
                    if (tower_hp[1] <= 90) tower_case = 1;
                    if (tower_hp[3] < tower_hp[1]) tower_case = 2;
                    if (tower_hp[2] <= 90 && tower_hp[1] <= 90) tower_case = 3;
                    if (tower_hp[2] <= 90 && tower_hp[3] < tower_hp[1]) tower_case =4;
                    switch (tower_case) {
                    case 0:
                        if (route%2 == 0) {
                            cout << "1 " << deck[i] << " 5 24" << endl << "0" << endl;
                            mana -= mana_need[i];
                        }
                        if (route%2 == 1) {
                            cout << "1 " << deck[i] << " 16 24" << endl << "0" << endl;
                            mana -= mana_need[i];
                        }
                        if (route == 100) route = 0;
                        break;
                    case 1:
                        cout << "1 " << deck[i] << " 5 11" << endl << "0" << endl;
                        mana -= mana_need[i];
                        break;
                    case 2:
                        cout << "1 " << deck[i] << " 16 11" << endl << "0" << endl;
                        mana -= mana_need[i];
                        break;
                    case 3:
                        cout << "1 " << deck[i] << " 8 11" << endl << "0" << endl;
                        mana -= mana_need[i];
                        break;
                    case 4:
                        cout << "1 " << deck[i] << " 13 11" << endl << "0" << endl;
                        mana -= mana_need[i];
                        break;
                    }
                }
                break;
            } else {
                i += 1;
            }
        }
    }
    return  0;
}
