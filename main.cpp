#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

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

        cout << endl << "Now playing: " <<
                  massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << endl;

        if (nomerTeckusheyPensy > 0) {cout << "Previous song: " <<
                        massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << endl;
        }

        if (nomerTeckusheyPensy <realnoe_kolichestvo_pesen - 1) {
            cout << "Next song: " <<
                          massivGrupp[nomerTeckusheyPensy + 1] << " - " << massiv_pesen[nomerTeckusheyPensy + 1] << endl;
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

        cin >> vybor;

        cin.ignore();

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

                cout << "New playlist order " << endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    cout << massivGrupp[i] << " - " << massiv_pesen[i] << endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(TMP2, massivGrupp[i]) == 0
                        && std::strcmp(TMP, massiv_pesen[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }
                }

                cout << "Current song position: " << nomerTeckusheyPensy + 1 << endl;

                cout << "Now playing: " <<
                          massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << endl;

                if (nomerTeckusheyPensy > 0) {
                    cout << "Previous song: " <<
                              massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << endl;
                }

                if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1) {
                    cout << "Next song: " <<
                              massivGrupp[nomerTeckusheyPensy + 1] << " - " << massiv_pesen[nomerTeckusheyPensy + 1] << endl;
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

                cout << "New playlist order " << endl;

                for (int i = 0; i<realnoe_kolichestvo_pesen; ++i)
                {
                    cout << massivGrupp[i] <<" - " << massiv_pesen[i] << endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i){
                    if (std::strcmp(nazvanieTekusheyGruppy, massivGrupp[i]) == 0
                        && std::strcmp(nazvanieTekusheyPesny, massiv_pesen[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }}

                cout<<"Current song position: "<<nomerTeckusheyPensy<< endl;

                cout<<"Now playing: " <<
                          massivGrupp[nomerTeckusheyPensy]<<" - "<< massiv_pesen[nomerTeckusheyPensy] << endl;

                if (nomerTeckusheyPensy > 0) {
                    cout << "Previous song: " <<
                              massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << endl;
                }

                if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1) {
                    cout << "Next song: " <<
                              massivGrupp[nomerTeckusheyPensy + 1] << " - " << massiv_pesen[nomerTeckusheyPensy + 1] << endl;
                }
                break;
            }

            case 5: {
                std::string str;
                cout << "Input band name you are looking for: " << endl;
                std::getline(cin, str);
                bool nashel=false;
                for (int i=0; i<realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(str.c_str(), massivGrupp[i]) == 0) {
                        cout << i + 1 << ") " << massivGrupp[i] << " - " << massiv_pesen[i] << endl;
                        nashel = true;
                    }
                }

                if(nashel){
                    cout << "Now you can play any song by it position" << endl;
                } else
                {
                    cout << "There are no pesny with band name like this " << str << endl;
                }

                break;
            }

            case 6: {
                std::string str2;
                cout << "Input song name you are looking for: " << endl;
                std::getline(cin, str2);
                bool nashel = false;
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(str2.c_str(), massiv_pesen[i]) == 0) {
                        cout << i + 1 << ") " << massivGrupp[i] << " - " << massiv_pesen[i] << endl;
                        nashel = true;
                    }
                }

                if (nashel)
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
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    cout << massivGrupp[i] << " - " << massiv_pesen[i] << endl;
                }
                break;
            }

            case 8: {
                cout << "Ok, here is the playlist: " << endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i){
                    cout << i + 1 << ") " << massivGrupp[i] << " - " << massiv_pesen[i] << endl;
                }

                cout <<"Enter song position, you want to play: " << endl;

                int songNomer;

                cin >> songNomer;

                cin.ignore();

                --songNomer;

                if (songNomer > -1 && songNomer<realnoe_kolichestvo_pesen) {
                    nomerTeckusheyPensy = songNomer;
                    ++popularnost_pesen[nomerTeckusheyPensy];
                }

                cout << "Now playing: " <<
                          massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << endl;

                if (nomerTeckusheyPensy > 0) {
                    cout << "Previous song: " <<
                              massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << endl;
                }

                if (nomerTeckusheyPensy<realnoe_kolichestvo_pesen-1) {
                    cout << "Next song: " <<
                              massivGrupp[nomerTeckusheyPensy + 1]<< " - "<< massiv_pesen[nomerTeckusheyPensy + 1] << endl;
                }

                break;
            }

            case 9: {
                cout<< "Now playing: "<<
                          massivGrupp[nomerTeckusheyPensy] <<" - " <<massiv_pesen[nomerTeckusheyPensy] << endl;
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

                cout << "Chart: " << endl;

                for(int i=0;i <realnoe_kolichestvo_pesen;++i){
                    cout<< (i + 1) << ") "<< gruppy_v_tope[i]<< " - "<< pesny_VTope[i] << endl;
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

                cout << "New playlist order " << endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    cout << massivGrupp[i] << " - " << massiv_pesen[i] << endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    if (std::strcmp(currentBandName, massivGrupp[i]) == 0
                        && std::strcmp(currentSongName, massiv_pesen[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break; }
                }

                cout << "Now playing: " << massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << endl;

                cout << "Song, you are listening on " << nomerTeckusheyPensy + 1 << " position of chart" << endl;
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

                    cout << "Most popular band is: " << gruppy_v_tope[0] << endl;
                break;
            }

            case 13: {
                prodolgitRabotu = false;
                break;
            }

            default:
                cout << "Unknown command." << endl;
        }
    }

    cout << "Goodbye!" << endl;
}