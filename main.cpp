#include <iostream>
#include <string>


int main () {
    const int number_of_songs = 20;

    const char* massiv_song[number_of_songs];
    const char* massiv_band[number_of_songs];
    int popular_songs[number_of_songs];


    const char* top_song[number_of_songs];
    const char*  in_the_top_group[number_of_songs];
    int popular_songs_in_the_top[number_of_songs];

    int realnoe_kolichestvo_pesen = 0;
    int nomerTeckusheyPensy = 0;

    massiv_song[0] = "Should I Stay or Should I Go";
    massiv_band[0] = "The Clash";
    popular_songs[0] = 0;

    massiv_song[1] = "Baby don't lie to me";
    massiv_band[1] = "The Fratellis";
    popular_songs[1] = 0;

    massiv_song[2] = "Ole Black 'n' Blue Eyes";
    massiv_band[2] = "The Fratellis";
    popular_songs[2] = 0;

    massiv_song[3] = "Like A Champion";
    massiv_band[3] = "The Baseballs";
    popular_songs[3] = 0;

    massiv_song[4] = "Jackie and Wilson";
    massiv_band[4] = "Hoizer";
    popular_songs[4] = 0;

    massiv_song[5] = "Mountains";
    massiv_band[5] = "Message To Bears";
    popular_songs[5] = 0;

    massiv_song[6] = "When It's Cold I'd Like to Die";
    massiv_band[6] = "Moby";
    popular_songs[6] = 0;

    massiv_song[7] = "Damn Your Eyes";
    massiv_band[7] = "Alex Clare";
    popular_songs[7] = 0;

    massiv_song[8] = "Heroes";
    massiv_band[8] = "David Bowie";
    popular_songs[8] = 0;

    massiv_song[9] = "No Diggity";
    massiv_band[9] = "Chet Faker";
    popular_songs[9] = 0;

    massiv_song[10] = "Inhaler";
    massiv_band[10] = "Foals";
    popular_songs[10] = 0;

    massiv_song[11] = "London Thunder";
    massiv_band[11] = "Foals";
    popular_songs[11] = 0;

    massiv_song[12] = "Spanish Sahara";
    massiv_band[12] = "Foals";
    popular_songs[12] = 0;

    massiv_song[13] = "Asleep";
    massiv_band[13] = "The Smiths";
    popular_songs[13] = 0;

    realnoe_kolichestvo_pesen = 14;

    bool prodolgitRabotu = true;

    while (prodolgitRabotu) { int vybor = -1;

        std::cout << std::endl << "Now playing: " <<
                  massiv_band[nomerTeckusheyPensy] << " - " << massiv_song[nomerTeckusheyPensy] << std::endl;

        if (nomerTeckusheyPensy > 0) {std::cout << "Previous song: " <<
                        massiv_band[nomerTeckusheyPensy - 1] << " - " << massiv_song[nomerTeckusheyPensy - 1] << std::endl;
        }

        if (nomerTeckusheyPensy <realnoe_kolichestvo_pesen - 1) {
            std::cout << "Next song: " <<
                          massiv_band[nomerTeckusheyPensy + 1] << " - " << massiv_song[nomerTeckusheyPensy + 1] << std::endl;
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
                const char* TMP = massiv_song[nomerTeckusheyPensy];
                const char* TMP2 = massiv_band[nomerTeckusheyPensy];
                int tekushayPopularnost = popular_songs[nomerTeckusheyPensy];


                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i)
                {
                    const char* tmp =massiv_song[i];
                    const char* temp= massiv_band[i];
                    int variable = popular_songs[i];

                    int j = i-1;
                    while (j> -1 && std::strcmp(temp, massiv_band[j]) != 0) {
                        massiv_song[j + 1] = massiv_song[j];
                        massiv_band[j +1] = massiv_band[j];
                        popular_songs[j+1] = popular_songs[j];
                        --j;
                    }

                    massiv_song[j+1] = tmp;
                    massiv_band[j+1] = temp;
                    popular_songs[j + 1] = variable;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    std::cout << massiv_band[i] << " - " << massiv_song[i] << std::endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(TMP2, massiv_band[i]) == 0
                        && std::strcmp(TMP, massiv_song[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }
                }

                std::cout << "Current song position: " << nomerTeckusheyPensy + 1 << std::endl;

                std::cout << "Now playing: " <<
                          massiv_band[nomerTeckusheyPensy] << " - " << massiv_song[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              massiv_band[nomerTeckusheyPensy - 1] << " - " << massiv_song[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1) {
                    std::cout << "Next song: " <<
                              massiv_band[nomerTeckusheyPensy + 1] << " - " << massiv_song[nomerTeckusheyPensy + 1] << std::endl;
                }
                break;
            }

            case 4: {
                const char* nazvanieTekusheyPesny = massiv_song[nomerTeckusheyPensy];
                const char* nazvanieTekusheyGruppy = massiv_band[nomerTeckusheyPensy];
                int popularnost_tekushey_Gruppy = popular_songs[nomerTeckusheyPensy];

                for (int i = 1; i<realnoe_kolichestvo_pesen; ++i) {
                    const char* vremenoeNazvanyePesny = massiv_song[i];
                    const char* vremenoeNazvanyeGruppy = massiv_band[i];
                    int popularnostVremennoyPesny = popular_songs[i];

                    int j = i-1;
                    while (j >-1 && std::strcmp(vremenoeNazvanyePesny,massiv_song[j])!=0){
                        massiv_song[j + 1] = massiv_song[j];
                        massiv_band[j + 1] = massiv_band[j];
                        popular_songs[j + 1] = popular_songs[j];
                        --j;}


                    massiv_song[j + 1] = vremenoeNazvanyePesny;
                    massiv_band[j + 1] = vremenoeNazvanyeGruppy;
                    popular_songs[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i<realnoe_kolichestvo_pesen; ++i)
                {
                    std::cout << massiv_band[i] <<" - " << massiv_song[i] << std::endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i){
                    if (std::strcmp(nazvanieTekusheyGruppy, massiv_band[i]) == 0
                        && std::strcmp(nazvanieTekusheyPesny, massiv_song[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }}

                std::cout<<"Current song position: "<<nomerTeckusheyPensy<< std::endl;

                std::cout<<"Now playing: " <<
                          massiv_band[nomerTeckusheyPensy]<<" - "<< massiv_song[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              massiv_band[nomerTeckusheyPensy - 1] << " - " << massiv_song[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1) {
                    std::cout << "Next song: " <<
                              massiv_band[nomerTeckusheyPensy + 1] << " - " << massiv_song[nomerTeckusheyPensy + 1] << std::endl;
                }
                break;
            }

            case 5: {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool nashel=false;
                for (int i=0; i<realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(str.c_str(), massiv_band[i]) == 0) {
                        std::cout << i + 1 << ") " << massiv_band[i] << " - " << massiv_song[i] << std::endl;
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
                    if (std::strcmp(str2.c_str(), massiv_song[i]) == 0) {
                        std::cout << i + 1 << ") " << massiv_band[i] << " - " << massiv_song[i] << std::endl;
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
                    std::cout << massiv_band[i] << " - " << massiv_song[i] << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "Ok, here is the playlist: " << std::endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i){
                    std::cout << i + 1 << ") " << massiv_band[i] << " - " << massiv_song[i] << std::endl;
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
                          massiv_band[nomerTeckusheyPensy] << " - " << massiv_song[nomerTeckusheyPensy] << std::endl;

                if (nomerTeckusheyPensy > 0) {
                    std::cout << "Previous song: " <<
                              massiv_band[nomerTeckusheyPensy - 1] << " - " << massiv_song[nomerTeckusheyPensy - 1] << std::endl;
                }

                if (nomerTeckusheyPensy<realnoe_kolichestvo_pesen-1) {
                    std::cout << "Next song: " <<
                              massiv_band[nomerTeckusheyPensy + 1]<< " - "<< massiv_song[nomerTeckusheyPensy + 1] << std::endl;
                }

                break;
            }

            case 9: {
                std::cout<< "Now playing: "<<
                          massiv_band[nomerTeckusheyPensy] <<" - " <<massiv_song[nomerTeckusheyPensy] << std::endl;
                break;
            }

            case 10: {
                for (int i =0; i < realnoe_kolichestvo_pesen;++i) {
                    top_song[i]= massiv_song[i];
                     in_the_top_group[i] =massiv_band[i];
                    popular_songs_in_the_top[i]=popularnost_pesen[i];
                }

                for (int i = 1;i< realnoe_kolichestvo_pesen;++i) {
const char* vremenoeNazvanyePesny = top_song[i];
                    const char* vremenoeNazvanyeGruppy =  in_the_top_group[i];int popularnostVremennoyPesny = popular_songs_in_the_top[i];

                    int j = i - 1;
                    while (j > -1 && popular_songs_in_the_top[j] < popularnostVremennoyPesny) {
                        top_song[j + 1] = top_song[j];
                   in_the_top_group[j + 1] =  in_the_top_group[j];
                        popular_songs_in_the_top[j + 1] = popular_songs_in_the_top[j];
                        --j;
                    }

                    top_song[j + 1] = vremenoeNazvanyePesny;
                     in_the_top_group[j + 1] = vremenoeNazvanyeGruppy;
                    popular_songs_in_the_top[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "Chart: " << std::endl;

                for(int i=0;i <realnoe_kolichestvo_pesen;++i){
                    std::cout<< (i + 1) << ") "<<  in_the_top_group[i]<< " - "<< top_song[i] << std::endl;
                }

                break;
            }

            case 11: {const char* currentSongName = massiv_song[nomerTeckusheyPensy];
                const char* currentBandName = massiv_band[nomerTeckusheyPensy];
                int currentSongPopularity = popular_songs[nomerTeckusheyPensy];

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i) { const char* vremenoeNazvanyePesny = massiv_song[i];
                    const char* vremenoeNazvanyeGruppy = massiv_band[i];
                    int popularnostVremennoyPesny = popular_songs[i];

                    int j = i - 1;
                    while (j > -1 && popular_songs[j] < popularnostVremennoyPesny) {
                      massiv_song[j + 1] = massiv_song[j];
                      massiv_band[j + 1] = massiv_band[j];
                      popular_songs[j + 1] = popular_songs[j];
                      --j;
                    }


                    massiv_song[j + 1] = vremenoeNazvanyePesny;
                    massiv_band[j + 1] = vremenoeNazvanyeGruppy;
                    popular_songs[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    std::cout << massiv_band[i] << " - " << massiv_song[i] << std::endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    if (std::strcmp(currentBandName, massiv_band[i]) == 0
                        && std::strcmp(currentSongName, massiv_song[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break; }
                }

                std::cout << "Now playing: " << massiv_band[nomerTeckusheyPensy] << " - " << massiv_song[nomerTeckusheyPensy] << std::endl;

                std::cout << "Song, you are listening on " << nomerTeckusheyPensy + 1 << " position of chart" << std::endl;
                break;
            }


            case 12: {
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    top_song[i] = massiv_song[i];
                         in_the_top_group[i] = massiv_band[i];
                    popular_songs_in_the_top[i] = popular_songs[i]; }

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i) { const char* temp1 = top_song[i]; const char* temp2 =  in_the_top_group[i];
                    int temp3 = popular_songs_in_the_top[i];

                    int j = i - 1;
                    while (j > -1 && popular_songs_in_the_top[j] < temp3)
                    {
                        top_song[j + 1] = top_song[j];
                         in_the_top_group[j + 1] =  in_the_top_group[j];
                        popular_songs_in_the_top[j + 1] = popular_songs_in_the_top[j];



                        --j;
                    }

                    top_song[j + 1] = temp1;
                         in_the_top_group[j + 1] = temp2;
                    popular_songs_in_the_top[j + 1] = temp3;
                }

                    std::cout << "Most popular band is: " <<  in_the_top_group[0] << std::endl;
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