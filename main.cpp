#include <iostream>
#include <string>


int main () {
    const int COUNT_SONGS = 20;

    const char* Songs[COUNT_SONGS];
    const char* Groups[COUNT_SONGS];
    int pop_Songs[COUNT_SONGS];


    const char* Top_songs[COUNT_SONGS];
    const char* Top_groups[COUNT_SONGS];
    int pop_songs_in_Top[COUNT_SONGS];

    int real_cout_Songs = 0;
    int number_current_song = 0;

    Songs[0] = "Should I Stay or Should I Go";
    Groups[0] = "The Clash";
    pop_Songs[0] = 0;

    Songs[1] = "Baby don't lie to me";
    Groups[1] = "The Fratellis";
    pop_Songs[1] = 0;

    Songs[2] = "Ole Black 'n' Blue Eyes";
    Groups[2] = "The Fratellis";
    pop_Songs[2] = 0;

    Songs[3] = "Like A Champion";
    Groups[3] = "The Baseballs";
    pop_Songs[3] = 0;

    Songs[4] = "Jackie and Wilson";
    Groups[4] = "Hoizer";
    pop_Songs[4] = 0;

    Songs[5] = "Mountains";
    Groups[5] = "Message To Bears";
    pop_Songs[5] = 0;

    Songs[6] = "When It's Cold I'd Like to Die";
    Groups[6] = "Moby";
    pop_Songs[6] = 0;

    Songs[7] = "Damn Your Eyes";
    Groups[7] = "Alex Clare";
    pop_Songs[7] = 0;

    Songs[8] = "Heroes";
    Groups[8] = "David Bowie";
    pop_Songs[8] = 0;

    Songs[9] = "No Diggity";
    Groups[9] = "Chet Faker";
    pop_Songs[9] = 0;

    Songs[10] = "Inhaler";
    Groups[10] = "Foals";
    pop_Songs[10] = 0;

    Songs[11] = "London Thunder";
    Groups[11] = "Foals";
    pop_Songs[11] = 0;

    Songs[12] = "Spanish Sahara";
    Groups[12] = "Foals";
    pop_Songs[12] = 0;

    Songs[13] = "Asleep";
    Groups[13] = "The Smiths";
    pop_Songs[13] = 0;

    real_cout_Songs = 14;

    bool work_duration = true;

    while (work_duration) { int selection = -1;

        std::cout << std::endl << "Now playing: " <<
                  Groups[number_current_song] << " - " << Songs[number_current_song] << std::endl;

        if (number_current_song > 0) {std::cout << "Previous song: " <<
                        Groups[number_current_song - 1] << " - " << Songs[number_current_song - 1] << std::endl;
        }

        if (number_current_song <real_cout_Songs - 1) {
            std::cout << "Next song: " <<
                          Groups[number_current_song + 1] << " - " << Songs[number_current_song + 1] << std::endl;
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
                if (number_current_song != real_cout_Songs - 1) {
                    ++number_current_song;
                    ++pop_Songs[number_current_song]; }
                break;
            }

            case 2: {
                if (number_current_song > 0)
                {
                    --number_current_song;
                    ++pop_Songs[number_current_song];
                }
                break;
            }

            case 3: {
                const char* TMP = Songs[number_current_song];
                const char* TMP2 = Groups[number_current_song];
                int current_pop = pop_Songs[number_current_song];


                for (int i = 1; i < real_cout_Songs; ++i)
                {
                    const char* tmp =Songs[i];
                    const char* temp= Groups[i];
                    int variable = pop_Songs[i];

                    int j = i-1;
                    while (j> -1 && std::strcmp(temp, Groups[j]) != 0) {
                        Songs[j + 1] = Songs[j];
                        Groups[j +1] = Groups[j];
                        pop_Songs[j+1] = pop_Songs[j];
                        --j;
                    }

                    Songs[j+1] = tmp;
                    Groups[j+1] = temp;
                    pop_Songs[j + 1] = variable;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < real_cout_Songs; ++i) {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                }

                for (int i = 0; i < real_cout_Songs; ++i) {
                    if (std::strcmp(TMP2, Groups[i]) == 0
                        && std::strcmp(TMP, Songs[i]) == 0) {
                        number_current_song = i;
                        break;
                    }
                }

                std::cout << "Current song position: " << number_current_song + 1 << std::endl;

                std::cout << "Now playing: " <<
                          Groups[number_current_song] << " - " << Songs[number_current_song] << std::endl;

                if (number_current_song > 0) {
                    std::cout << "Previous song: " <<
                              Groups[number_current_song - 1] << " - " << Songs[number_current_song - 1] << std::endl;
                }

                if (number_current_song < real_cout_Songs - 1) {
                    std::cout << "Next song: " <<
                              Groups[number_current_song + 1] << " - " << Songs[number_current_song + 1] << std::endl;
                }
                break;
            }

            case 4: {
                const char* name_Current_Song = Songs[number_current_song];
                const char* name_Current_Group = Groups[number_current_song];
                int pop_current_Group = pop_Songs[number_current_song];

                for (int i = 1; i<real_cout_Songs; ++i) {
                    const char* temp_name_Song = Songs[i];
                    const char* temp_name_Group = Groups[i];
                    int pop_temp_Song = pop_Songs[i];

                    int j = i-1;
                    while (j >-1 && std::strcmp(temp_name_Song,Songs[j])!=0){
                        Songs[j + 1] = Songs[j];
                        Groups[j + 1] = Groups[j];
                        pop_Songs[j + 1] = pop_Songs[j];
                        --j;}


                    Songs[j + 1] = temp_name_Song;
                    Groups[j + 1] = temp_name_Group;
                    pop_Songs[j + 1] = pop_temp_Song;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i<real_cout_Songs; ++i)
                {
                    std::cout << Groups[i] <<" - " << Songs[i] << std::endl;
                }

                for (int i = 0; i < real_cout_Songs; ++i){
                    if (std::strcmp(name_Current_Group, Groups[i]) == 0
                        && std::strcmp(name_Current_Song, Songs[i]) == 0) {
                        number_current_song = i;
                        break;
                    }}

                std::cout<<"Current song position: "<<number_current_song<< std::endl;

                std::cout<<"Now playing: " <<
                          Groups[number_current_song]<<" - "<< Songs[number_current_song] << std::endl;

                if (number_current_song > 0) {
                    std::cout << "Previous song: " <<
                              Groups[number_current_song - 1] << " - " << Songs[number_current_song - 1] << std::endl;
                }

                if (number_current_song < real_cout_Songs - 1) {
                    std::cout << "Next song: " <<
                              Groups[number_current_song + 1] << " - " << Songs[number_current_song + 1] << std::endl;
                }
                break;
            }

            case 5: {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool found=false;
                for (int i=0; i<real_cout_Songs; ++i) {
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
                for (int i = 0; i < real_cout_Songs; ++i) {
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
                for (int i = 0; i < real_cout_Songs; ++i) {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "Ok, here is the playlist: " << std::endl;

                for (int i = 0; i < real_cout_Songs; ++i){
                    std::cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << std::endl;
                }

                std::cout <<"Enter song position, you want to play: " << std::endl;

                int song_number;

                std::cin >> song_number;

                std::cin.ignore();

                --song_number;

                if (song_number > -1 && song_number<real_cout_Songs) {
                    number_current_song = song_number;
                    ++pop_Songs[number_current_song];
                }

                std::cout << "Now playing: " <<
                          Groups[number_current_song] << " - " << Songs[number_current_song] << std::endl;

                if (number_current_song > 0) {
                    std::cout << "Previous song: " <<
                              Groups[number_current_song - 1] << " - " << Songs[number_current_song - 1] << std::endl;
                }

                if (number_current_song<real_cout_Songs-1) {
                    std::cout << "Next song: " <<
                              Groups[number_current_song + 1]<< " - "<< Songs[number_current_song + 1] << std::endl;
                }

                break;
            }

            case 9: {
                std::cout<< "Now playing: "<<
                          Groups[number_current_song] <<" - " <<Songs[number_current_song] << std::endl;
                break;
            }

            case 10: {
                for (int i =0; i < real_cout_Songs;++i) {
                    Top_songs[i]= Songs[i];
                    Top_groups[i] =Groups[i];
                    pop_songs_in_Top[i]=pop_Songs[i];
                }

                for (int i = 1;i< real_cout_Songs;++i) {
                    const char* temp_name_Song = Top_songs[i];
                    const char* temp_name_Group = Top_groups[i];int pop_temp_Song = pop_songs_in_Top[i];

                    int j = i - 1;
                    while (j > -1 && pop_songs_in_Top[j] < pop_temp_Song) {
                        Top_songs[j + 1] = Top_songs[j];
                        Top_groups[j + 1] = Top_groups[j];
                        pop_songs_in_Top[j + 1] = pop_songs_in_Top[j];
                        --j;
                    }

                    Top_songs[j + 1] = temp_name_Song;
                    Top_groups[j + 1] = temp_name_Group;
                    pop_songs_in_Top[j + 1] = pop_temp_Song;
                }

                std::cout << "Chart: " << std::endl;

                for(int i=0;i <real_cout_Songs;++i){
                    std::cout<< (i + 1) << ") "<< Top_groups[i]<< " - "<< Top_songs[i] << std::endl;
                }

                break;
            }

            case 11: {const char* currentSongName = Songs[number_current_song];
                const char* currentBandName = Groups[number_current_song];
                int currentSongPopularity = pop_Songs[number_current_song];

                for (int i = 1; i < real_cout_Songs; ++i) { const char* temp_name_Song = Songs[i];
                    const char* temp_name_Group = Groups[i];
                    int pop_temp_Song = pop_Songs[i];

                    int j = i - 1;
                    while (j > -1 && pop_Songs[j] < pop_temp_Song) {
                      Songs[j + 1] = Songs[j];
                      Groups[j + 1] = Groups[j];
                      pop_Songs[j + 1] = pop_Songs[j];
                      --j;
                    }


                    Songs[j + 1] = temp_name_Song;
                    Groups[j + 1] = temp_name_Group;
                    pop_Songs[j + 1] = pop_temp_Song;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < real_cout_Songs; ++i) {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                }

                for (int i = 0; i < real_cout_Songs; ++i)
                {
                    if (std::strcmp(currentBandName, Groups[i]) == 0
                        && std::strcmp(currentSongName, Songs[i]) == 0) {
                        number_current_song = i;
                        break; }
                }

                std::cout << "Now playing: " << Groups[number_current_song] << " - " << Songs[number_current_song] << std::endl;

                std::cout << "Song, you are listening on " << number_current_song + 1 << " position of chart" << std::endl;
                break;
            }


            case 12: {
                for (int i = 0; i < real_cout_Songs; ++i)
                {
                    Top_songs[i] = Songs[i];
                        Top_groups[i] = Groups[i];
                    pop_songs_in_Top[i] = pop_Songs[i]; }

                for (int i = 1; i < real_cout_Songs; ++i) { const char* temp1 = Top_songs[i]; const char* temp2 = Top_groups[i];
                    int temp3 = pop_songs_in_Top[i];

                    int j = i - 1;
                    while (j > -1 && pop_songs_in_Top[j] < temp3)
                    {
                        Top_songs[j + 1] = Top_songs[j];
                        Top_groups[j + 1] = Top_groups[j];
                        pop_songs_in_Top[j + 1] = pop_songs_in_Top[j];



                        --j;
                    }

                    Top_songs[j + 1] = temp1;
                        Top_groups[j + 1] = temp2;
                    pop_songs_in_Top[j + 1] = temp3;
                }

                    std::cout << "Most popular band is: " << Top_groups[0] << std::endl;
                break;
            }

            case 13: {
                work_duration = false;
                break;
            }

            default:
                std::cout << "Unknown command." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;

}