#include <iostream>
#include <string>

const int number_of_songs_of_all = 20;
int popularity_of_songs_in_top[number_of_songs_of_all];
int popularity_of_songs[number_of_songs_of_all];
int real_number_of_songs = 0;
int numberOfTheCurrentSong = 0;
int choice = -1;
std::string massiv_song[number_of_songs_of_all];
std::string massivBand[number_of_songs_of_all];
std::string  songs_in_top[number_of_songs_of_all];
std::string band_in_top[number_of_songs_of_all];

std::string massiv_song[number_of_songs_of_all] =
  {
    "Should I Stay or Should I Go",
    "Baby don't lie to me",
    "Ole Black 'n' Blue Eyes",
    "Like A Champion",
    "Jackie and Wilson",
    "Mountains",
    "When It's Cold I'd Like to Die",
    "Damn Your Eyes",
    "Heroes",
    "No Diggity",
    "Inhaler",
    "London Thunder",
    "Spanish Sahara",
    "Asleep"
  };

 int popularity_of_songs[number_of_songs_of_all] =
  {
    0,0,0,0,0,0,0,0,0,0,0,0,0
  };
  std::string massivBand[number_of_songs_of_all] =
  {
    "The Clash",
    "The Fratellis",
    "The Fratellis",
    "The Baseballs",
    "Hoizer",
    "Message To Bears",
    "Moby",
    "Alex Clare",
    "David Bowie",
    "Chet Faker",
    "Foals",
    "Foals",
    "Foals",
    "The Smiths",
  };

  int continue_work(int numberOfTheCurrentSong)
{
    std::cout � std::endl � "Now playing: " � massivBand[numberOfTheCurrentSong]
      � " - " � massiv_song[numberOfTheCurrentSong] � std::endl;

    if (numberOfTheCurrentSong > 0)
    {
      std::cout � "Previous song: " � massivBand[numberOfTheCurrentSong - 1]
        � " - " � massiv_song[numberOfTheCurrentSong - 1] � std::endl;
    }

    if (numberOfTheCurrentSong < massiv_song - 1)
    {
      std::cout � "Next song: " � massivBand[numberOfTheCurrentSong + 1] � " - " � massiv_song[numberOfTheCurrentSong + 1] � std::endl;
    }
  return  0;
};


