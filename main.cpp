#include <iostream>
#include <string>


int main () {
    const int COUNT_SONGS = 20;

    const char* Songs[COUNT_SONGS];
    const char* Groups[COUNT_SONGS];
    int popularity_Songs[COUNT_SONGS];


    const char* pesny_VTope[COUNT_SONGS];
    const char* gruppy_v_tope[COUNT_SONGS];
    int popularnost_pesen_v_tope[COUNT_SONGS];

    int real_cout_Songs = 0;
    int nomerTeckusheyPensy = 0;

    Songs[0] = "Should I Stay or Should I Go";
    Groups[0] = "The Clash";
    popularity_Songs[0] = 0;

    Songs[1] = "Baby don't lie to me";
    Groups[1] = "The Fratellis";
    popularity_Songs[1] = 0;

    Songs[2] = "Ole Black 'n' Blue Eyes";
    Groups[2] = "The Fratellis";
    popularity_Songs[2] = 0;

    Songs[3] = "Like A Champion";
    Groups[3] = "The Baseballs";
    popularity_Songs[3] = 0;

    Songs[4] = "Jackie and Wilson";
    Groups[4] = "Hoizer";
    popularity_Songs[4] = 0;

    Songs[5] = "Mountains";
    Groups[5] = "Message To Bears";
    popularity_Songs[5] = 0;

    Songs[6] = "When It's Cold I'd Like to Die";
    Groups[6] = "Moby";
    popularity_Songs[6] = 0;

    Songs[7] = "Damn Your Eyes";
    Groups[7] = "Alex Clare";
    popularity_Songs[7] = 0;

    Songs[8] = "Heroes";
    Groups[8] = "David Bowie";
    popularity_Songs[8] = 0;

    Songs[9] = "No Diggity";
    Groups[9] = "Chet Faker";
    popularity_Songs[9] = 0;

    Songs[10] = "Inhaler";
    Groups[10] = "Foals";
    popularity_Songs[10] = 0;

    Songs[11] = "London Thunder";
    Groups[11] = "Foals";
    popularity_Songs[11] = 0;

    Songs[12] = "Spanish Sahara";
    Groups[12] = "Foals";
    popularity_Songs[12] = 0;

    Songs[13] = "Asleep";
    Groups[13] = "The Smiths";
    popularity_Songs[13] = 0;

    real_cout_Songs = 14;

    bool prodolgitRabotu = true;

    while (prodolgitRabotu) { int vybor = -1;

        std::cout << std::endl << "Now playing: " <<
                  Groups[nomerTeckusheyPensy] << " - " << Songs[nomerTeckusheyPensy] << std::endl;

        if (nomerTeckusheyPensy > 0) {std::cout << "Previous song: " <<
                        Groups[nomerTeckusheyPensy - 1] << " - " << Songs[nomerTeckusheyPensy - 1] << std::endl;
        }

        if (nomerTeckusheyPensy <real_cout_Songs - 1) {
            std::cout << "Next song: " <<
                          Groups[nomerTeckusheyPensy + 1] << " - " << Songs[nomerTeckusheyPensy + 1] << std::endl;
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

        std::cin >> vybor;

        std::cin.ignore();

        switch (vybor) {
            case 1: {
                if (nomerTeckusheyPensy != real_cout_Songs - 1) {
                    ++nomerTeckusheyPensy;
                    ++popularity_Songs[nomerTeckusheyPensy]; }
                break;
            }

            case 2: {
                if (nomerTeckusheyPensy > 0)
                {
                    --nomerTeckusheyPensy;
                    ++popularity_Songs[nomerTeckusheyPensy];
                }
                break;
            }

            case 3: {
                const char* TMP = Songs[nomerTeckusheyPensy];
                const char* TMP2 = Groups[nomerTeckusheyPensy];
                int tekushayPopularnost = popularity_Songs[nomerTeckusheyPensy];


                for (int i = 1; i < real_cout_Songs; ++i)
                {
                    const char* tmp =Songs[i];
                    const char* temp= Groups[i];
                    int variable = popularity_Songs[i];

                    int j = i-1;
                    while (j> -1 && std::strcmp(temp, Groups[j]) != 0) {
                        Songs[j + 1] = Songs[j];
                        Groups[j +1] = Groups[j];
                        popularity_Songs[j+1] = popularity_Songs[j];
                        --j;
                    }

                    Songs[j+1] = tmp;
                    Groups[j+1] = temp;
                    popularity_Songs[j + 1] = variable;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < real_cout_Songs; ++i) {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                }

                for (int i = 0; i < real_cout_Songs; ++i) {
                    if (std::strcmp(TMP2, Groups[i]) == 0
                        && std::strcmp(TMP, Songs[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }
                }

                std::cout << "Current song position: " << nomerTeckusheyPensy + 1 << std::endl;

                std::cout << "Now playing: " <<
                          Groups[nomerTeckusheyPensy] << " - " << Songs[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              Groups[nomerTeckusheyPensy - 1] << " - " << Songs[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy < real_cout_Songs - 1) {
                    std::cout << "Next song: " <<
                              Groups[nomerTeckusheyPensy + 1] << " - " << Songs[nomerTeckusheyPensy + 1] << std::endl;
                }
                break;
            }

            case 4: {
                const char* nazvanieTekusheyPesny = Songs[nomerTeckusheyPensy];
                const char* nazvanieTekusheyGruppy = Groups[nomerTeckusheyPensy];
                int popularnost_tekushey_Gruppy = popularity_Songs[nomerTeckusheyPensy];

                for (int i = 1; i<real_cout_Songs; ++i) {
                    const char* vremenoeNazvanyePesny = Songs[i];
                    const char* vremenoeNazvanyeGruppy = Groups[i];
                    int popularnostVremennoyPesny = popularity_Songs[i];

                    int j = i-1;
                    while (j >-1 && std::strcmp(vremenoeNazvanyePesny,Songs[j])!=0){
                        Songs[j + 1] = Songs[j];
                        Groups[j + 1] = Groups[j];
                        popularity_Songs[j + 1] = popularity_Songs[j];
                        --j;}


                    Songs[j + 1] = vremenoeNazvanyePesny;
                    Groups[j + 1] = vremenoeNazvanyeGruppy;
                    popularity_Songs[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i<real_cout_Songs; ++i)
                {
                    std::cout << Groups[i] <<" - " << Songs[i] << std::endl;
                }

                for (int i = 0; i < real_cout_Songs; ++i){
                    if (std::strcmp(nazvanieTekusheyGruppy, Groups[i]) == 0
                        && std::strcmp(nazvanieTekusheyPesny, Songs[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }}

                std::cout<<"Current song position: "<<nomerTeckusheyPensy<< std::endl;

                std::cout<<"Now playing: " <<
                          Groups[nomerTeckusheyPensy]<<" - "<< Songs[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              Groups[nomerTeckusheyPensy - 1] << " - " << Songs[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy < real_cout_Songs - 1) {
                    std::cout << "Next song: " <<
                              Groups[nomerTeckusheyPensy + 1] << " - " << Songs[nomerTeckusheyPensy + 1] << std::endl;
                }
                break;
            }

            case 5: {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool nashel=false;
                for (int i=0; i<real_cout_Songs; ++i) {
                    if (std::strcmp(str.c_str(), Groups[i]) == 0) {
                        std::cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << std::endl;
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
                for (int i = 0; i < real_cout_Songs; ++i) {
                    if (std::strcmp(str2.c_str(), Songs[i]) == 0) {
                        std::cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << std::endl;
                        nashel = true;
                    }
                }

                if (nashel)
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

                int songNomer;

                std::cin >> songNomer;

                std::cin.ignore();

                --songNomer;

                if (songNomer > -1 && songNomer<real_cout_Songs) {
                    nomerTeckusheyPensy = songNomer;
                    ++popularity_Songs[nomerTeckusheyPensy];
                }

                std::cout << "Now playing: " <<
                          Groups[nomerTeckusheyPensy] << " - " << Songs[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              Groups[nomerTeckusheyPensy - 1] << " - " << Songs[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy<real_cout_Songs-1) {
                    std::cout << "Next song: " <<
                              Groups[nomerTeckusheyPensy + 1]<< " - "<< Songs[nomerTeckusheyPensy + 1] << std::endl;
                }

                break;
            }

            case 9: {
                std::cout<< "Now playing: "<<
                          Groups[nomerTeckusheyPensy] <<" - " <<Songs[nomerTeckusheyPensy] << std::endl;
                break;
            }

            case 10: {
                for (int i =0; i < real_cout_Songs;++i) {
                    pesny_VTope[i]= Songs[i];
                    gruppy_v_tope[i] =Groups[i];
                    popularnost_pesen_v_tope[i]=popularity_Songs[i];
                }

                for (int i = 1;i< real_cout_Songs;++i) {
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

                for(int i=0;i <real_cout_Songs;++i){
                    std::cout<< (i + 1) << ") "<< gruppy_v_tope[i]<< " - "<< pesny_VTope[i] << std::endl;
                }

                break;
            }

            case 11: {const char* currentSongName = Songs[nomerTeckusheyPensy];
                const char* currentBandName = Groups[nomerTeckusheyPensy];
                int currentSongPopularity = popularity_Songs[nomerTeckusheyPensy];

                for (int i = 1; i < real_cout_Songs; ++i) { const char* vremenoeNazvanyePesny = Songs[i];
                    const char* vremenoeNazvanyeGruppy = Groups[i];
                    int popularnostVremennoyPesny = popularity_Songs[i];

                    int j = i - 1;
                    while (j > -1 && popularity_Songs[j] < popularnostVremennoyPesny) {
                      Songs[j + 1] = Songs[j];
                      Groups[j + 1] = Groups[j];
                      popularity_Songs[j + 1] = popularity_Songs[j];
                      --j;
                    }


                    Songs[j + 1] = vremenoeNazvanyePesny;
                    Groups[j + 1] = vremenoeNazvanyeGruppy;
                    popularity_Songs[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < real_cout_Songs; ++i) {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                }

                for (int i = 0; i < real_cout_Songs; ++i)
                {
                    if (std::strcmp(currentBandName, Groups[i]) == 0
                        && std::strcmp(currentSongName, Songs[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break; }
                }

                std::cout << "Now playing: " << Groups[nomerTeckusheyPensy] << " - " << Songs[nomerTeckusheyPensy] << std::endl;

                std::cout << "Song, you are listening on " << nomerTeckusheyPensy + 1 << " position of chart" << std::endl;
                break;
            }


            case 12: {
                for (int i = 0; i < real_cout_Songs; ++i)
                {
                    pesny_VTope[i] = Songs[i];
                        gruppy_v_tope[i] = Groups[i];
                    popularnost_pesen_v_tope[i] = popularity_Songs[i]; }

                for (int i = 1; i < real_cout_Songs; ++i) { const char* temp1 = pesny_VTope[i]; const char* temp2 = gruppy_v_tope[i];
                    int temp3 = popularnost_pesen_v_tope[i];

                    int j = i - 1;
                    while (j > -1 && popularnost_pesen_v_tope[j] < temp3)
                    {
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