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

string temp_name_song;
string temp_name_group;
string sought_word;

int real_cout_Songs = 14;
int number_of_the_current_Song = 0;

bool isDone = true;
bool found;

Song songs [COUNT_SONGS];
Song popularity [COUNT_SONGS];
Song tempSong;                  //Временная структура для свапа

void new_playlist_order()
  {
    cout<<"New playlist order "<<endl;

    for (int i = 0; i < real_cout_Songs; ++i) 
      {
        cout<<songs[i].group<< " - "<<songs[i].name<<endl;
      }

	for (int i = 0; i < real_cout_Songs; ++i)
	  {
        if (temp_name_group == songs[i].group   && temp_name_song == songs[i].name) 
		  {
            number_of_the_current_Song = i;
            break;
          }
	  }
  }

void cout_now_playing()
{
  cout<<endl<<"Now playing: "<<songs[number_of_the_current_Song].group<<" - "<<songs[number_of_the_current_Song].name<<endl;
}

void cout_previous_song()
 {
   if(number_of_the_current_Song > 0) 
     {
	   cout<<"Previous song: "<<songs[number_of_the_current_Song - 1].group<< " - " <<songs[number_of_the_current_Song - 1].name<<endl;
     }   
 }

void cout_next_song()
 {   
   if(number_of_the_current_Song < real_cout_Songs - 1) 
	 {
	   cout<<"Next song: "<<songs[number_of_the_current_Song + 1].group<<" - "<<songs[number_of_the_current_Song + 1].name<<endl;
     }
 }

void if_found()
{
	if(found)
	  {
        cout<<"Now you can play any song by it position"<<endl;
      } 

	else
      {
        cout<<"There are no song with band name like this "<<sought_word<<endl;
      }
}

int main () 
{	              
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
	    found = false;

		cout_now_playing();
	    cout_previous_song();
		cout_next_song();

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
                    ++songs[number_of_the_current_Song].popularity; 
			      }
                break;
              }

            case 2: 
		      {
                if(number_of_the_current_Song > 0)
                  {
                    --number_of_the_current_Song;
                    ++songs[number_of_the_current_Song].popularity;
                  }
                break;
              }

            case 3: 
		      {
                temp_name_song = songs[number_of_the_current_Song].name;
                temp_name_group = songs[number_of_the_current_Song].group;               

			    for(int i = 1; i < real_cout_Songs; ++i)
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

                new_playlist_order();
               
                cout<<"Current song position: "<<number_of_the_current_Song + 1<<endl;

			    cout_now_playing();
	            cout_previous_song();
		        cout_next_song();

                break;
              }

            case 4: 
	          {
                temp_name_song = songs[number_of_the_current_Song].name;
                temp_name_group = songs[number_of_the_current_Song].group;               

                for (int i = 1; i<real_cout_Songs; ++i) 
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

                new_playlist_order();
               
                cout<<"Current song position: "<<number_of_the_current_Song<<endl;

                cout_now_playing();
	            cout_previous_song();
		        cout_next_song();

                break;
              }

            case 5: 
		      {             
                cout<<"Input band name you are looking for: "<<endl;
                getline(cin, sought_word);
                
                for (int i=0; i<real_cout_Songs; ++i) 
				  {
                    if (sought_word.c_str() == songs[i].group)  
					  {
                        cout<<i + 1<<") "<<songs[i].group<<" - "<<songs[i].name<<endl;
                        found = true;
                      }
                  }

                if_found();

                break;
              }

            case 6: 
		      {                
                cout<<"Input song name you are looking for: "<<endl;
                getline(cin, sought_word);
               
                for (int i = 0; i < real_cout_Songs; ++i) 
				  {
                    if (sought_word.c_str() == songs[i].name) 
					  {
                        cout<<i + 1<<") "<<songs[i].group<<" - "<<songs[i].name<<endl;
                        found = true;
                      }
                  }

                if_found();

                break;
              }

            case 7: 
			  {
                cout<<"Playlist: "<<endl;

                for (int i = 0; i < real_cout_Songs; ++i) 
				  {
                    cout<<songs[i].group<<" - "<<songs[i].name<<endl;
                  }
                break;
              }

            case 8: 
			  {
                cout<<"Ok, here is the playlist: "<<endl;

                for (int i = 0; i < real_cout_Songs; ++i)
				  {
                    cout<<i + 1<<") "<<songs[i].group<<" - "<<songs[i].name<<endl;
                  }

                cout<<"Enter song position, you want to play: "<<endl;

                int songNomer;

                cin>>songNomer;
                cin.ignore();
                --songNomer;

                if (songNomer > -1 && songNomer<real_cout_Songs) 
				  {
                    number_of_the_current_Song = songNomer;
                    ++songs[number_of_the_current_Song].popularity;
                  }

                cout_now_playing();
	            cout_previous_song();
		        cout_next_song();

                break;
              }

            case 9: 
			  {
                cout_now_playing();
				break;
              }

            case 10: 
			  {
                for (int i =0; i < real_cout_Songs;++i) 
				  {
                    popularity[i] = songs[i];                    
                  }

                for (int i = 1;i< real_cout_Songs;++i) 
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

                for(int i=0;i <real_cout_Songs;++i)
				  {
                    cout<<(i + 1)<<") "<<popularity[i].group<<" - "<<popularity[i].name<<endl;
                  }

                break;
              }

            case 11: 
		      {
				temp_name_song = songs[number_of_the_current_Song].name;
                temp_name_group = songs[number_of_the_current_Song].group;               

                for (int i = 1; i < real_cout_Songs; ++i) 
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

                new_playlist_order();
                cout_now_playing();

                cout<<"Song, you are listening on "<<number_of_the_current_Song + 1<<" position of chart"<<endl;
                break;
              }

            case 12: 
			  {
                for (int i = 0; i < real_cout_Songs; ++i)
                  {
                    popularity[i] = songs[i];                     
				  }

                for (int i = 1; i < real_cout_Songs; ++i) 
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