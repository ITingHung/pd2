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
    char card_exist[50];
    string AT;
    char card_position[50][5];
    string HP;
    int card_hp[50];
    int card_number = 0;
    char enemy_exist[50];
    char enemy_position[50][5];
    int enemy_hp[50];
    int enemy_number = 0;
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
                if (map == "ENEMY") {
                    cin >> enemy_exist[enemy_number];
                    cin >> AT;
                    cin >> enemy_position[enemy_number];
                    cin >> HP;
                    cin >> enemy_hp[enemy_number];
                    enemy_number += 1;
                }
            }
        }

        while(i < 4) {
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
                // Make sure no enemy card keep going ahead to our tower
                /*int leave = 0;
                for (j=0; j<enemy_number; j++) {
                    for (X=3; X<19; X++) {
                        for (Y=11 ; Y<18; Y++) {
                            if (enemy_position[j] == "X,Y") {
                                cout<< "1" << deck[i] << " " << X << " " << Y-1 << endl << "0" << endl;
                                mana -= mana_need[i];
                                leave = 1;
                                break;
                            }
                        }
                        break;
                    }
                    break;
                }
                if (leave) break;*/
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
                    //Compare the number of our card and enemy's card
                    int number;
                    if (card_number > enemy_number) number = card_number;
                    else number = enemy_number;
                    //When facing different situation, cout the card in different location
                    switch (tower_case) {
                    case 0:
                        if (route%2 == 0) {
							X = 5; Y = 24;
                            /*for(j=0; j<number; j++) {
								char position[5] = 5,24;
                                if (card_position[j] == position || enemy_position[j] == position) Change_position(5.24);
                            }*/
                            cout << "1 " << deck[i] << " " << X << " " << Y << endl << "0" << endl;
                            mana -= mana_need[i];
                        }
                        if (route%2 == 1) {
							X = 16; Y = 24;
                            /*for(j=0; j<number; j++) {
                                if (card_position[j] == "16,24" || enemy_position[j] == "16,24") Chaneg_position(16,24);
                            }*/
                            cout << "1 " << deck[i] << " " << X << " " << Y <<  endl << "0" << endl;
                            mana -= mana_need[i];
                        }
                        if (route == 100) route = 0;
                        break;
                    case 1:
						X = 5; Y = 11;
                        /*for(j=0; j<number; j++) {
                            if (card_position[j] == "5,11" || enemy_position[j] == "5,11") Change_position(5,11);
                        }*/
                        cout << "1 " << deck[i] << " " << X << " " << Y << endl << "0" << endl;
                        mana -= mana_need[i];
                        break;
                    case 2:
						X = 16; Y = 11;
                        /*for(j=0; j<number; j++) {
                            if (card_position[j] == "16,11" || enemy_position[j] == "16,11") Change_position(16,11)
						}*/
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
