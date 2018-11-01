/* utPod_driver.cpp

This is a the driver created by Andy and Iris

*/

#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

//remove when empty
    Song s1("Honne","I Got You",45);
    int result = t.removeSong(s1);
    cout << "Remove when Empty: result = " << result << endl;
    cout << endl;
//shuffle and show list when empty
    cout << "Shuffle when empty: nothing happens" << endl;
    cout << "-----" << endl;
    t.shuffle();
    t.showSongList();
    cout << "-----" << endl;
    cout << endl;
//sort when empty
    cout << "Sort when empty: nothing happens" << endl;
    cout << "-----" << endl;
    t.sortSongList();
    t.showSongList();
    cout << "-----" << endl;
    cout << endl;
//get remaining memory when empty
    int remain = t.getRemainingMemory();
    int total = t.getTotalMemory();
    cout << "Total Memory: " << total << endl << "Remaining Memory: " << remain << endl;
    cout << endl;
//add when empty
    cout << "Add when UtPod is empty" << endl;
    result = t.addSong(s1);
    cout << "Add when empty: result = " << result << endl;
    t.showSongList();
    cout << endl;
//****WHEN MEMORY IS NOT FULL****
//add rest of songs
    Song s2("Nujabes","Counting Stars",50);
    Song s22("Nujabes","Counting Stars",50);
    Song s3("Honne","Day 1", 100);
    Song s4("Nujabes","Counting Stars",55);
    Song s5("ABBA","Take On Me",200);
    result = t.addSong(s2);
    result = t.addSong(s3);
    result = t.addSong(s4);
    result = t.addSong(s5);
    t.showSongList();
    cout << endl;
//sort
    cout << "Sort the UtPod" << endl;
    t.sortSongList();
    t.showSongList();
    cout << endl;
//shuffle
    cout << "Shuffle the UtPod" << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;
//get remaining memory
    remain = t.getRemainingMemory();
    cout << "Remaining Memory should be: "<< t.getTotalMemory()-500 << endl;
    cout << "Remaing Memory: " << remain;
    cout << endl;
//add to make FULL
    Song s6("Bazzi","Take On Me",t.getRemainingMemory());
    result = t.addSong(s6);
    t.showSongList();
    cout << endl;
//sort
    cout << "Sort" << endl;
    t.sortSongList();
    t.showSongList();
    cout << endl;
//add when UtPod is full
    cout << "Adding when the memory is full"<< endl;
    Song s7("Bazzi","Beautiful",10);
    result = t.addSong(s7);
    cout << "Result = " << result << endl;
    cout << endl;
//remove a song that comes up twice
    cout << "Removing a song that occurs multiple times in UtPod" << endl;
    result = t.removeSong(s22);
    cout << endl;
//remove a song at the beginning
    cout << "Remove the song at the head of the linked list of Songs" << endl;
    result = t.removeSong(s5);
    cout << endl;
//remove a song at the end
    cout << "Remove the last songnode that points to null" << endl;
    result = t.removeSong(s4);
    cout << "Result = " << result << endl;
    cout << endl;
//remove all but two songs
    result = t.removeSong(s6);
    result = t.removeSong(s3);
//*********TWO SONGS LEFT***********
//when two songs are left:: shuffle
    cout << "Two Songs in UtPod::" << endl;
    t.showSongList();
    cout << "Shuffle" << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;
//*********ONE SONG  LEFT***********
//when one song is left
    result = t.removeSong(s1);
//


}