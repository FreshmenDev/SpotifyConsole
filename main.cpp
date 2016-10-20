#include <iostream>
#include <string>


int main () {
    const int KOLICHESTVO_PESEN_VSEGO = 20;

    const char* massiv_pesen[KOLICHESTVO_PESEN_VSEGO];
    const char* massivGrupp[KOLICHESTVO_PESEN_VSEGO];
    int popularnost_pesen[KOLICHESTVO_PESEN_VSEGO];


    const char* pesny_VTope[KOLICHESTVO_PESEN_VSEGO];
    const char* gruppy_v_tope[KOLICHESTVO_PESEN_VSEGO];
    int popularnost_pesen_v_tope[KOLICHESTVO_PESEN_VSEGO];

    int realnoe_kolichestvo_pesen = 0;
    int nomerTeckusheyPensy = 0;

    massiv_pesen[0] = "Should I Stay or Should I Go";
    massivGrupp[0] = "The Clash";
    popularnost_pesen[0] = 0;

    massiv_pesen[1] = "Baby don't lie to me";
    massivGrupp[1] = "The Fratellis";
    popularnost_pesen[1] = 0;

    massiv_pesen[2] = "Ole Black 'n' Blue Eyes";
    massivGrupp[2] = "The Fratellis";
    popularnost_pesen[2] = 0;

    massiv_pesen[3] = "Like A Champion";
    massivGrupp[3] = "The Baseballs";
    popularnost_pesen[3] = 0;

    massiv_pesen[4] = "Jackie and Wilson";
    massivGrupp[4] = "Hoizer";
    popularnost_pesen[4] = 0;

    massiv_pesen[5] = "Mountains";
    massivGrupp[5] = "Message To Bears";
    popularnost_pesen[5] = 0;

    massiv_pesen[6] = "When It's Cold I'd Like to Die";
    massivGrupp[6] = "Moby";
    popularnost_pesen[6] = 0;

    massiv_pesen[7] = "Damn Your Eyes";
    massivGrupp[7] = "Alex Clare";
    popularnost_pesen[7] = 0;

    massiv_pesen[8] = "Heroes";
    massivGrupp[8] = "David Bowie";
    popularnost_pesen[8] = 0;

    massiv_pesen[9] = "No Diggity";
    massivGrupp[9] = "Chet Faker";
    popularnost_pesen[9] = 0;

    massiv_pesen[10] = "Inhaler";
    massivGrupp[10] = "Foals";
    popularnost_pesen[10] = 0;

    massiv_pesen[11] = "London Thunder";
    massivGrupp[11] = "Foals";
    popularnost_pesen[11] = 0;

    massiv_pesen[12] = "Spanish Sahara";
    massivGrupp[12] = "Foals";
    popularnost_pesen[12] = 0;

    massiv_pesen[13] = "Asleep";
    massivGrupp[13] = "The Smiths";
    popularnost_pesen[13] = 0;

    realnoe_kolichestvo_pesen = 14;

    bool prodolgitRabotu = true;

    while (prodolgitRabotu) { int vybor = -1;

        std::cout << std::endl << "Now playing: " <<
                  massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;

        if (nomerTeckusheyPensy > 0) {std::cout << "Previous song: " <<
                        massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << std::endl;
        }

        if (nomerTeckusheyPensy <realnoe_kolichestvo_pesen - 1) {
            std::cout << "Next song: " <<
                          massivGrupp[nomerTeckusheyPensy + 1] << " - " << massiv_pesen[nomerTeckusheyPensy + 1] << std::endl;
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
                const char* TMP = massiv_pesen[nomerTeckusheyPensy];
                const char* TMP2 = massivGrupp[nomerTeckusheyPensy];
                int tekushayPopularnost = popularnost_pesen[nomerTeckusheyPensy];


                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i)
                {
                    const char* tmp =massiv_pesen[i];
                    const char* temp= massivGrupp[i];
                    int variable = popularnost_pesen[i];

                    int j = i-1;
                    while (j> -1 && std::strcmp(temp, massivGrupp[j]) != 0) {
                        massiv_pesen[j + 1] = massiv_pesen[j];
                        massivGrupp[j +1] = massivGrupp[j];
                        popularnost_pesen[j+1] = popularnost_pesen[j];
                        --j;
                    }

                    massiv_pesen[j+1] = tmp;
                    massivGrupp[j+1] = temp;
                    popularnost_pesen[j + 1] = variable;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    std::cout << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(TMP2, massivGrupp[i]) == 0
                        && std::strcmp(TMP, massiv_pesen[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }
                }

                std::cout << "Current song position: " << nomerTeckusheyPensy + 1 << std::endl;

                std::cout << "Now playing: " <<
                          massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1) {
                    std::cout << "Next song: " <<
                              massivGrupp[nomerTeckusheyPensy + 1] << " - " << massiv_pesen[nomerTeckusheyPensy + 1] << std::endl;
                }
                break;
            }

            case 4: {
                const char* nazvanieTekusheyPesny = massiv_pesen[nomerTeckusheyPensy];
                const char* nazvanieTekusheyGruppy = massivGrupp[nomerTeckusheyPensy];
                int popularnost_tekushey_Gruppy = popularnost_pesen[nomerTeckusheyPensy];

                for (int i = 1; i<realnoe_kolichestvo_pesen; ++i) {
                    const char* vremenoeNazvanyePesny = massiv_pesen[i];
                    const char* vremenoeNazvanyeGruppy = massivGrupp[i];
                    int popularnostVremennoyPesny = popularnost_pesen[i];

                    int j = i-1;
                    while (j >-1 && std::strcmp(vremenoeNazvanyePesny,massiv_pesen[j])!=0){
                        massiv_pesen[j + 1] = massiv_pesen[j];
                        massivGrupp[j + 1] = massivGrupp[j];
                        popularnost_pesen[j + 1] = popularnost_pesen[j];
                        --j;}


                    massiv_pesen[j + 1] = vremenoeNazvanyePesny;
                    massivGrupp[j + 1] = vremenoeNazvanyeGruppy;
                    popularnost_pesen[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i<realnoe_kolichestvo_pesen; ++i)
                {
                    std::cout << massivGrupp[i] <<" - " << massiv_pesen[i] << std::endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i){
                    if (std::strcmp(nazvanieTekusheyGruppy, massivGrupp[i]) == 0
                        && std::strcmp(nazvanieTekusheyPesny, massiv_pesen[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }}

                std::cout<<"Current song position: "<<nomerTeckusheyPensy<< std::endl;

                std::cout<<"Now playing: " <<
                          massivGrupp[nomerTeckusheyPensy]<<" - "<< massiv_pesen[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1) {
                    std::cout << "Next song: " <<
                              massivGrupp[nomerTeckusheyPensy + 1] << " - " << massiv_pesen[nomerTeckusheyPensy + 1] << std::endl;
                }
                break;
            }

            case 5: {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool nashel=false;
                for (int i=0; i<realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(str.c_str(), massivGrupp[i]) == 0) {
                        std::cout << i + 1 << ") " << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
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
                    if (std::strcmp(str2.c_str(), massiv_pesen[i]) == 0) {
                        std::cout << i + 1 << ") " << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
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
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    std::cout << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "Ok, here is the playlist: " << std::endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i){
                    std::cout << i + 1 << ") " << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
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
                          massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy<realnoe_kolichestvo_pesen-1) {
                    std::cout << "Next song: " <<
                              massivGrupp[nomerTeckusheyPensy + 1]<< " - "<< massiv_pesen[nomerTeckusheyPensy + 1] << std::endl;
                }

                break;
            }

            case 9: {
                std::cout<< "Now playing: "<<
                          massivGrupp[nomerTeckusheyPensy] <<" - " <<massiv_pesen[nomerTeckusheyPensy] << std::endl;
                break;
            }

            case 10: {
                for (int i =0; i < realnoe_kolichestvo_pesen;++i) {
                    pesny_VTope[i]= massiv_pesen[i];
                    gruppy_v_tope[i] =massivGrupp[i];
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

                for(int i=0;i <realnoe_kolichestvo_pesen;++i){
                    std::cout<< (i + 1) << ") "<< gruppy_v_tope[i]<< " - "<< pesny_VTope[i] << std::endl;
                }

                break;
            }

            case 11: {const char* currentSongName = massiv_pesen[nomerTeckusheyPensy];
                const char* currentBandName = massivGrupp[nomerTeckusheyPensy];
                int currentSongPopularity = popularnost_pesen[nomerTeckusheyPensy];

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i) { const char* vremenoeNazvanyePesny = massiv_pesen[i];
                    const char* vremenoeNazvanyeGruppy = massivGrupp[i];
                    int popularnostVremennoyPesny = popularnost_pesen[i];

                    int j = i - 1;
                    while (j > -1 && popularnost_pesen[j] < popularnostVremennoyPesny) {
                      massiv_pesen[j + 1] = massiv_pesen[j];
                      massivGrupp[j + 1] = massivGrupp[j];
                      popularnost_pesen[j + 1] = popularnost_pesen[j];
                      --j;
                    }


                    massiv_pesen[j + 1] = vremenoeNazvanyePesny;
                    massivGrupp[j + 1] = vremenoeNazvanyeGruppy;
                    popularnost_pesen[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    std::cout << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    if (std::strcmp(currentBandName, massivGrupp[i]) == 0
                        && std::strcmp(currentSongName, massiv_pesen[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break; }
                }

                std::cout << "Now playing: " << massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;

                std::cout << "Song, you are listening on " << nomerTeckusheyPensy + 1 << " position of chart" << std::endl;
                break;
            }


            case 12: {
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    pesny_VTope[i] = massiv_pesen[i];
                        gruppy_v_tope[i] = massivGrupp[i];
                    popularnost_pesen_v_tope[i] = popularnost_pesen[i]; }

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i) { const char* temp1 = pesny_VTope[i]; const char* temp2 = gruppy_v_tope[i];
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