int main () {
	real_number_of_songs = 14;

   bool continue_work = true;
   while (continue_work)
  {
    Func_continue_work(numberOfTheCurrentSong);

    std::cout � "Enter action you want to make: " � std::endl;

    std::cout � "1) Play next" � std::endl;

    std::cout � "2) Play prev" � std::endl;

    std::cout � "3) Group by band" � std::endl;

    std::cout � "4) Group by song name" � std::endl;

    std::cout � "5) Search song by band " � std::endl;

    std::cout � "6) Search song by name " � std::endl;

    std::cout � "7) Show playlist " � std::endl;

    std::cout � "8) Play specific song (specified by position) " � std::endl;

    std::cout � "9) What is playing now? " � std::endl;

    std::cout � "10) Show my chart " � std::endl;

    std::cout � "11) Sort by popularity " � std::endl;

    std::cout � "12) Show the most popular band " � std::endl;

    std::cout � "13) Exit " � std::endl;

    std::cin � choice;

    std::cin.ignore();
  }

        switch (choice) {
            case 1: {
                if (numberOfTheCurrentSong != real_number_of_songs - 1) {
                    ++numberOfTheCurrentSong;
                    ++popularity_of_songs[numberOfTheCurrentSong]; }
                break;
            }

            case 2: {
                if (numberOfTheCurrentSong > 0)
                {
                    --numberOfTheCurrentSong;
                    ++popularity_of_songs[numberOfTheCurrentSong];
                }
                break;
            }

            case 3: {
                const char* TMP = massiv_song[numberOfTheCurrentSong];
                const char* TMP2 = massivBand[numberOfTheCurrentSong];
                int currentPopularity = popularity_of_songs[numberOfTheCurrentSong];


                for (int i = 1; i < real_number_of_songs; ++i)
                {
                    const char* tmp =massiv_song[i];
                    const char* temp= massivBand[i];
                    int variable = popularity_of_songs[i];

                    int j = i-1;
                    while (j> -1 && std::strcmp(temp, massivBand[j]) != 0) {
                        massiv_song[j + 1] = massiv_song[j];
                        massivBand[j +1] = massivBand[j];
                        popularity_of_songs[j+1] = popularity_of_songs[j];
                        --j;
                    }

                    massiv_song[j+1] = tmp;
                    massivBand[j+1] = temp;
                    popularity_of_songs[j + 1] = variable;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < real_number_of_songs; ++i) {
                    std::cout << massivBand[i] << " - " << massiv_song[i] << std::endl;
                }

                for (int i = 0; i < real_number_of_songs; ++i) {
                    if (std::strcmp(TMP2, massivBand[i]) == 0
                        && std::strcmp(TMP, massiv_song[i]) == 0) {
                        numberOfTheCurrentSong = i;
                        break;
                    }
                }

                std::cout << "Current song position: " << numberOfTheCurrentSong + 1 << std::endl;

                std::cout << "Now playing: " <<
                          massivBand[numberOfTheCurrentSong] << " - " << massiv_song[numberOfTheCurrentSong] << std::endl;

                if (numberOfTheCurrentSong > 0) {
                    std::cout << "Previous song: " <<
                              massivBand[numberOfTheCurrentSong - 1] << " - " << massiv_song[numberOfTheCurrentSong - 1] << std::endl;
                }

                if (numberOfTheCurrentSong < real_number_of_songs - 1) {
                    std::cout << "Next song: " <<
                              massivBand[numberOfTheCurrentSong + 1] << " - " << massiv_song[numberOfTheCurrentSong + 1] << std::endl;
                }
                break;
            }

            case 4: {
                const char* nameOfTheCurrentSong = massiv_song[numberOfTheCurrentSong];
                const char* nameOfTheCurrentBand = massivBand[numberOfTheCurrentSong];
                int popularity_of_current_band = popularity_of_songs[numberOfTheCurrentSong];

                for (int i = 1; i<real_number_of_songs; ++i) {
                    const char* TemporaryNameOfASong = massiv_song[i];
                    const char* TemporaryNameOfABand = massivBand[i];
                    int popularityOfATemporarySong = popularity_of_songs[i];

                    int j = i-1;
                    while (j >-1 && std::strcmp(nameOfTheCurrentSong,massiv_song[j])!=0){
                        massiv_song[j + 1] = massiv_song[j];
                        massivBand[j + 1] = massivBand[j];
                        popularity_of_songs[j + 1] = popularity_of_songs[j];
                        --j;}


                    massiv_song[j + 1] = nameOfTheCurrentSong;
                    massivBand[j + 1] = nameOfTheCurrentBand;
                    popularity_of_songs[j + 1] = popularityOfATemporarySong;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i<real_number_of_songs; ++i)
                {
                    std::cout << massivBand[i] <<" - " << massiv_song[i] << std::endl;
                }

                for (int i = 0; i < real_number_of_songs; ++i){
                    if (std::strcmp(nazvanieTekusheyGruppy, massivBand[i]) == 0
                        && std::strcmp(nazvanieTekusheyPesny, massiv_song[i]) == 0) {
                        numberOfTheCurrentSong = i;
                        break;
                    }}

                std::cout<<"Current song position: "<<numberOfTheCurrentSong<< std::endl;

                std::cout<<"Now playing: " <<
                          massivBand[numberOfTheCurrentSong]<<" - "<< massiv_song[numberOfTheCurrentSong] << std::endl;

                if (numberOfTheCurrentSong > 0) {
                    std::cout << "Previous song: " <<
                              massivBand[numberOfTheCurrentSong - 1] << " - " << massiv_song[numberOfTheCurrentSong - 1] << std::endl;
                }

                if (numberOfTheCurrentSong < real_number_of_songs - 1) {
                    std::cout << "Next song: " <<
                              massivBand[numberOfTheCurrentSong + 1] << " - " << massiv_song[numberOfTheCurrentSong + 1] << std::endl;
                }
                break;
            }

            case 5: {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool find=false;
                for (int i=0; i<real_number_of_songs; ++i) {
                    if (std::strcmp(str.c_str(), massivBand[i]) == 0) {
                        std::cout << i + 1 << ") " << massivBand[i] << " - " << massiv_song[i] << std::endl;
                        find = true;
                    }
                }

                if(find){
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
                bool find = false;
                for (int i = 0; i < real_number_of_songs; ++i) {
                    if (std::strcmp(str2.c_str(), massiv_song[i]) == 0) {
                        std::cout << i + 1 << ") " << massivBand[i] << " - " << massiv_song[i] << std::endl;
                        find = true;
                    }
                }

                if (find)
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
                for (int i = 0; i < real_number_of_songs; ++i) {
                    std::cout << massivBand[i] << " - " << massiv_song[i] << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "Ok, here is the playlist: " << std::endl;

                for (int i = 0; i < real_number_of_songs; ++i){
                    std::cout << i + 1 << ") " << massivBand[i] << " - " << massiv_song[i] << std::endl;
                }

                std::cout <<"Enter song position, you want to play: " << std::endl;

                int songNumer;

                std::cin >> songNumer;

                std::cin.ignore();

                --songNumer;

                if (songNumer > -1 && songNumer<real_number_of_songs) {
                    numberOfTheCurrentSong = songNumer;
                    ++popularity_of_songs[numberOfTheCurrentSong];
                }

                std::cout << "Now playing: " <<
                          massivBand[numberOfTheCurrentSong] << " - " << massiv_song[numberOfTheCurrentSong] << std::endl;

                if (numberOfTheCurrentSong > 0) {
                    std::cout << "Previous song: " <<
                              massivBand[numberOfTheCurrentSong - 1] << " - " << massiv_song[numberOfTheCurrentSong - 1] << std::endl;
                }

                if (numberOfTheCurrentSong<real_number_of_songs-1) {
                    std::cout << "Next song: " <<
                              massivBand[numberOfTheCurrentSong + 1]<< " - "<< massiv_song[numberOfTheCurrentSong + 1] << std::endl;
                }

                break;
            }

            case 9: {
                std::cout<< "Now playing: "<<
                          massivBand[numberOfTheCurrentSong] <<" - " <<massiv_song[numberOfTheCurrentSong] << std::endl;
                break;
            }

            case 10: {
                for (int i =0; i < real_number_of_songs;++i) {
                    songs_in_top[i]= massiv_song[i];
                    band_in_top[i] =massivBand[i];
                    popularity_of_songs_in_top[i]=popularity_of_songs[i];
                }

                for (int i = 1;i< real_number_of_songs;++i) {
const char* nameOfTheCurrentSong = songs_in_top[i];
                    const char* nameOfTheCurrentBand = band_in_top[i];int popularityOfATemporarySong = popularity_of_songs_in_top[i];

                    int j = i - 1;
                    while (j > -1 && popularity_of_songs_in_top[j] < popularityOfATemporarySong) {
                        songs_in_top[j + 1] = songs_in_top[j];
                  gruppy_in_top[j + 1] = gruppy_in_top[j];
                        popularity_of_songs_in_top[j + 1] = popularity_of_songs_in_top[j];
                        --j;
                    }

                    songs_in_top[j + 1] = nameOfTheCurrentSong;
                    gruppy_in_top[j + 1] = nameOfTheCurrentBand;
                    popularity_of_songs_in_top[j + 1] = popularityOfATemporarySong;
                }

                std::cout << "Chart: " << std::endl;

                for(int i=0;i <real_number_of_songs;++i){
                    std::cout<< (i + 1) << ") "<< band_in_top[i]<< " - "<<songs_in_top[i] << std::endl;
                }

                break;
            }

            case 11: {const char* currentSongName = massiv_song[numberOfTheCurrentSong];
                const char* currentBandName = massivBand[numberOfTheCurrentSong];
                int currentSongPopularity = popularity_of_songs[numberOfTheCurrentSong];

                for (int i = 1; i < real_number_of_songs; ++i) { const char* nameOfTheCurrentSong = massiv_song[i];
                    const char* nameOfTheCurrentBand = massivBand[i];
                    int popularityOfATemporarySong = popularity_of_songs[i];

                    int j = i - 1;
                    while (j > -1 && popularity_of_songs[j] < popularityOfATemporarySong) {
                      massiv_song[j + 1] = massiv_song[j];
                      massivBand[j + 1] = massivBand[j];
                      popularity_of_songs[j + 1] = popularity_of_songs[j];
                      --j;
                    }


                    massiv_song[j + 1] = nameOfTheCurrentSong;
                    massivBand[j + 1] = nameOfTheCurrentBand;
                    popularity_of_songs[j + 1] = popularityOfATemporarySong;
                }

                std::cout << "New playlist order " << std::endl;

                for (int i = 0; i < real_number_of_songs; ++i) {
                    std::cout << massivBand[i] << " - " << massiv_song[i] << std::endl;
                }

                for (int i = 0; i < real_number_of_songs; ++i)
                {
                    if (std::strcmp(currentBandName, massivBand[i]) == 0
                        && std::strcmp(currentSongName, massiv_song[i]) == 0) {
                        numberOfTheCurrentSong = i;
                        break; }
                }

                std::cout << "Now playing: " << massivBand[numberOfTheCurrentSong] << " - " << massiv_song[numberOfTheCurrentSong] << std::endl;

                std::cout << "Song, you are listening on " << numberOfTheCurrentSong + 1 << " position of chart" << std::endl;
                break;
            }


            case 12: {
                for (int i = 0; i < real_number_of_songs; ++i)
                {
                    songs_in_top[i] = massiv_song[i];
                        band_in_top[i] = massivBand[i];
                    popularity_of_songs_in_top[i] = popularity_of_songs[i]; }

                for (int i = 1; i < real_number_of_songs; ++i) { const char* temp1 = songs_in_top[i]; const char* temp2 = band_in_top[i];
                    int temp3 = popularity_of_songs_in_top[i];

                    int j = i - 1;
                    while (j > -1 && popularity_of_songs_in_top[j] < temp3)
                    {
                        songs_in_top[j + 1] = songs_in_top[j];
                        band_in_top[j + 1] = band_in_top[j];
                        popularity_of_songs_in_top[j + 1] = popularity_of_songs_in_top[j];



                        --j;
                    }

                    songs_in_top[j + 1] = temp1;
                        band_in_top[j + 1] = temp2;
                    popularity_of_songs_in_top[j + 1] = temp3;
                }

                    std::cout << "Most popular band is: " << band_in_top[0] << std::endl;
                break;
            }

            case 13: {
                continueWork = false;
                break;
            }

            default:
                std::cout << "Unknown command." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
}