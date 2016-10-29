#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Song  
{
  string name;
  string group;
  int popularity;
};

const int COUNT_SONGS = 20;

bool isDone = true;

Song songs [COUNT_SONGS];
Song popularity [COUNT_SONGS];
Song tempSong;                  //Временная структура для свапа

void newPlaylistOrder(string &tempNameSong, string &tempNameGroup,int &numberOfTheCurrentSong,int &realCoutSongs)
  {
    cout<<"New playlist order "<<endl;

    for (int i = 0; i < realCoutSongs; ++i) 
      {
        cout<<songs[i].group<< " - "<<songs[i].name<<endl;
      }

	for (int i = 0; i < realCoutSongs; ++i)
	  {
        if (tempNameGroup == songs[i].group   && tempNameSong == songs[i].name) 
		  {
            numberOfTheCurrentSong = i;
            break;
          }
	  }
  }

void coutNowPlaying(int &numberOfTheCurrentSong)
{
  cout<<endl<<"Now playing: "<<songs[numberOfTheCurrentSong].group<<" - "<<songs[numberOfTheCurrentSong].name<<endl;
}

void coutPreviousSong(int &numberOfTheCurrentSong)
 {
   if(numberOfTheCurrentSong > 0) 
     {
	   cout<<"Previous song: "<<songs[numberOfTheCurrentSong - 1].group<< " - " <<songs[numberOfTheCurrentSong - 1].name<<endl;
     }   
 }

void coutNextSong(int &numberOfTheCurrentSong, int &realCoutSongs)
 {   
   if(numberOfTheCurrentSong < realCoutSongs - 1) 
	 {
	   cout<<"Next song: "<<songs[numberOfTheCurrentSong + 1].group<<" - "<<songs[numberOfTheCurrentSong + 1].name<<endl;
     }
 }

void if_found(bool &found, string &soughtWord)
{
	if(found)
	  {
        cout<<"Now you can play any song by it position"<<endl;
      } 

	else
      {
        cout<<"There are no song with band name like this "<<soughtWord<<endl;
      }
}

