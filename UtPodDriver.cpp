/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

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
    Song s1("Lily","Day 1",45);
    int result = t.removeSong(s1);
    cout << "Remove when Empty: result = " << result << endl;
//shuffle and show list when empty
    cout << "Shuffle when empty: nothing happens" << endl;
    cout << "-----" << endl;
    t.shuffle();
    t.showSongList();
    cout << "-----" << endl;
//sort when empty
    cout << "Sort when empty: nothing happens" << endl;
    cout << "-----" << endl;
    t.sortSongList();
    t.showSongList();
    cout << "-----" << endl;
//get remaining memory when empty
    int remain = t.getRemainingMemory();
    int total = t.getTotalMemory();
    cout << "Total Memory: " << total << endl << "Remaining Memory: " << remain << endl;
//add when empty
    cout << "Add when UtPod is empty" << endl;
    result = t.addSong(s1);
    cout << "Add when empty: result = " << result << endl;
    t.showSongList();
//****WHEN MEMORY IS NOT FULL****
//add rest of songs
    Song s2("Nujabes","Counting Stars",100);
    Song s3("Honne","Day 1", 100);
    Song s4("Nujabes","Counting Stars",55);
    Song s5("ABBA","Take On Me",200);
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s4);
    t.addSong(s5);
    t.showSongList();
//sort
    cout << "Sort the UtPod" << endl;
    t.sortSongList();
    t.showSongList();

//shuffle
    cout << "Shuffle the UtPod" << endl;
    t.shuffle();
    t.showSongList();
//get remaining memory
    remain = t.getRemainingMemory();
    cout << "Remaining Memory should be: "<< t.getTotalMemory()-500 << endl;
    cout << "Remaing Memory: " << remain;
//
}