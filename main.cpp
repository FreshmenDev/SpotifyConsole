#include <iostream>
#include <string>

using namespace std;

int main () {
    const int COUNT_SONGS = 20;

    const char* Songs[COUNT_SONGS];
    const char* Groups[COUNT_SONGS];
    int popSongs[COUNT_SONGS];


    const char* topSong[COUNT_SONGS];
    const char* topGroups[COUNT_SONGS];
    int popSongTop[COUNT_SONGS];

    int realCoutSongs = 0;
    int numCurrentSong = 0;

    Songs[0] = "Should I Stay or Should I Go";
    Groups[0] = "The Clash";
    popSongs[0] = 0;

    Songs[1] = "Baby don't lie to me";
    Groups[1] = "The Fratellis";
    popSongs[1] = 0;

    Songs[2] = "Ole Black 'n' Blue Eyes";
    Groups[2] = "The Fratellis";
    popSongs[2] = 0;

    Songs[3] = "Like A Champion";
    Groups[3] = "The Baseballs";
    popSongs[3] = 0;

    Songs[4] = "Jackie and Wilson";
    Groups[4] = "Hoizer";
    popSongs[4] = 0;

    Songs[5] = "Mountains";
    Groups[5] = "Message To Bears";
    popSongs[5] = 0;

    Songs[6] = "When It's Cold I'd Like to Die";
    Groups[6] = "Moby";
    popSongs[6] = 0;

    Songs[7] = "Damn Your Eyes";
    Groups[7] = "Alex Clare";
    popSongs[7] = 0;

    Songs[8] = "Heroes";
    Groups[8] = "David Bowie";
    popSongs[8] = 0;

    Songs[9] = "No Diggity";
    Groups[9] = "Chet Faker";
    popSongs[9] = 0;

    Songs[10] = "Inhaler";
    Groups[10] = "Foals";
    popSongs[10] = 0;

    Songs[11] = "London Thunder";
    Groups[11] = "Foals";
    popSongs[11] = 0;

    Songs[12] = "Spanish Sahara";
    Groups[12] = "Foals";
    popSongs[12] = 0;

    Songs[13] = "Asleep";
    Groups[13] = "The Smiths";
    popSongs[13] = 0;

    realCoutSongs = 14;

    bool workDuration = true;

    while (workDuration) { int selection = -1;

        cout << endl << "Now playing: " <<
                  Groups[numCurrentSong] << " - " << Songs[numCurrentSong] << endl;

        if (numCurrentSong > 0) {cout << "Previous song: " << Groups[numCurrentSong - 1] << " - " << Songs[numCurrentSong - 1] << endl;
        }

        if (numCurrentSong <realCoutSongs - 1) {
            cout << "Next song: " << Groups[numCurrentSong + 1] << " - " << Songs[numCurrentSong + 1] << endl;
        }


        cout << "Enter action you want to make: " << endl;
        cout << "1) Play next" << endl;
        cout << "2) Play prev" << endl;
        cout << "3) Group by band" << endl;
        cout << "4) Group by song name" << endl;
        cout << "5) Search song by band " << endl;
        cout << "6) Search song by name " << endl;
        cout << "7) Show playlist " << endl;
        cout << "8) Play specific song (specified by position) " << endl;
        cout << "9) What is playing now? " << endl;
        cout << "10) Show my chart " << endl;
        cout << "11) Sort by popularity " << endl;
        cout << "12) Show the most popular band " << endl;
        cout << "13) Exit " << endl;

        cin >> selection;

        cin.ignore();

        switch (selection) {
            case 1: {
                if (numCurrentSong != realCoutSongs - 1) {
                    ++numCurrentSong;
                    ++popSongs[numCurrentSong]; }
                break;
            }

            case 2: {
                if (numCurrentSong > 0)
                {
                    --numCurrentSong;
                    ++popSongs[numCurrentSong];
                }
                break;
            }

            case 3: {
                const char* TMP = Songs[numCurrentSong];
                const char* TMP2 = Groups[numCurrentSong];
                int currentPop = popSongs[numCurrentSong];


                for (int i = 1; i < realCoutSongs; ++i)
                {
                    const char* tmp =Songs[i];
                    const char* temp= Groups[i];
                    int variable = popSongs[i];

                    int j = i-1;
                    while (j> -1 && strcmp(temp, Groups[j]) != 0) {
                        Songs[j + 1] = Songs[j];
                        Groups[j +1] = Groups[j];
                        popSongs[j+1] = popSongs[j];
                        --j;
                    }

                    Songs[j+1] = tmp;
                    Groups[j+1] = temp;
                    popSongs[j + 1] = variable;
                }

                cout << "New playlist order " << endl;

                for (int i = 0; i < realCoutSongs; ++i) {
                    cout << Groups[i] << " - " << Songs[i] << endl;
                }

                for (int i = 0; i < realCoutSongs; ++i) {
                    if (strcmp(TMP2, Groups[i]) == 0
                        && strcmp(TMP, Songs[i]) == 0) {
                        numCurrentSong = i;
                        break;
                    }
                }

                cout << "Current song position: " << numCurrentSong + 1 << endl;

                cout << "Now playing: " << Groups[numCurrentSong] << " - " << Songs[numCurrentSong] << endl;

                if (numCurrentSong > 0) {
                    cout << "Previous song: " << Groups[numCurrentSong - 1] << " - " << Songs[numCurrentSong - 1] << endl;
                }

                if (numCurrentSong < realCoutSongs - 1) {
                    cout << "Next song: " << Groups[numCurrentSong + 1] << " - " << Songs[numCurrentSong + 1] << endl;
                }
                break;
            }

            case 4: {
                const char* nameCurrentSongs = Songs[numCurrentSong];
                const char* nameCurrentGroups = Groups[numCurrentSong];
                int popCurrentGroups = popSongs[numCurrentSong];

                for (int i = 1; i < realCoutSongs; ++i) {
                    const char* tempNamesSongs = Songs[i];
                    const char* tempNamesGroups = Groups[i];
                    int tempPopSongs = popSongs[i];

                    int j = i-1;
                    while (j >-1 && strcmp(tempNamesSongs,Songs[j])!=0){
                        Songs[j + 1] = Songs[j];
                        Groups[j + 1] = Groups[j];
                        popSongs[j + 1] = popSongs[j];
                        --j;}


                    Songs[j + 1] = tempNamesSongs;
                    Groups[j + 1] = tempNamesGroups;
                    popSongs[j + 1] = tempPopSongs;
                }

                cout << "New playlist order " << endl;

                for (int i = 0; i < realCoutSongs; ++i)
                {
                    cout << Groups[i] << " - " << Songs[i] << endl;
                }

                for (int i = 0; i < realCoutSongs; ++i){
                    if (strcmp(nameCurrentGroups, Groups[i]) == 0
                        && strcmp(nameCurrentSongs, Songs[i]) == 0) {
                        numCurrentSong = i;
                        break;
                    }}

                cout << "Current song position: " << numCurrentSong << endl;

                cout << "Now playing: " << Groups[numCurrentSong] << " - " << Songs[numCurrentSong] << endl;

                if (numCurrentSong > 0) {
                    cout << "Previous song: " << Groups[numCurrentSong - 1] << " - " << Songs[numCurrentSong - 1] << endl;
                }

                if (numCurrentSong < realCoutSongs - 1) {
                    cout << "Next song: " << Groups[numCurrentSong + 1] << " - " << Songs[numCurrentSong + 1] << endl;
                }
                break;
            }

            case 5: {
                string str;
                cout << "Input band name you are looking for: " << endl;
                getline(cin, str);
                bool found=false;
                for (int i=0; i<realCoutSongs; ++i) {
                    if (strcmp(str.c_str(), Groups[i]) == 0) {
                        cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << endl;
                        found = true;
                    }
                }

                if(found){
                    cout << "Now you can play any song by it position" << endl;
                } else
                {
                    cout << "There are no pesny with band name like this " << str << endl;
                }

                break;
            }

            case 6: {
                string str2;
                cout << "Input song name you are looking for: " << endl;
                getline(cin, str2);
                bool found = false;
                for (int i = 0; i < realCoutSongs; ++i) {
                    if (strcmp(str2.c_str(), Songs[i]) == 0) {
                        cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << endl;
                        found = true;
                    }
                }

                if (found)
                {
                    cout << "Now you can play any song by it position" << endl;
                }

                else {
                    cout << "There are no pesny with name like this " << str2 << endl;
                }

                break;
            }

            case 7: {
                cout << "Playlist: " << endl;
                for (int i = 0; i < realCoutSongs; ++i) {
                    cout << Groups[i] << " - " << Songs[i] << endl;
                }
                break;
            }

            case 8: {
                cout << "Ok, here is the playlist: " << endl;

                for (int i = 0; i < realCoutSongs; ++i){ 
                    cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << endl;
                }

                cout <<"Enter song position, you want to play: " << endl;

                int numSongs;

                cin >> numSongs;

                cin.ignore();

                --numSongs;

                if (numSongs > -1 && numSongs<realCoutSongs) {
                    numCurrentSong = numSongs;
                    ++popSongs[numCurrentSong];
                }

                cout << "Now playing: " << Groups[numCurrentSong] << " - " << Songs[numCurrentSong] << endl;

                if (numCurrentSong > 0) {
                    cout << "Previous song: " << Groups[numCurrentSong - 1] << " - " << Songs[numCurrentSong - 1] << endl;
                }

                if (numCurrentSong<realCoutSongs-1) {
                    cout << "Next song: " << Groups[numCurrentSong + 1] << " - " << Songs[numCurrentSong + 1] << endl;
                }

                break;
            }

            case 9: {
                cout<< "Now playing: "<< Groups[numCurrentSong] <<" - " << Songs[numCurrentSong] << endl;
                break;
            }

            case 10: {
                for (int i =0; i < realCoutSongs;++i) {
                    topSong[i]= Songs[i];
                    topGroups[i] = Groups[i];
                    popSongTop[i]=popSongs[i];
                }

                for (int i = 1;i< realCoutSongs;++i) {
                    const char*tempNamesSongs = topSong[i];
                    const char* tempNamesGroups = topGroups[i];int tempPopSongs = popSongTop[i];

                    int j = i - 1;
                    while (j > -1 && popSongTop[j] < tempPopSongs) {
                        topSong[j + 1] = topSong[j];
                        topGroups[j + 1] = topGroups[j];
                        popSongTop[j + 1] = popSongTop[j];
                        --j;
                    }

                    topSong[j + 1] =tempNamesSongs;
                    topGroups[j + 1] = tempNamesGroups;
                    popSongTop[j + 1] = tempPopSongs;
                }

                cout << "Chart: " << endl;

                for(int i=0;i <realCoutSongs;++i){
                    cout << (i + 1) << ") " << topGroups[i] << " - "<< topSong[i] << endl;
                }

                break;
            }

            case 11: {const char* currentSongName = Songs[numCurrentSong];
                const char* currentBandName = Groups[numCurrentSong];
                int currentSongPopularity = popSongs[numCurrentSong];

                for (int i = 1; i < realCoutSongs; ++i) { const char*tempNamesSongs = Songs[i];
                    const char* tempNamesGroups = Groups[i];
                    int tempPopSongs = popSongs[i];

                    int j = i - 1;
                    while (j > -1 && popSongs[j] < tempPopSongs) {
                      Songs[j + 1] = Songs[j];
                      Groups[j + 1] = Groups[j];
                      popSongs[j + 1] = popSongs[j];
                      --j;
                    }


                    Songs[j + 1] = tempNamesSongs;
                    Groups[j + 1] = tempNamesGroups;
                    popSongs[j + 1] = tempPopSongs;
                }

                cout << "New playlist order " << endl;

                for (int i = 0; i < realCoutSongs; ++i) {
                    cout << Groups[i] << " - " << Songs[i] << endl;
                }

                for (int i = 0; i < realCoutSongs; ++i)
                {
                    if (strcmp(currentBandName, Groups[i]) == 0
                        && strcmp(currentSongName, Songs[i]) == 0) {
                        numCurrentSong = i;
                        break; }
                }

                cout << "Now playing: " << Groups[numCurrentSong] << " - " << Songs[numCurrentSong] << endl;

                cout << "Song, you are listening on " << numCurrentSong + 1 << " position of chart" << endl;
                break;
            }


            case 12: {
                for (int i = 0; i < realCoutSongs; ++i)
                {
                    topSong[i] = Songs[i];
                        topGroups[i] = Groups[i];
                    popSongTop[i] = popSongs[i]; }

                for (int i = 1; i < realCoutSongs; ++i) { const char* temp1 = topSong[i]; const char* temp2 = topGroups[i];
                    int temp3 = popSongTop[i];

                    int j = i - 1;
                    while (j > -1 && popSongTop[j] < temp3)
                    {
                        topSong[j + 1] = topSong[j];
                        topGroups[j + 1] = topGroups[j];
                        popSongTop[j + 1] = popSongTop[j];



                        --j;
                    }

                    topSong[j + 1] = temp1;
                        topGroups[j + 1] = temp2;
                    popSongTop[j + 1] = temp3;
                }

                    cout << "Most popular band is: " << topGroups[0] << endl;
                break;
            }

            case 13: {
                workDuration = false;
                break;
            }

            default:
                cout << "Unknown command." << endl;
        }
    }

    cout << "Goodbye!" << endl;

}