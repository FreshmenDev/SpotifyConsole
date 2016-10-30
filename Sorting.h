#include "SongManagementStruct.h"

#ifndef SORTING_H
#define SORTING_H

void charMoveUpByOne(int &j, const char *temporaryName, const char **targetName[], SongManagement table[]);
void intMoveUpByOne(int &j, int temporarySongPopularity, int *targetName[], SongManagement table[]);
void sortSongs(const int NUMBER_OF_SONGS, SongManagement table[], int action);
int currentSongPosition(const int NUMBER_OF_SONGS, SongManagement table[], const char *currentSongName, const char *currentGroupName);

#endif