#include <iostream>
#include <string>


int main () {
    const int TOTAL_NUMBER_OF_SONGS = 20; // количество песен всего

    const char* array_of_songs[TOTAL_NUMBER_OF_SONGS]; //массив песен
    const char* array_group[TOTAL_NUMBER_OF_SONGS];
    int popularnost_pesen[TOTAL_NUMBER_OF_SONGS];


    const char* pesny_VTope[TOTAL_NUMBER_OF_SONGS];
    const char* gruppy_v_tope[TOTAL_NUMBER_OF_SONGS];
    int popularnost_pesen_v_tope[TOTAL_NUMBER_OF_SONGS];

    int realnoe_kolichestvo_pesen = 0;
    int nomerTeckusheyPensy = 0;

    array_of_songs[0] = "Should I Stay or Should I Go";
    array_group[0] = "The Clash";
    popularnost_pesen[0] = 0;

    array_of_songs[1] = "Baby don't lie to me";
    array_group[1] = "The Fratellis";
    popularnost_pesen[1] = 0;

    array_of_songs[2] = "Ole Black 'n' Blue Eyes";
    array_group[2] = "The Fratellis";
    popularnost_pesen[2] = 0;

    array_of_songs[3] = "Like A Champion";
    array_group[3] = "The Baseballs";
    popularnost_pesen[3] = 0;

    array_of_songs[4] = "Jackie and Wilson";
    array_group[4] = "Hoizer";
    popularnost_pesen[4] = 0;

    array_of_songs[5] = "Mountains";
    array_group[5] = "Message To Bears";
    popularnost_pesen[5] = 0;

    array_of_songs[6] = "When It's Cold I'd Like to Die";
    array_group[6] = "Moby";
    popularnost_pesen[6] = 0;

    array_of_songs[7] = "Damn Your Eyes";
    array_group[7] = "Alex Clare";
    popularnost_pesen[7] = 0;

    array_of_songs[8] = "Heroes";
    array_group[8] = "David Bowie";
    popularnost_pesen[8] = 0;

    array_of_songs[9] = "No Diggity";
    array_group[9] = "Chet Faker";
    popularnost_pesen[9] = 0;

    array_of_songs[10] = "Inhaler";
    array_group[10] = "Foals";
    popularnost_pesen[10] = 0;

    array_of_songs[11] = "London Thunder";
    array_group[11] = "Foals";
    popularnost_pesen[11] = 0;

    array_of_songs[12] = "Spanish Sahara";
    array_group[12] = "Foals";
    popularnost_pesen[12] = 0;

    array_of_songs[13] = "Asleep";
    array_group[13] = "The Smiths";
    popularnost_pesen[13] = 0;

    realnoe_kolichestvo_pesen = 14;

    bool prodolgitRabotu = true;

    while (prodolgitRabotu) { int choise = -1;

        std::cout << std::endl << "Now playing: " <<
                  array_group[nomerTeckusheyPensy] << " - " << array_of_songs[nomerTeckusheyPensy] << std::endl;

        if (nomerTeckusheyPensy > 0) {std::cout << "Previous song: " <<
                        array_group[nomerTeckusheyPensy - 1] << " - " << array_of_songs[nomerTeckusheyPensy - 1] << std::endl;
        }

        if (nomerTeckusheyPensy <realnoe_kolichestvo_pesen - 1) {
            std::cout << "Next song: " <<
                          array_group[nomerTeckusheyPensy + 1] << " - " << array_of_songs[nomerTeckusheyPensy + 1] << std::endl;
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
                if (nomerTeckusheyPensy != realnoe_kolichestvo_pesen - 1) {
                    ++nomerTeckusheyPensy;
                    ++popularnost_pesen[nomerTeckusheyPensy]; }
                break;
            }

            case 2: {
                if (nomerTeckusheyPensy > 0)
                {
                    --nomerTeckusheyPensy;
                    ++popularnost_pesen[nomerTeckusheyPensy];
                }
                break;
            }

            case 3: {
                const char* TMP = array_of_songs[nomerTeckusheyPensy];
                const char* TMP2 = array_group[nomerTeckusheyPensy];
                int tekushayPopularnost = popularnost_pesen[nomerTeckusheyPensy];


                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i)
                {
                    const char* tmp =array_of_songs[i];
                    const char* temp= array_group[i];
                    int variable = popularnost_pesen[i];

                    int j = i-1;
                    while (j> -1 && std::strcmp(temp, array_group[j]) != 0) {
                        array_of_songs[j + 1] = array_of_songs[j];
                        array_group[j +1] = array_group[j];
                        popularnost_pesen[j+1] = popularnost_pesen[j];
                        --j;
                    }

                   array_of_songs[j+1] = tmp;
                    array_group[j+1] = temp;
                    popularnost_pesen[j + 1] = variable;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    std::cout << array_group[i] << " - " << array_of_songs[i] << std::endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(TMP2, array_group[i]) == 0
                        && std::strcmp(TMP, array_of_songs[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }
                }

              std::cout << "Current song position: " << nomerTeckusheyPensy + 1 << std::endl;

               std::cout << "Now playing: " <<
                         array_group[nomerTeckusheyPensy] << " - " << array_of_songs[nomerTeckusheyPensy] << std::endl;

               if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              array_group[nomerTeckusheyPensy - 1] << " - " << array_of_songs[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1) {
                    std::cout << "Next song: " <<
                              array_group[nomerTeckusheyPensy + 1] << " - " << array_of_songs[nomerTeckusheyPensy + 1] << std::endl;
                }
                break;
            }

            case 4: {
                const char* nazvanieTekusheyPesny = array_of_songs[nomerTeckusheyPensy];
                const char* nazvanieTekusheyGruppy = array_group[nomerTeckusheyPensy];
                int popularnost_tekushey_Gruppy = popularnost_pesen[nomerTeckusheyPensy];

                for (int i = 1; i<realnoe_kolichestvo_pesen; ++i) {
                    const char* vremenoeNazvanyePesny = array_of_songs[i];
                    const char* vremenoeNazvanyeGruppy = array_group[i];
                    int popularnostVremennoyPesny = popularnost_pesen[i];

                    
					int j = i-1;
                    while (j >-1 && std::strcmp(vremenoeNazvanyePesny,array_of_songs[j])!=0) {
                        array_of_songs[j + 1] = array_of_songs[j];
                        array_group[j + 1] = array_group[j];
                        popularnost_pesen[j + 1] = popularnost_pesen[j];
                        --j;
					}

                    array_of_songs[j + 1] = vremenoeNazvanyePesny;
                    array_group[j + 1] = vremenoeNazvanyeGruppy;
                    popularnost_pesen[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i<realnoe_kolichestvo_pesen; ++i) {
                    std::cout << array_group[i] <<" - " << array_of_songs[i] << std::endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i){
                    if (std::strcmp(nazvanieTekusheyGruppy, array_group[i]) == 0
                        && std::strcmp(nazvanieTekusheyPesny, array_of_songs[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }}

                std::cout<<"Current song position: "<<nomerTeckusheyPensy<< std::endl;

                std::cout<<"Now playing: " <<
                          array_group[nomerTeckusheyPensy]<<" - "<< array_of_songs[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              array_group[nomerTeckusheyPensy - 1] << " - " << array_of_songs[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1) {
                    std::cout << "Next song: " <<
                              array_group[nomerTeckusheyPensy + 1] << " - " << array_of_songs[nomerTeckusheyPensy + 1] << std::endl;
                }
                break;
            }

            case 5: {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool nashel=false;
                for (int i=0; i<realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(str.c_str(), array_group[i]) == 0) {
                        std::cout << i + 1 << ") " << array_group[i] << " - " << array_of_songs[i] << std::endl;
                        nashel = true;
                    }
                }

                if(nashel){
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
                bool nashel = false;
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(str2.c_str(), array_of_songs[i]) == 0) {
                        std::cout << i + 1 << ") " << array_group[i] << " - " << array_of_songs[i] << std::endl;
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
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    std::cout << array_group[i] << " - " << array_of_songs[i] << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "Ok, here is the playlist: " << std::endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i){
                    std::cout << i + 1 << ") " << array_group[i] << " - " << array_of_songs[i] << std::endl;
                }

                std::cout <<"Enter song position, you want to play: " << std::endl;

                int songNomer;

                std::cin >> songNomer;

                std::cin.ignore();

                --songNomer;

                if (songNomer > -1 && songNomer<realnoe_kolichestvo_pesen) {
                    nomerTeckusheyPensy = songNomer;
                    ++popularnost_pesen[nomerTeckusheyPensy];
                }

                std::cout << "Now playing: " <<
                          array_group[nomerTeckusheyPensy] << " - " << array_of_songs[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              array_group[nomerTeckusheyPensy - 1] << " - " << array_of_songs[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy<realnoe_kolichestvo_pesen-1) {
                    std::cout << "Next song: " <<
                              array_group[nomerTeckusheyPensy + 1]<< " - "<< array_of_songs[nomerTeckusheyPensy + 1] << std::endl;
                }

                break;
            }

            case 9: {
                std::cout<< "Now playing: "<<
                          array_group[nomerTeckusheyPensy] <<" - " <<array_of_songs[nomerTeckusheyPensy] << std::endl;
                break;
            }

            case 10: {
                for (int i =0; i < realnoe_kolichestvo_pesen;++i) {
                    pesny_VTope[i] = array_of_songs[i];
                    gruppy_v_tope[i] = array_group[i];
                    popularnost_pesen_v_tope[i]=popularnost_pesen[i];
                }

                for (int i = 1;i< realnoe_kolichestvo_pesen;++i) {
					const char* vremenoeNazvanyePesny = pesny_VTope[i];
					const char* vremenoeNazvanyeGruppy = gruppy_v_tope[i];int popularnostVremennoyPesny = popularnost_pesen_v_tope[i];

                    int j = i - 1;
                    while (j > -1 && popularnost_pesen_v_tope[j] < popularnostVremennoyPesny) {
                        pesny_VTope[j + 1] = pesny_VTope[j];
						gruppy_v_tope[j + 1] = gruppy_v_tope[j];
                        popularnost_pesen_v_tope[j + 1] = popularnost_pesen_v_tope[j];
                        --j;
                    }

                    pesny_VTope[j + 1] = vremenoeNazvanyePesny;
                    gruppy_v_tope[j + 1] = vremenoeNazvanyeGruppy;
                    popularnost_pesen_v_tope[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "Chart: " << std::endl;

                for(int i=0; i <realnoe_kolichestvo_pesen; ++i) {
                    std::cout<< (i + 1) << ") "<< gruppy_v_tope[i]<< " - "<< pesny_VTope[i] << std::endl;
                }

                break;
            }

            case 11: {const char* currentSongName = array_of_songs[nomerTeckusheyPensy];
                const char* currentBandName = array_group[nomerTeckusheyPensy];
                int currentSongPopularity = popularnost_pesen[nomerTeckusheyPensy];

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i) { const char* vremenoeNazvanyePesny = array_of_songs[i];
                    const char* vremenoeNazvanyeGruppy = array_group[i];
                    int popularnostVremennoyPesny = popularnost_pesen[i];

                    int j = i - 1;
                    while (j > -1 && popularnost_pesen[j] < popularnostVremennoyPesny) {
                      array_of_songs[j + 1] = array_of_songs[j];
                      array_group[j + 1] = array_group[j];
                      popularnost_pesen[j + 1] = popularnost_pesen[j];
                      --j;
                    }


                    array_of_songs[j + 1] = vremenoeNazvanyePesny;
                    array_group[j + 1] = vremenoeNazvanyeGruppy;
                    popularnost_pesen[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    std::cout << array_group[i] << " - " << array_of_songs[i] << std::endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    if (std::strcmp(currentBandName, array_group[i]) == 0
                        && std::strcmp(currentSongName, array_of_songs[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break; }
                }

                std::cout << "Now playing: " << array_group[nomerTeckusheyPensy] << " - " << array_of_songs[nomerTeckusheyPensy] << std::endl;

                std::cout << "Song, you are listening on " << nomerTeckusheyPensy + 1 << " position of chart" << std::endl;
                break;
            }


            case 12: {
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    pesny_VTope[i] = array_of_songs[i];
                    gruppy_v_tope[i] = array_group[i];
                    popularnost_pesen_v_tope[i] = popularnost_pesen[i]; 
				}

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i) { const char* temp1 = pesny_VTope[i]; const char* temp2 = gruppy_v_tope[i];
                    int temp3 = popularnost_pesen_v_tope[i];

                    int j = i - 1;
                    while (j > -1 && popularnost_pesen_v_tope[j] < temp3) {
                        pesny_VTope[j + 1] = pesny_VTope[j];
                        gruppy_v_tope[j + 1] = gruppy_v_tope[j];
                        popularnost_pesen_v_tope[j + 1] = popularnost_pesen_v_tope[j];
                        --j;
                    }

                    pesny_VTope[j + 1] = temp1;
                    gruppy_v_tope[j + 1] = temp2;
                    popularnost_pesen_v_tope[j + 1] = temp3;
                }

				std::cout << "Most popular band is: " << gruppy_v_tope[0] << std::endl;
				break;
            }

            case 13: {
                prodolgitRabotu = false;
                break;
            }

            default:
			std::cout << "Unknown command." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
}