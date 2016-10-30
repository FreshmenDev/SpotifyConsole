#include <iostream>
#include <string>
#include <cstring>
#include "SongStruct.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void printInformation(int currentSongIndex, int amountOfSongs, Song Songs[]);
void printNewPlaylistOrder(int amountOfSongs, Song Songs[]);
void sortingSongsByName(int currentSongIndex, int amountOfSongs, Song Songs[], Song TopSongs[]);
void sortingSongsByPopylarity(int currentSongIndex, int amountOfSongs, Song Songs[], Song TopSongs[]);
void changeSongNumber(int currentSongIndex, int amountOfSongs, Song Songs[]);
int searchSongByBand(int amountOfSongs, Song Songs[], std::string bandName);
int searchSongByName(int amountOfSongs, Song Songs[], std::string songName);
void updateTopList(int amountOfSongs, Song Songs[], Song TopSongs[]);

#endif FUNCTIONS_H