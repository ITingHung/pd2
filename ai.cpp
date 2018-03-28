#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    cout << "6 8 1 5 C 4 9 2" << endl;
    string map;
    int i;
    int j;
    int mana;
    char deck[4];
    int mana_need[4];
    int tower_rank;
    int tower_number;
    int tower_hp[6];
    int tower_case;
    char card_exist[8];
    string AT;
    char card_position[8][5];
    string HP;
    int card_hp[8];
    int card_number = 0;
    int route = 1;
    int X;
    int Y;
    int X2;
    int Y2;

    while(1) {
        getline(cin,map);

        if(map == "BEGIN") {
            while(1) {
                cin >> map;
                if (map == "END") {
                    i = 0;
                    break;
                }
                if (map == "MANA") {
                    cin >> mana;
                }
                if (map == "DECK") {
                    for(i=0; i<4; i++) cin >> deck[i];
                }
                if (map == "TOWER") {
                    cin >> tower_rank;
                    tower_number = tower_rank-1;
                    cin >> tower_hp[tower_number];
                }
                if (map == "FRIEND") {
                    cin >> card_exist[card_number];
                    cin >> AT;
                    cin >> card_position[card_number];
                    cin >> HP;
                    cin >> card_hp[card_number];
                    card_number += 1;
                }
            }
        }

        while(i < 4) {
            int frag = 0;
            // Make sure not to cout the card that is already existing on map
            for (j=0; j<card_number; j++) {
                if (card_exist[j] == deck[i]) {
                    if (i == 3) {
                        cout << "0" << endl;
                        frag = 1;
                        break;
                    }
                    i += 1;
                    frag = 1;
                    break;
                }
            }
            if(frag) break;
            // Check out how many mana does this card cost
            switch(deck[i]) {
            case '1':
                mana_need[i] = 5;
                break;
            case '5':
                mana_need[i] = 1;
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
            // If this turn is unable to cout a card, then cout 0
            if (i == 3 && mana_need[i] > mana) cout << "0" << endl;
            // Check out if mana is big enough to cout a card
            if (mana_need[i] <= mana) {
                // Set up card 9's initial position
                if (deck[i] == '9' && tower_hp[0] > 80 && tower_hp[1] >80 && tower_hp[2] > 80) {
                    cout << "1 9 1 1" << endl << "0" << endl;
                    mana -= mana_need[i];
                }
                // Set up other card's initial posion
                if (deck[i] != '9') {
                    route += 1;
                    // Check out if any tower need help
                    if (tower_hp[0] > 90 && tower_hp[1] > 90 && tower_hp[2] >90) tower_case = 0;
                    if (tower_hp[0] <= 90) tower_case = 1;
                    if (tower_hp[2] < tower_hp[0]) tower_case = 2;
                    if (tower_hp[1] <= 90 && tower_hp[0] <= 90) tower_case = 3;
                    if (tower_hp[1] <= 90 && tower_hp[2] < tower_hp[0]) tower_case =4;
                    switch (tower_case) {
                    case 0:
                        if (route%2 == 0) {
                            X = 5;
                            Y = 24;
                            for(j=0; j<8; j++) {
                                if (card_position[j] == "X,Y") {
                                    if (X=8) Y += 1;
                                    if (X<8) X += 1;
                                }
                            }
                            cout << "1 " << deck[i] << " " << X << " " << Y << endl << "0" << endl;
                            mana -= mana_need[i];
                        }
                        if (route%2 == 1) {
                            X2 = 16;
                            Y2 = 24;
                            for(j=0; j<8; j++) {
                                if (card_position[j] == "X2,Y2") {
                                    if (X2=8) Y2 += 1;
                                    if (X2<8) X2 += 1;
                                }
                            }
                            cout << "1 " << deck[i] << " " << X2 << " " << Y2 <<  endl << "0" << endl;
                            mana -= mana_need[i];
                        }
                        if (route == 100) route = 0;
                        break;
                    case 1:
                        X = 5;
                        Y = 11;
                        for(j=0; j<8; j++) {
                            if (card_position[j] == "X,Y" ) {
                                if (X=7) Y += 1;
                                if (X<8) X += 1;
                            }
                        }
                        cout << "1 " << deck[i] << " " << X << " " << Y << endl << "0" << endl;
                        mana -= mana_need[i];
                        break;
                    case 2:
                        X = 16;
                        Y = 11;
                        for(j=0; j<8; j++) {
                            if (card_position[j] == "X,Y") {
                                if (X=14) Y += 1;
                                if (X>13) X += 1;
                            }
                        }
                        cout << "1 " << deck[i] << " " << X << " " << Y << endl << "0" << endl;
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
                i = 4;
                break;
            } else {
                i += 1;
            }
        }
    }
    return  0;
}
