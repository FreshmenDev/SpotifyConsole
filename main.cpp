#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main () 
{
    const int COUNT_SONGS = 20;
	
    const char* Songs[COUNT_SONGS];
    const char* Groups[COUNT_SONGS];
	const char* songs_in_Top[COUNT_SONGS];
    const char* groups_in_Top[COUNT_SONGS];   

    int popularity_Songs[COUNT_SONGS];
    int popularity_songs_in_Top[COUNT_SONGS];
    int real_cout_Songs = 0;
    int number_of_the_current_Song = 0;

	bool isDone = true;

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

    while (isDone) 
	  {
		int selection = -1;

		cout<<endl<<"Now playing: "<<Groups[number_of_the_current_Song]<<" - "<<Songs[number_of_the_current_Song]<<endl;

		if(number_of_the_current_Song > 0) 
		  {
		    cout<<"Previous song: "<<Groups[number_of_the_current_Song - 1]<< " - " <<Songs[number_of_the_current_Song - 1]<<endl;
          }

        if(number_of_the_current_Song < real_cout_Songs - 1) 
		  {
		    cout<<"Next song: "<<Groups[number_of_the_current_Song + 1]<<" - "<<Songs[number_of_the_current_Song + 1]<<endl;
          }

        cout<<"Enter action you want to make: "<<endl;
        cout<<"1) Play next"<<endl;
        cout<<"2) Play prev"<<endl;
        cout<<"3) Group by band"<<endl;
        cout<<"4) Group by song name"<<endl;
		cout<<"5) Search song by band "<<endl;
		cout<<"6) Search song by name "<<endl;
        cout<<"7) Show playlist "<<endl;
	    cout<<"8) Play specific song (specified by position) "<<endl;
		cout<<"9) What is playing now? "<<endl;
		cout<<"10) Show my chart "<<endl;
		cout<<"11) Sort by popularity "<<endl;
	    cout<<"12) Show the most popular band "<<endl;
        cout<<"13) Exit "<<endl;

        cin>>selection;
		cin.ignore();

        switch(selection) 
		  {
            case 1: 
		      {
                if(number_of_the_current_Song != real_cout_Songs - 1) 
			      {
                    ++number_of_the_current_Song;
                    ++popularity_Songs[number_of_the_current_Song]; 
			      }
                break;
              }

            case 2: 
		      {
                if(number_of_the_current_Song > 0)
                  {
                    --number_of_the_current_Song;
                    ++popularity_Songs[number_of_the_current_Song];
                  }
                break;
              }

            case 3: 
		      {
                const char* TMP = Songs[number_of_the_current_Song];
                const char* TMP2 = Groups[number_of_the_current_Song];
                int current_Popularity = popularity_Songs[number_of_the_current_Song];

			    for(int i = 1; i < real_cout_Songs; ++i)
			      {
                    const char* tmp =Songs[i];
                    const char* temp= Groups[i];
                    int variable = popularity_Songs[i];
			        int j = i-1;

                    while (j> -1 && std::strcmp(temp, Groups[j]) != 0) 
			          {
                        Songs[j + 1] = Songs[j];
                        Groups[j +1] = Groups[j];
                        popularity_Songs[j+1] = popularity_Songs[j];
                        --j;
                      }
                    Songs[j+1] = tmp;
                    Groups[j+1] = temp;
                    popularity_Songs[j + 1] = variable;
                  }

                cout<< "New playlist order "<<endl;

                for (int i = 0; i < real_cout_Songs; ++i) 
		 	      {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                  }

                for (int i = 0; i < real_cout_Songs; ++i) 
			      {
                    if (strcmp(TMP2, Groups[i])==0 && strcmp(TMP, Songs[i])== 0) 
			          {
                        number_of_the_current_Song = i;
                        break;
                      }
                  }

                std::cout << "Current song position: " << number_of_the_current_Song + 1 << std::endl;
			    std::cout << "Now playing: " <<
                Groups[number_of_the_current_Song] << " - " << Songs[number_of_the_current_Song] << std::endl;

                if (number_of_the_current_Song > 0) 
			      {
                    std::cout << "Previous song: " <<Groups[number_of_the_current_Song - 1] << " - " << Songs[number_of_the_current_Song - 1] << std::endl;
                  }
            
			    if (number_of_the_current_Song < real_cout_Songs - 1) 
				  {
                    std::cout << "Next song: " <<Groups[number_of_the_current_Song + 1] << " - " << Songs[number_of_the_current_Song + 1] << std::endl;
				  }

                break;
              }

            case 4: 
	          {
                const char* nazvanieTekusheyPesny = Songs[number_of_the_current_Song];
                const char* nazvanieTekusheyGruppy = Groups[number_of_the_current_Song];
                int popularnost_tekushey_Gruppy = popularity_Songs[number_of_the_current_Song];

                for (int i = 1; i<real_cout_Songs; ++i) 
				  {
                    const char* vremenoeNazvanyePesny = Songs[i];
                    const char* vremenoeNazvanyeGruppy = Groups[i];
                    int popularnostVremennoyPesny = popularity_Songs[i];
                    int j = i-1;

                    while (j >-1 && std::strcmp(vremenoeNazvanyePesny,Songs[j])!=0)
					  {
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

                for (int i = 0; i<real_cout_Songs; ++i)
                  {
                    std::cout << Groups[i] <<" - " << Songs[i] << std::endl;
                  }

                for (int i = 0; i < real_cout_Songs; ++i)
				  {
                    if (std::strcmp(nazvanieTekusheyGruppy, Groups[i]) == 0 && std::strcmp(nazvanieTekusheyPesny, Songs[i]) == 0) 
					  {
                        number_of_the_current_Song = i;
                        break;
                      }
				  }

                std::cout<<"Current song position: "<<number_of_the_current_Song<< std::endl;
                std::cout<<"Now playing: " << Groups[number_of_the_current_Song]<<" - "<< Songs[number_of_the_current_Song] << std::endl;

                if (number_of_the_current_Song > 0) 
				  {
                    std::cout << "Previous song: " << Groups[number_of_the_current_Song - 1] << " - " << Songs[number_of_the_current_Song - 1] << std::endl;
                  }

                if (number_of_the_current_Song < real_cout_Songs - 1) 
				  {
                    std::cout << "Next song: " <<Groups[number_of_the_current_Song + 1] << " - " << Songs[number_of_the_current_Song + 1] << std::endl;
                  }
                break;
              }

            case 5: 
		      {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool nashel=false;

                for (int i=0; i<real_cout_Songs; ++i) 
				  {
                    if (std::strcmp(str.c_str(), Groups[i]) == 0) 
					  {
                        std::cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << std::endl;
                        nashel = true;
                      }
                  }

                if(nashel)
				  {
                    std::cout << "Now you can play any song by it position" << std::endl;
                  } 

				else
                  {
                    std::cout << "There are no pesny with band name like this " << str << std::endl;
                  }

                break;
              }

            case 6: 
		      {
                std::string str2;
                std::cout << "Input song name you are looking for: " << std::endl;
                std::getline(std::cin, str2);
                bool nashel = false;

                for (int i = 0; i < real_cout_Songs; ++i) 
				  {
                    if (std::strcmp(str2.c_str(), Songs[i]) == 0) 
					  {
                        std::cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << std::endl;
                        nashel = true;
                      }
                  }

                if (nashel)
                  {
                    std::cout << "Now you can play any song by it position" << std::endl;
                  }

                else 
				  {
                    std::cout << "There are no pesny with name like this " << str2 << std::endl;
                  }

                break;
              }

            case 7: 
			  {
                std::cout << "Playlist: " << std::endl;

                for (int i = 0; i < real_cout_Songs; ++i) 
				  {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                  }
                break;
              }

            case 8: 
			  {
                std::cout << "Ok, here is the playlist: " << std::endl;

                for (int i = 0; i < real_cout_Songs; ++i)
				  {
                    std::cout << i + 1 << ") " << Groups[i] << " - " << Songs[i] << std::endl;
                  }

                std::cout <<"Enter song position, you want to play: " << std::endl;

                int songNomer;

                std::cin >> songNomer;
                std::cin.ignore();
                --songNomer;

                if (songNomer > -1 && songNomer<real_cout_Songs) 
				  {
                    number_of_the_current_Song = songNomer;
                    ++popularity_Songs[number_of_the_current_Song];
                  }

                std::cout << "Now playing: " <<Groups[number_of_the_current_Song] << " - " << Songs[number_of_the_current_Song] << std::endl;

                if (number_of_the_current_Song > 0) 
				  {
                    std::cout << "Previous song: " <<Groups[number_of_the_current_Song - 1] << " - " << Songs[number_of_the_current_Song - 1] << std::endl;
                  }

                if (number_of_the_current_Song<real_cout_Songs-1) 
				  {
                    std::cout << "Next song: " <<Groups[number_of_the_current_Song + 1]<< " - "<< Songs[number_of_the_current_Song + 1] << std::endl;
                  }

                break;
              }

            case 9: 
			  {
                std::cout<< "Now playing: "<<Groups[number_of_the_current_Song] <<" - " <<Songs[number_of_the_current_Song] << std::endl;
                break;
              }

            case 10: 
			  {
                for (int i =0; i < real_cout_Songs;++i) 
				  {
                    songs_in_Top[i]= Songs[i];
                    groups_in_Top[i] =Groups[i];
                    popularity_songs_in_Top[i]=popularity_Songs[i];
                  }

                for (int i = 1;i< real_cout_Songs;++i) 
				  {
				    const char* vremenoeNazvanyePesny = songs_in_Top[i];
                    const char* vremenoeNazvanyeGruppy = groups_in_Top[i];
					int popularnostVremennoyPesny = popularity_songs_in_Top[i];
                    int j = i - 1;

                    while (j > -1 && popularity_songs_in_Top[j] < popularnostVremennoyPesny)
					  {
                        songs_in_Top[j + 1] = songs_in_Top[j];
                        groups_in_Top[j + 1] = groups_in_Top[j];
                        popularity_songs_in_Top[j + 1] = popularity_songs_in_Top[j];
                        --j;
                      }

                    songs_in_Top[j + 1] = vremenoeNazvanyePesny;
                    groups_in_Top[j + 1] = vremenoeNazvanyeGruppy;
                    popularity_songs_in_Top[j + 1] = popularnostVremennoyPesny;
                  }

                std::cout << "Chart: " << std::endl;

                for(int i=0;i <real_cout_Songs;++i)
				  {
                    std::cout<< (i + 1) << ") "<< groups_in_Top[i]<< " - "<< songs_in_Top[i] << std::endl;
                  }

                break;
              }

            case 11: 
		      {
				const char* currentSongName = Songs[number_of_the_current_Song];
                const char* currentBandName = Groups[number_of_the_current_Song];
                int currentSongPopularity = popularity_Songs[number_of_the_current_Song];

                for (int i = 1; i < real_cout_Songs; ++i) 
				  { 
					const char* vremenoeNazvanyePesny = Songs[i];
                    const char* vremenoeNazvanyeGruppy = Groups[i];
                    int popularnostVremennoyPesny = popularity_Songs[i];
                    int j = i - 1;

                    while (j > -1 && popularity_Songs[j] < popularnostVremennoyPesny) 
					  {
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

                for (int i = 0; i < real_cout_Songs; ++i)
				  {
                    std::cout << Groups[i] << " - " << Songs[i] << std::endl;
                  }

                for (int i = 0; i < real_cout_Songs; ++i)
                  {
                    if (std::strcmp(currentBandName, Groups[i]) == 0 && std::strcmp(currentSongName, Songs[i]) == 0) 
					  {
                        number_of_the_current_Song = i;
                        break; 
					  }
                  }

                std::cout << "Now playing: " << Groups[number_of_the_current_Song] << " - " << Songs[number_of_the_current_Song] << std::endl;
                std::cout << "Song, you are listening on " << number_of_the_current_Song + 1 << " position of chart" << std::endl;
                break;
              }

            case 12: 
			  {
                for (int i = 0; i < real_cout_Songs; ++i)
                  {
                    songs_in_Top[i] = Songs[i];
                    groups_in_Top[i] = Groups[i];
                    popularity_songs_in_Top[i] = popularity_Songs[i]; 
				  }

                for (int i = 1; i < real_cout_Songs; ++i) 
			      { 
				    const char* temp1 = songs_in_Top[i]; 
					const char* temp2 = groups_in_Top[i];
					int temp3 = popularity_songs_in_Top[i];
					int j = i - 1;

					while (j > -1 && popularity_songs_in_Top[j] < temp3)
				      {
						songs_in_Top[j + 1] = songs_in_Top[j];
						groups_in_Top[j + 1] = groups_in_Top[j];
						popularity_songs_in_Top[j + 1] = popularity_songs_in_Top[j];
						--j;
					  }

					songs_in_Top[j + 1] = temp1;
                    groups_in_Top[j + 1] = temp2;
                    popularity_songs_in_Top[j + 1] = temp3;
                  }

                std::cout << "Most popular band is: " << groups_in_Top[0] << std::endl;
                break;
              }

            case 13: 
		      {
                isDone = false;
                break;
              }

			default: std::cout << "Unknown command." << std::endl;
		  }
      }

	std::cout << "Goodbye!" << std::endl;
}