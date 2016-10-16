#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct Pesni
{
	const char* pesni;
	const char* Gruppa;
	int popularnost;
};

int main () {
    const int KOLICHESTVO_PESEN_VSEGO = 20;
	
	Pesni Massiv[KOLICHESTVO_PESEN_VSEGO] = {

		{"Should I Stay or Should I Go"  , "The Clash"       , 0},
		{"Baby don't lie to me"          , "The Fratellis"   , 0},
		{"Ole Black 'n' Blue Eyes"       , "The Fratellis"   , 0},
		{"Like A Champion"               , "The Baseballs"   , 0},
		{"Jackie and Wilson"             , "Hoizer"          , 0},
		{"Mountains"                     , "Message To Bears", 0},
		{"When It's Cold I'd Like to Die", "Moby"            , 0},
		{"Damn Your Eyes"                , "Alex Clare"      , 0},
		{"Heroes"                        , "David Bowie"     , 0},
		{"No Diggity"                    , "Chet Faker"      , 0},
		{"Inhaler"                       , "Foals"           , 0},
		{"London Thunder"                , "Foals"           , 0},
		{"Spanish Sahara"                , "Foals"           , 0},
		{"Asleep"                        , "The Smiths"      , 0}

	};
    
    const char* pesny_VTope[KOLICHESTVO_PESEN_VSEGO];
    const char* gruppy_v_tope[KOLICHESTVO_PESEN_VSEGO];
    int popularnost_pesen_v_tope[KOLICHESTVO_PESEN_VSEGO];

    int realnoe_kolichestvo_pesen = 0;
    int nomerTeckusheyPensy = 0;
	
    realnoe_kolichestvo_pesen = 14;

    bool prodolgitRabotu = true;

    while (prodolgitRabotu) { int vybor = -1;

        cout << endl << "Now playing: " <<
			Massiv[nomerTeckusheyPensy].Gruppa << " - " << Massiv[nomerTeckusheyPensy].pesni << endl;

        if (nomerTeckusheyPensy > 0) {cout << "Previous song: " <<
            Massiv[nomerTeckusheyPensy - 1].Gruppa << " - " << Massiv[nomerTeckusheyPensy - 1].pesni << endl;
        }

        if (nomerTeckusheyPensy <realnoe_kolichestvo_pesen - 1) {
            cout << "Next song: " <<
                Massiv[nomerTeckusheyPensy + 1].Gruppa << " - " << Massiv[nomerTeckusheyPensy + 1].pesni << endl;
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
                    ++Massiv[nomerTeckusheyPensy].popularnost; }
                break;
            }

            case 2: {
                if (nomerTeckusheyPensy > 0)
                {
                    --nomerTeckusheyPensy;
                    ++Massiv[nomerTeckusheyPensy].popularnost;
                }
                break;
            }

            case 3: {
                const char* TMP = Massiv[nomerTeckusheyPensy].pesni;
                const char* TMP2 = Massiv[nomerTeckusheyPensy].Gruppa;
                int tekushayPopularnost = Massiv[nomerTeckusheyPensy].popularnost;


                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i)
                {
                    const char* tmp =Massiv[i].pesni;
                    const char* temp= Massiv[i].Gruppa;
                    int variable = Massiv[i].popularnost;
                    int j = i-1;
					
                    while (j> -1 && std::strcmp(temp, Massiv[j].Gruppa) != 0) {
                        Massiv[j + 1].pesni = Massiv[j].pesni;
                        Massiv[j +1].Gruppa = Massiv[j].Gruppa;
                        Massiv[j+1].popularnost = Massiv[j].popularnost;
                        --j;
                    }

                    Massiv[j+1].pesni = tmp;
                    Massiv[j+1].Gruppa = temp;
                    Massiv[j + 1].popularnost = variable;
                }

                cout << "New playlist order " << endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    cout << Massiv[i].Gruppa << " - " << Massiv[i].pesni << endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(TMP2, Massiv[i].Gruppa) == 0
                        && std::strcmp(TMP, Massiv[i].pesni) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }
                }

                cout << "Current song position: " << nomerTeckusheyPensy + 1 << endl;

                cout << "Now playing: " <<
                    Massiv[nomerTeckusheyPensy].Gruppa << " - " << Massiv[nomerTeckusheyPensy].pesni << endl;

                if (nomerTeckusheyPensy > 0) {
                    cout << "Previous song: " <<
                        Massiv[nomerTeckusheyPensy - 1].Gruppa << " - " << Massiv[nomerTeckusheyPensy - 1].pesni << endl;
                }

                if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1) {
                    cout << "Next song: " <<
                        Massiv[nomerTeckusheyPensy + 1].Gruppa << " - " << Massiv[nomerTeckusheyPensy + 1].pesni << endl;
                }
                break;
            }

            case 4: {
                const char* nazvanieTekusheyPesny = Massiv[nomerTeckusheyPensy].pesni;
                const char* nazvanieTekusheyGruppy = Massiv[nomerTeckusheyPensy].Gruppa;
                int popularnost_tekushey_Gruppy = Massiv[nomerTeckusheyPensy].popularnost;

                for (int i = 1; i<realnoe_kolichestvo_pesen; ++i) {
                    const char* vremenoeNazvanyePesny = Massiv[i].pesni;
                    const char* vremenoeNazvanyeGruppy = Massiv[i].Gruppa;
                    int popularnostVremennoyPesny = Massiv[i].popularnost;
                    int j = i-1;
					
                    while (j >-1 && std::strcmp(vremenoeNazvanyePesny,Massiv[j].pesni)!=0){
                        Massiv[j + 1].pesni = Massiv[j].pesni;
                        Massiv[j + 1].Gruppa = Massiv[j].Gruppa;
                        Massiv[j + 1].popularnost = Massiv[j].popularnost;
                        --j;}

                    Massiv[j + 1].pesni = vremenoeNazvanyePesny;
                    Massiv[j + 1].Gruppa = vremenoeNazvanyeGruppy;
                    Massiv[j + 1].popularnost = popularnostVremennoyPesny;
                }

                cout << "New playlist order " << endl;

                for (int i = 0; i<realnoe_kolichestvo_pesen; ++i)
                {
                    cout << Massiv[i].Gruppa <<" - " << Massiv[i].pesni << endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i){
					
                    if (std::strcmp(nazvanieTekusheyGruppy, Massiv[i].Gruppa) == 0
                        && std::strcmp(nazvanieTekusheyPesny, Massiv[i].pesni) == 0) {
                        nomerTeckusheyPensy = i;
                        break;
                    }}

                cout<<"Current song position: "<<nomerTeckusheyPensy<< endl;

                cout<<"Now playing: " <<
                    Massiv[nomerTeckusheyPensy].Gruppa<<" - "<< Massiv[nomerTeckusheyPensy].pesni << endl;

                if (nomerTeckusheyPensy > 0) {
                    cout << "Previous song: " <<
                        Massiv[nomerTeckusheyPensy - 1].Gruppa << " - " << Massiv[nomerTeckusheyPensy - 1].pesni << endl;
                }

                if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1) {
                    cout << "Next song: " <<
                        Massiv[nomerTeckusheyPensy + 1].Gruppa << " - " << Massiv[nomerTeckusheyPensy + 1].pesni << endl;
                }
                break;
            }

            case 5: {
                std::string str;
                cout << "Input band name you are looking for: " << endl;
                std::getline(cin, str);
                bool nashel=false;
				
                for (int i=0; i<realnoe_kolichestvo_pesen; ++i) {
                    if (std::strcmp(str.c_str(), Massiv[i].Gruppa) == 0) {
                        cout << i + 1 << ") " << Massiv[i].Gruppa << " - " << Massiv[i].pesni << endl;
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
                    if (std::strcmp(str2.c_str(), Massiv[i].pesni) == 0) {
                        cout << i + 1 << ") " << Massiv[i].Gruppa << " - " << Massiv[i].pesni << endl;
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
                    cout << Massiv[i].Gruppa << " - " << Massiv[i].pesni << endl;
                }
                break;
            }

            case 8: {
                cout << "Ok, here is the playlist: " << endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i){
                    cout << i + 1 << ") " << Massiv[i].Gruppa << " - " << Massiv[i].pesni << endl;
                }

                cout <<"Enter song position, you want to play: " << endl;

                int songNomer;

                cin >> songNomer;

                cin.ignore();

                --songNomer;

                if (songNomer > -1 && songNomer<realnoe_kolichestvo_pesen) {
                    nomerTeckusheyPensy = songNomer;
                    ++Massiv[nomerTeckusheyPensy].popularnost;
                }

                cout << "Now playing: " <<
                          Massiv[nomerTeckusheyPensy].Gruppa << " - " << Massiv[nomerTeckusheyPensy].pesni << endl;

                if (nomerTeckusheyPensy > 0) {
                    cout << "Previous song: " <<
                              Massiv[nomerTeckusheyPensy - 1].Gruppa << " - " << Massiv[nomerTeckusheyPensy - 1].pesni << endl;
                }

                if (nomerTeckusheyPensy<realnoe_kolichestvo_pesen-1) {
                    cout << "Next song: " <<
                              Massiv[nomerTeckusheyPensy + 1].Gruppa<< " - "<< Massiv[nomerTeckusheyPensy + 1].pesni << endl;
                }

                break;
            }

            case 9: {
                cout<< "Now playing: "<<
                    Massiv[nomerTeckusheyPensy].Gruppa <<" - " <<Massiv[nomerTeckusheyPensy].pesni << endl;
                break;
            }

            case 10: {
                for (int i =0; i < realnoe_kolichestvo_pesen;++i) {
                    pesny_VTope[i]= Massiv[i].pesni;
                    gruppy_v_tope[i] =Massiv[i].Gruppa;
                    popularnost_pesen_v_tope[i]=Massiv[i].popularnost;
                }

                for (int i = 1;i< realnoe_kolichestvo_pesen;++i) {
					
                    const char* vremenoeNazvanyePesny = pesny_VTope[i];
                    const char* vremenoeNazvanyeGruppy = gruppy_v_tope[i];
					int popularnostVremennoyPesny = popularnost_pesen_v_tope[i];
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

            case 11: {const char* currentSongName = Massiv[nomerTeckusheyPensy].pesni;
                const char* currentBandName = Massiv[nomerTeckusheyPensy].Gruppa;
                int currentSongPopularity = Massiv[nomerTeckusheyPensy].popularnost;

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i) { const char* vremenoeNazvanyePesny = Massiv[i].pesni;
                    const char* vremenoeNazvanyeGruppy = Massiv[i].Gruppa;
                    int popularnostVremennoyPesny = Massiv[i].popularnost;
                    int j = i - 1;
					
                    while (j > -1 && Massiv[j].popularnost < popularnostVremennoyPesny) {
                      Massiv[j + 1].pesni = Massiv[j].pesni;
                      Massiv[j + 1].Gruppa = Massiv[j].Gruppa;
                      Massiv[j + 1].popularnost = Massiv[j].popularnost;
                      --j;
                    }

                    Massiv[j + 1].pesni = vremenoeNazvanyePesny;
                    Massiv[j + 1].Gruppa = vremenoeNazvanyeGruppy;
                    Massiv[j + 1].popularnost = popularnostVremennoyPesny;
                }

                cout << "New playlist order " << endl;

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i) {
                    cout << Massiv[i].Gruppa << " - " << Massiv[i].pesni << endl;
                }

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    if (std::strcmp(currentBandName, Massiv[i].Gruppa) == 0
                        && std::strcmp(currentSongName, Massiv[i].pesni) == 0) {
                        nomerTeckusheyPensy = i;
                        break; }
                }

                cout << "Now playing: " << Massiv[nomerTeckusheyPensy].Gruppa << " - " << Massiv[nomerTeckusheyPensy].pesni << endl;
				
                cout << "Song, you are listening on " << nomerTeckusheyPensy + 1 << " position of chart" << endl;
                break;
            }


            case 12: {
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    pesny_VTope[i] = Massiv[i].pesni;
                    gruppy_v_tope[i] = Massiv[i].Gruppa;
                    popularnost_pesen_v_tope[i] = Massiv[i].popularnost; }

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