int main () 
{	
	int numberOfTheCurrentSong = 0;
	int realCoutSongs = 14;

    songs[0].name = "Should I Stay or Should I Go";
    songs[0].group = "The Clash";
    songs[0].popularity = 0;

    songs[1].name = "Baby don't lie to me";
    songs[1].group = "The Fratellis";
    songs[1].popularity = 0;

    songs[2].name = "Ole Black 'n' Blue Eyes";
    songs[2].group = "The Fratellis";
    songs[2].popularity = 0;

    songs[3].name = "Like A Champion";
    songs[3].group = "The Baseballs";
    songs[3].popularity = 0;

    songs[4].name = "Jackie and Wilson";
    songs[4].group = "Hoizer";
    songs[4].popularity = 0;

    songs[5].name = "Mountains";
    songs[5].group = "Message To Bears";
    songs[5].popularity = 0;

    songs[6].name = "When It's Cold I'd Like to Die";
    songs[6].group = "Moby";
    songs[6].popularity = 0;

    songs[7].name = "Damn Your Eyes";
    songs[7].group = "Alex Clare";
    songs[7].popularity = 0;

    songs[8].name = "Heroes";
    songs[8].group = "David Bowie";
    songs[8].popularity = 0;

    songs[9].name = "No Diggity";
    songs[9].group = "Chet Faker";
    songs[9].popularity = 0;

    songs[10].name = "Inhaler";
    songs[10].group = "Foals";
    songs[10].popularity = 0;

    songs[11].name = "London Thunder";
    songs[11].group = "Foals";
    songs[11].popularity = 0;

    songs[12].name = "Spanish Sahara";
    songs[12].group = "Foals";
    songs[12].popularity = 0;

    songs[13].name = "Asleep";
    songs[13].group = "The Smiths";
    songs[13].popularity = 0;

    while (isDone) 
	  {
		int selection = -1;
	    bool found = false;

		coutNowPlaying(numberOfTheCurrentSong);
	    coutPreviousSong(numberOfTheCurrentSong);
		coutNextSong(numberOfTheCurrentSong,realCoutSongs);

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
                if(numberOfTheCurrentSong != realCoutSongs - 1) 
			      {
                    ++numberOfTheCurrentSong;
                    ++songs[numberOfTheCurrentSong].popularity; 
			      }
                break;
              }

            case 2: 
		      {
                if(numberOfTheCurrentSong > 0)
                  {
                    --numberOfTheCurrentSong;
                    ++songs[numberOfTheCurrentSong].popularity;
                  }
                break;
              }

            case 3: 
		      {
                string tempNameSong = songs[numberOfTheCurrentSong].name;
                string tempNameGroup = songs[numberOfTheCurrentSong].group;               

			    for(int i = 1; i < realCoutSongs; ++i)
			      {
                    tempSong = songs[i];                   
			        int j = i-1;

                    while (j> -1 && tempSong.name != songs[j].group ) 
			          {
                        songs[j + 1] = songs[j];
                        --j;
                      }
                    songs[j+1] = tempSong;                    
                  }

                newPlaylistOrder(tempNameSong,tempNameGroup,numberOfTheCurrentSong,realCoutSongs);
               
                cout<<"Current song position: "<<numberOfTheCurrentSong + 1<<endl;

			    coutNowPlaying(numberOfTheCurrentSong);
	            coutPreviousSong(numberOfTheCurrentSong);
		        coutNextSong(numberOfTheCurrentSong,realCoutSongs);

                break;
              }

            case 4: 
	          {
                string tempNameSong = songs[numberOfTheCurrentSong].name;
                string tempNameGroup = songs[numberOfTheCurrentSong].group;               

                for (int i = 1; i<realCoutSongs; ++i) 
				  {
                    tempSong = songs[i];                    
                    int j = i-1;

                    while (j >-1 && tempSong.name != songs[j].name)
					  {
                        songs[j + 1] = songs[j];                       
                        --j;
					  }

                    songs[j + 1] = tempSong;                    
                  }

                newPlaylistOrder(tempNameSong,tempNameGroup,numberOfTheCurrentSong,realCoutSongs);
               
                cout<<"Current song position: "<<numberOfTheCurrentSong<<endl;

                coutNowPlaying(numberOfTheCurrentSong);
	            coutPreviousSong(numberOfTheCurrentSong);
		        coutNextSong(numberOfTheCurrentSong,realCoutSongs);

                break;
              }

            case 5: 
		      {  
				string soughtWord;
                cout<<"Input band name you are looking for: "<<endl;
                getline(cin, soughtWord);
                
                for (int i=0; i<realCoutSongs; ++i) 
				  {
                    if (soughtWord.c_str() == songs[i].group)  
					  {
                        cout<<i + 1<<") "<<songs[i].group<<" - "<<songs[i].name<<endl;
                        found = true;
                      }
                  }

                if_found(found,soughtWord);

                break;
              }

            case 6: 
		      {  
				string soughtWord;
                cout<<"Input song name you are looking for: "<<endl;
                getline(cin, soughtWord);
               
                for (int i = 0; i < realCoutSongs; ++i) 
				  {
                    if (soughtWord.c_str() == songs[i].name) 
					  {
                        cout<<i + 1<<") "<<songs[i].group<<" - "<<songs[i].name<<endl;
                        found = true;
                      }
                  }

                if_found(found,soughtWord);

                break;
              }

            case 7: 
			  {
                cout<<"Playlist: "<<endl;

                for (int i = 0; i < realCoutSongs; ++i) 
				  {
                    cout<<songs[i].group<<" - "<<songs[i].name<<endl;
                  }
                break;
              }

            case 8: 
			  {
                cout<<"Ok, here is the playlist: "<<endl;

                for (int i = 0; i < realCoutSongs; ++i)
				  {
                    cout<<i + 1<<") "<<songs[i].group<<" - "<<songs[i].name<<endl;
                  }

                cout<<"Enter song position, you want to play: "<<endl;

                int songNomer;

                cin>>songNomer;
                cin.ignore();
                --songNomer;

                if (songNomer > -1 && songNomer<realCoutSongs) 
				  {
                    numberOfTheCurrentSong = songNomer;
                    ++songs[numberOfTheCurrentSong].popularity;
                  }

                coutNowPlaying(numberOfTheCurrentSong);
	            coutPreviousSong(numberOfTheCurrentSong);
		        coutNextSong(numberOfTheCurrentSong,realCoutSongs);

                break;
              }

            case 9: 
			  {
                coutNowPlaying(numberOfTheCurrentSong);
				break;
              }

            case 10: 
			  {
                for (int i =0; i < realCoutSongs;++i) 
				  {
                    popularity[i] = songs[i];                    
                  }

                for (int i = 1;i< realCoutSongs;++i) 
				  {
				    tempSong = popularity[i];                    
                    int j = i - 1;

                    while (j > -1 && popularity[j].popularity < tempSong.popularity)
					  {
                        popularity[j + 1] = popularity[j];                       
                        --j;
                      }

                    popularity[j + 1] = tempSong;                    
                  }

                cout<<"Chart: "<<endl;

                for(int i=0;i <realCoutSongs;++i)
				  {
                    cout<<(i + 1)<<") "<<popularity[i].group<<" - "<<popularity[i].name<<endl;
                  }

                break;
              }

            case 11: 
		      {
				string tempNameSong = songs[numberOfTheCurrentSong].name;
                string tempNameGroup = songs[numberOfTheCurrentSong].group;               

                for (int i = 1; i < realCoutSongs; ++i) 
				  { 
					tempSong = songs[i];                    
                    int j = i - 1;

                    while (j > -1 && songs[j].popularity < tempSong.popularity) 
					  {
                        songs[j + 1] = songs[j];                        
                        --j;
                      }

                    songs[j + 1] = tempSong;                    
                  }

                newPlaylistOrder(tempNameSong,tempNameGroup,numberOfTheCurrentSong,realCoutSongs);
                coutNowPlaying(numberOfTheCurrentSong);

                cout<<"Song, you are listening on "<<numberOfTheCurrentSong + 1<<" position of chart"<<endl;
                break;
              }

            case 12: 
			  {
                for (int i = 0; i < realCoutSongs; ++i)
                  {
                    popularity[i] = songs[i];                     
				  }

                for (int i = 1; i < realCoutSongs; ++i) 
			      { 
				    tempSong = popularity[i]; 					
					int j = i - 1;

					while (j > -1 && popularity[j].popularity < tempSong.popularity)
				      {
						popularity[j + 1] = popularity[j];						
						--j;
					  }

					popularity[j + 1] = tempSong;                    
                  }

                cout<<"Most popular band is: "<<popularity[0].group<<endl;
                break;
              }

            case 13: 
		      {
                isDone = false;
                break;
              }

			default: cout<<"Unknown command."<<endl;
		  }
      }

	cout<<"Goodbye!"<<endl;
	system("pause");
}