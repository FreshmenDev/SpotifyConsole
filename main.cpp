#include <iostream>
#include <string>


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

        std::cout << std::endl << "Now playing: " <<
                  Groups[numCurrentSong] << " - " << Songs[numCurrentSong] << std::endl;

        if (numCurrentSong > 0) {std::cout << "Previous song: " <<
                        Groups[numCurrentSong - 1] << " - " << Songs[numCurrentSong - 1] << std::endl;
        }

        if (numCurrentSong <realCoutSongs - 1) {
            std::cout << "Next song: " <<
                          Groups[numCurrentSong + 1] << " - " << Songs[numCurrentSong + 1] << std::endl;
        }


        std::cout << "Enter action you want to make: " << std::endl;

        std::cout << "1) Play next" << std::endl;

        std::cout << "2) Play prev" << std::endl;

        std::cout << "3) Group by band" << std::endl;

                            std::cout << "4) Group by song name" << std::endl;

           std::cout << "5) Search song by band " << std::endl;

                            std::cout << "6) Search song by name " << std::endl;
            std::cout << "7) Show playlist " << std::endl;

                            std::cout << "8) Play specific song (specified by position) " << std::endl;

        std::cout << "9) What is playing now? " << std::endl;

        std::cout << "10) Show my chart " << std::endl;

        std::cout << "11) Sort by popularity " << std::endl;

                std::cout << "12) Show the most popular band " << std::endl;

        std::cout << "13) Exit " << std::endl;

        std::cin >> selection;

        std::cin.ignore();

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
                    while (j> -1 && std::strcmp(temp, Groups[j]) != 0) {
                        Songs[j + 1] = Songs[j];
                        Groups[j +1] = Groups[j];
                        popSongs[j+1] = popSongs[j];
                        --j;
                    }

                    Songs[j+1] = tmp;
                    Groups[j+1] = temp;
                    popSongs[j + 1] = variable;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < realCoutSongs; ++i) {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                }

                for (int i = 0; i < realCoutSongs; ++i) {
                    if (std::strcmp(TMP2, Groups[i]) == 0
                        && std::strcmp(TMP, Songs[i]) == 0) {
                        numCurrentSong = i;
                        break;
                    }
                }

                std::cout << "Current song position: " << numCurrentSong + 1 << std::endl;

                std::cout << "Now playing: " <<
                          Groups[numCurrentSong] << " - " << Songs[numCurrentSong] << std::endl;

                if (numCurrentSong > 0) {
                    std::cout << "Previous song: " <<
                              Groups[numCurrentSong - 1] << " - " << Songs[numCurrentSong - 1] << std::endl;
                }

                if (numCurrentSong < realCoutSongs - 1) {
                    std::cout << "Next song: " <<
                              Groups[numCurrentSong + 1] << " - " << Songs[numCurrentSong + 1] << std::endl;
                }
                break;
            }

            case 4: {
                const char* name_Current_Song = Songs[numCurrentSong];
                const char* name_Current_Group = Groups[numCurrentSong];
                int pop_current_Group = popSongs[numCurrentSong];

                for (int i = 1; i<realCoutSongs; ++i) {
                    const char* tempNamesSongs = Songs[i];
                    const char* tempNamesGroups = Groups[i];
                    int tempPopSongs = popSongs[i];

                    int j = i-1;
                    while (j >-1 && std::strcmp(tempNamesSongs,Songs[j])!=0){
                        Songs[j + 1] = Songs[j];
                        Groups[j + 1] = Groups[j];
                        popSongs[j + 1] = popSongs[j];
                        --j;}


                    Songs[j + 1] = tempNamesSongs;
                    Groups[j + 1] = tempNamesGroups;
                    popSongs[j + 1] = tempPopSongs;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i<realCoutSongs; ++i)
                {
                    std::cout << Groups[i] <<" - " << Songs[i] << std::endl;
                }

                for (int i = 0; i < realCoutSongs; ++i){
                    if (std::strcmp(name_Current_Group, Groups[i]) == 0
                        && std::strcmp(name_Current_Song, Songs[i]) == 0) {
                        numCurrentSong = i;
                        break;
                    }}

                std::cout<<"Current song position: "<<numCurrentSong<< std::endl;

                std::cout<<"Now playing: " <<
                          Groups[numCurrentSong]<<" - "<< Songs[numCurrentSong] << std::endl;

                if (numCurrentSong > 0) {
                    std::cout << "Previous song: " <<
                              Groups[numCurrentSong - 1] << " - " << Songs[numCurrentSong - 1] << std::endl;
                }

                if (numCurrentSong < realCoutSongs - 1) {
                    std::cout << "Next song: " <<
                              Groups[numCurrentSong + 1] << " - " << Songs[numCurrentSong + 1] << std::endl;
                }
                break;
            }

            case 5: {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool found=false;
                for (int i=0; i<realCoutSongs; ++i) {
                    if (std::strcmp(str.c_str(), Groups[i]) == 0) {
                        std::cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << std::endl;
                        found = true;
                    }
                }

                if(found){
                    std::cout << "Now you can play any song by it position" << std::endl;
                } else
                {
                    std::cout << "There are no pesny with band name like this " << str << std::endl;
                }

                break;
            }

            case 6: {
                std::string str2;
                std::cout << "Input song name you are looking for: " << std::endl;
                std::getline(std::cin, str2);
                bool found = false;
                for (int i = 0; i < realCoutSongs; ++i) {
                    if (std::strcmp(str2.c_str(), Songs[i]) == 0) {
                        std::cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << std::endl;
                        found = true;
                    }
                }

                if (found)
                {
                    std::cout << "Now you can play any song by it position" << std::endl;
                }

                else {
                    std::cout << "There are no pesny with name like this " << str2 << std::endl;
                }

                break;
            }

            case 7: {
                std::cout << "Playlist: " << std::endl;
                for (int i = 0; i < realCoutSongs; ++i) {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "Ok, here is the playlist: " << std::endl;

                for (int i = 0; i < realCoutSongs; ++i){
                    std::cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << std::endl;
                }

                std::cout <<"Enter song position, you want to play: " << std::endl;

                int numSongs;

                std::cin >> numSongs;

                std::cin.ignore();

                --numSongs;

                if (numSongs > -1 && numSongs<realCoutSongs) {
                    numCurrentSong = numSongs;
                    ++popSongs[numCurrentSong];
                }

                std::cout << "Now playing: " <<
                          Groups[numCurrentSong] << " - " << Songs[numCurrentSong] << std::endl;

                if (numCurrentSong > 0) {
                    std::cout << "Previous song: " <<
                              Groups[numCurrentSong - 1] << " - " << Songs[numCurrentSong - 1] << std::endl;
                }

                if (numCurrentSong<realCoutSongs-1) {
                    std::cout << "Next song: " <<
                              Groups[numCurrentSong + 1] << " - " << Songs[numCurrentSong + 1] << std::endl;
                }

                break;
            }

            case 9: {
                std::cout<< "Now playing: "<<
                          Groups[numCurrentSong] <<" - " << Songs[numCurrentSong] << std::endl;
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

                std::cout << "Chart: " << std::endl;

                for(int i=0;i <realCoutSongs;++i){
                    std::cout<< (i + 1) << ") "<< topGroups[i]<< " - "<< topSong[i] << std::endl;
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


                    Songs[j + 1] =tempNamesSongs;
                    Groups[j + 1] = tempNamesGroups;
                    popSongs[j + 1] = tempPopSongs;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < realCoutSongs; ++i) {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                }

                for (int i = 0; i < realCoutSongs; ++i)
                {
                    if (std::strcmp(currentBandName, Groups[i]) == 0
                        && std::strcmp(currentSongName, Songs[i]) == 0) {
                        numCurrentSong = i;
                        break; }
                }

                std::cout << "Now playing: " << Groups[numCurrentSong] << " - " << Songs[numCurrentSong] << std::endl;

                std::cout << "Song, you are listening on " << numCurrentSong + 1 << " position of chart" << std::endl;
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

                    std::cout << "Most popular band is: " << topGroups[0] << std::endl;
                break;
            }

            case 13: {
                workDuration = false;
                break;
            }

            default:
                std::cout << "Unknown command." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
}