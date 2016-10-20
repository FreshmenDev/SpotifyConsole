#include <iostream>
#include <string>


int main () {
    const int TOTAL_NUMBER_OF_SONGS = 20; // количество песен всего

    const char* array_songs[TOTAL_NUMBER_OF_SONGS]; // массив песен
    const char* array_group[TOTAL_NUMBER_OF_SONGS]; // массив групп
    int popular_songs[TOTAL_NUMBER_OF_SONGS]; // попул€рность песен


    const char* top_songs[TOTAL_NUMBER_OF_SONGS]; // песни в топе
    const char* top_group[TOTAL_NUMBER_OF_SONGS]; // группы в топе
    int top_popular_songs[TOTAL_NUMBER_OF_SONGS]; // попул€рность песен в топе

    int real = 0; // реальное кол-во песен
    int number_current_song = 0; // номер текущей песни

    array_songs[0] = "Should I Stay or Should I Go";
    array_group[0] = "The Clash";
    popular_songs[0] = 0;

    array_songs[1] = "Baby don't lie to me";
    array_group[1] = "The Fratellis";
    popular_songs[1] = 0;

    array_songs[2] = "Ole Black 'n' Blue Eyes";
    array_group[2] = "The Fratellis";
    popular_songs[2] = 0;

    array_songs[3] = "Like A Champion";
    array_group[3] = "The Baseballs";
    popular_songs[3] = 0;

    array_songs[4] = "Jackie and Wilson";
    array_group[4] = "Hoizer";
    popular_songs[4] = 0;

    array_songs[5] = "Mountains";
    array_group[5] = "Message To Bears";
    popular_songs[5] = 0;

    array_songs[6] = "When It's Cold I'd Like to Die";
    array_group[6] = "Moby";
    popular_songs[6] = 0;

    array_songs[7] = "Damn Your Eyes";
    array_group[7] = "Alex Clare";
    popular_songs[7] = 0;

    array_songs[8] = "Heroes";
    array_group[8] = "David Bowie";
    popular_songs[8] = 0;

    array_songs[9] = "No Diggity";
    array_group[9] = "Chet Faker";
    popular_songs[9] = 0;

    array_songs[10] = "Inhaler";
    array_group[10] = "Foals";
    popular_songs[10] = 0;

    array_songs[11] = "London Thunder";
    array_group[11] = "Foals";
    popular_songs[11] = 0;

    array_songs[12] = "Spanish Sahara";
    array_group[12] = "Foals";
    popular_songs[12] = 0;

    array_songs[13] = "Asleep";
    array_group[13] = "The Smiths";
    popular_songs[13] = 0;

    real = 14;

    bool continue_work = true;

    while (continue_work) { int choise = -1;

        std::cout << std::endl << "Now playing: " <<
        array_group[number_current_song] << " - " << array_songs[number_current_song] << std::endl;

        if (number_current_song > 0) {std::cout << "Previous song: " << array_group[number_current_song - 1] << " - " << array_songs[number_current_song - 1] << std::endl;
        }

        if (number_current_song < real - 1) {
        std::cout << "Next song: " << array_group[number_current_song + 1] << " - " << array_songs[number_current_song + 1] << std::endl;
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

        std::cin >> choise;

        std::cin.ignore();

        switch (choise) {
            case 1: {
                if (number_current_song != real - 1) {
                    ++number_current_song;
                    ++popular_songs[number_current_song]; 
				}
                break;
            }

            case 2: {
                if (number_current_song > 0) {
                    --number_current_song;
                    ++popular_songs[number_current_song];
                }
                break;
            }

            case 3: {
                const char* TMP = array_songs[number_current_song];
                const char* TMP2 = array_group[number_current_song];
                int popular_now = popular_songs[number_current_song]; // текуща€ попул€рность
				
                for (int i = 1; i < real; ++i)
                {
                    const char* tmp =array_songs[i];
                    const char* temp= array_group[i];
                    int variable = popular_songs[i];

                    int j = i-1;
                    while (j> -1 && std::strcmp(temp, array_group[j]) != 0) {
                        array_songs[j + 1] = array_songs[j];
                        array_group[j +1] = array_group[j];
                        popular_songs[j+1] = popular_songs[j];
                        --j;
                    }

                   array_songs[j+1] = tmp;
                   array_group[j+1] = temp;
                   popular_songs[j + 1] = variable;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < real; ++i) {
                    std::cout << array_group[i] << " - " << array_songs[i] << std::endl;
                }

                for (int i = 0; i < real; ++i) {
                    if (std::strcmp(TMP2, array_group[i]) == 0
                        && std::strcmp(TMP, array_songs[i]) == 0) {
                        number_current_song = i;
                        break;
                    }
				}

				std::cout << "Current song position: " << number_current_song + 1 << std::endl;
				std::cout << "Now playing: " << array_group[number_current_song] << " - " << array_songs[number_current_song] << std::endl;

               if (number_current_song > 0) {
                    std::cout << "Previous song: " <<
                              array_group[number_current_song - 1] << " - " << array_songs[number_current_song - 1] << std::endl;
                }

                if (number_current_song < real - 1) {
                    std::cout << "Next song: " << array_group[number_current_song + 1] << " - " << array_songs[number_current_song + 1] << std::endl;
                }
                break;
            }

            case 4: {
                const char* song_now = array_songs[number_current_song]; // название текущей песни
                const char* group_now = array_group[number_current_song]; // название текущей группы
                int popular_group_now = popular_songs[number_current_song]; //попул€рность текущей группы

                for (int i = 1; i<real; ++i) {
                    const char* vremenoeNazvanyePesny = array_songs[i];
                    const char* vremenoeNazvanyeGruppy = array_group[i];
                    int popularnostVremennoyPesny = popular_songs[i];

                    
					int j = i-1;
                    while (j >-1 && std::strcmp(vremenoeNazvanyePesny,array_songs[j])!=0) {
                        array_songs[j + 1] = array_songs[j];
                        array_group[j + 1] = array_group[j];
                        popular_songs[j + 1] = popular_songs[j];
                        --j;
					}

                    array_songs[j + 1] = vremenoeNazvanyePesny;
                    array_group[j + 1] = vremenoeNazvanyeGruppy;
                    popular_songs[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i<real; ++i) {
                    std::cout << array_group[i] <<" - " << array_songs[i] << std::endl;
                }

                for (int i = 0; i < real; ++i){
                    if (std::strcmp(group_now, array_group[i]) == 0
                        && std::strcmp(song_now, array_songs[i]) == 0) {
                        number_current_song = i;
                        break;
                    }}

                std::cout<<"Current song position: "<<number_current_song<< std::endl;

                std::cout<<"Now playing: " <<
                          array_group[number_current_song]<<" - "<< array_songs[number_current_song] << std::endl;

                if (number_current_song > 0) {
                    std::cout << "Previous song: " <<
                              array_group[number_current_song - 1] << " - " << array_songs[number_current_song - 1] << std::endl;
                }

                if (number_current_song < real - 1) {
                    std::cout << "Next song: " <<
                              array_group[number_current_song + 1] << " - " << array_songs[number_current_song + 1] << std::endl;
                }
                break;
            }

            case 5: {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool nashel=false;
                for (int i=0; i<real; ++i) {
                    if (std::strcmp(str.c_str(), array_group[i]) == 0) {
                        std::cout << i + 1 << ") " << array_group[i] << " - " << array_songs[i] << std::endl;
                        nashel = true;
                    }
                }

                if(nashel) {
                    std::cout << "Now you can play any song by it position" << std::endl;
                } 
				else {
                    std::cout << "There are no pesny with band name like this " << str << std::endl;
                }

                break;
            }

            case 6: {
                std::string str2;
                std::cout << "Input song name you are looking for: " << std::endl;
                std::getline(std::cin, str2);
                bool nashel = false;
                for (int i = 0; i < real; ++i) {
                    if (std::strcmp(str2.c_str(), array_songs[i]) == 0) {
                        std::cout << i + 1 << ") " << array_group[i] << " - " << array_songs[i] << std::endl;
                        nashel = true;
                    }
                }

                if (nashel) {
                    std::cout << "Now you can play any song by it position" << std::endl;
                }

                else {
                    std::cout << "There are no pesny with name like this " << str2 << std::endl;
                }

                break;
            }

            case 7: {
                std::cout << "Playlist: " << std::endl;
                for (int i = 0; i < real; ++i) {
                    std::cout << array_group[i] << " - " << array_songs[i] << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "Ok, here is the playlist: " << std::endl;

                for (int i = 0; i < real; ++i){
                    std::cout << i + 1 << ") " << array_group[i] << " - " << array_songs[i] << std::endl;
                }

                std::cout <<"Enter song position, you want to play: " << std::endl;

                int songNomer;

                std::cin >> songNomer;

                std::cin.ignore();

                --songNomer;

                if (songNomer > -1 && songNomer<real) {
                    number_current_song = songNomer;
                    ++popular_songs[number_current_song];
                }

                std::cout << "Now playing: " <<
                          array_group[number_current_song] << " - " << array_songs[number_current_song] << std::endl;

                if (number_current_song > 0) {
                    std::cout << "Previous song: " <<
                              array_group[number_current_song - 1] << " - " << array_songs[number_current_song - 1] << std::endl;
                }

                if (number_current_song<real - 1) {
                    std::cout << "Next song: " <<
                              array_group[number_current_song + 1]<< " - "<< array_songs[number_current_song + 1] << std::endl;
                }

                break;
            }

            case 9: {
                std::cout<< "Now playing: "<<
                          array_group[number_current_song] <<" - " <<array_songs[number_current_song] << std::endl;
                break;
            }

            case 10: {
                for (int i =0; i < real;++i) {
                    top_songs[i] = array_songs[i];
                    top_group[i] = array_group[i];
                    top_popular_songs[i]=popular_songs[i];
                }

                for (int i = 1;i< real;++i) {
					const char* vremenoeNazvanyePesny = top_songs[i];
					const char* vremenoeNazvanyeGruppy = top_group[i];
					int popularnostVremennoyPesny = top_popular_songs[i];

                    int j = i - 1;
                    while (j > -1 && top_popular_songs[j] < popularnostVremennoyPesny) {
                        top_songs[j + 1] = top_songs[j];
						top_group[j + 1] = top_group[j];
                        top_popular_songs[j + 1] = top_popular_songs[j];
                        --j;
                    }

                    top_songs[j + 1] = vremenoeNazvanyePesny;
                    top_group[j + 1] = vremenoeNazvanyeGruppy;
                    top_popular_songs[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "Chart: " << std::endl;

                for(int i=0; i <real; ++i) {
                    std::cout<< (i + 1) << ") "<< top_group[i]<< " - "<< top_songs[i] << std::endl;
                }

                break;
            }

            case 11: {const char* currentSongName = array_songs[number_current_song];
                const char* currentBandName = array_group[number_current_song];
                int currentSongPopularity = popular_songs[number_current_song];

                for (int i = 1; i < real; ++i) { const char* vremenoeNazvanyePesny = array_songs[i];
                    const char* vremenoeNazvanyeGruppy = array_group[i];
                    int popularnostVremennoyPesny = popular_songs[i];

                    int j = i - 1;
                    while (j > -1 && popular_songs[j] < popularnostVremennoyPesny) {
                      array_songs[j + 1] = array_songs[j];
                      array_group[j + 1] = array_group[j];
                      popular_songs[j + 1] = popular_songs[j];
                      --j;
                    }

                    array_songs[j + 1] = vremenoeNazvanyePesny;
                    array_group[j + 1] = vremenoeNazvanyeGruppy;
                    popular_songs[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < real; ++i) {
                    std::cout << array_group[i] << " - " << array_songs[i] << std::endl;
                }

                for (int i = 0; i < real; ++i)
                {
                    if (std::strcmp(currentBandName, array_group[i]) == 0
                        && std::strcmp(currentSongName, array_songs[i]) == 0) {
                        number_current_song = i;
                        break; }
                }

                std::cout << "Now playing: " << array_group[number_current_song] << " - " << array_songs[number_current_song] << std::endl;

                std::cout << "Song, you are listening on " << number_current_song + 1 << " position of chart" << std::endl;
                break;
            }


            case 12: {
                for (int i = 0; i < real; ++i) {
                    top_songs[i] = array_songs[i];
                    top_group[i] = array_group[i];
                    top_popular_songs[i] = popular_songs[i]; 
				}

                for (int i = 1; i < real; ++i) { const char* temp1 = top_songs[i]; const char* temp2 = top_group[i];
                    int temp3 = top_popular_songs[i];

                    int j = i - 1;
                    while (j > -1 && top_popular_songs[j] < temp3) {
                        top_songs[j + 1] = top_songs[j];
                        top_group[j + 1] = top_group[j];
                        top_popular_songs[j + 1] = top_popular_songs[j];
                        --j;
                    }

                    top_songs[j + 1] = temp1;
                    top_group[j + 1] = temp2;
                    top_popular_songs[j + 1] = temp3;
                }

				std::cout << "Most popular band is: " << top_group[0] << std::endl;
				break;
            }

            case 13: {
                continue_work = false;
                break;
            }

            default:
			std::cout << "Unknown command." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
}