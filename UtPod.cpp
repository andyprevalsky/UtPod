#include "UtPod.h"
#include "song.h"
#include <stdlib.h>
#include <time.h>

UtPod::UtPod() {
    songs = NULL;
    this->memSize = MAX_MEMORY;
}

      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
UtPod::UtPod(int size) {
    songs = NULL;
    if (size > MAX_MEMORY || size < 0) {
      this->memSize = MAX_MEMORY;
    } else {
      this->memSize = size;
    }
}

int UtPod::getLength() {
    SongNode *temp;
    temp = songs;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}


       /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms - the address of a const Song object

       output parms - 0 if song was added and -1 if song could not be added due to memory overflow
       */

int UtPod::addSong(Song const &s) {
    if(s.getSize() > getRemainingMemory()) {
      return NO_MEMORY;
    }
    SongNode* newSong = new SongNode;
    newSong->s = s;
    if(songs == NULL){
      songs = newSong;
    } else {
        newSong->next = songs;
        songs = newSong;
    }
    memSize = memSize + newSong->s.getSize();
    return SUCCESS;
}

      /* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -1 if nothing is removed


         input parms -

         output parms -
      */

int UtPod::removeSong (Song const &s) {
    if(getLength()==0){
        return NOT_FOUND;
    }
    SongNode* temp = songs;
    SongNode* temptemp;

    if(temp->s == s){
        songs = temp->next;
        delete temp;
        return SUCCESS;
    }

    while(temp->next != NULL){
        if(temp->next->s == s) {
            temptemp = temp->next;
            temp->next = temp->next->next;
            delete temptemp;
            return SUCCESS;
        }
        temp = temp->next;

    }
    return NOT_FOUND;
}

      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

void UtPod::shuffle() {
    if(getLength() < 2){
        return;
    }

    srand (time(NULL));
    int count = getLength();

    SongNode* song1;
    SongNode* song2;

    for(int i = 0;i<10000;i++){

        song1 = song2 = songs;
        int rand1 = rand() % count;
        int rand2 = rand() % count;
        for(int j = 0; j < rand1; j++){
            song1 = song1->next;
        }
        for(int j = 0; j < rand2; j++){
            song2 = song2->next;
        }
        Song tmp = song1->s;
        song1->s = song2->s;
        song2->s = tmp;

    }    
}

      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms -

         output parms -
      */

void UtPod::showSongList() {
    SongNode* temp = songs;
    while(temp!= NULL){
        cout << temp->s.getTitle() << ", " << temp->s.getArtist() << ", " << temp->s.getSize() << " MB" << endl;
        temp = temp->next;
    }
}


      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

void UtPod::sortSongList() {
    int length = getLength();
    if(length < 2){
        return;
    }
    SongNode* song1;
    for(int i = 0;i < length;i++){
        song1 = songs;
        for(int j = 0;j < length-1;j++){
            if(song1->s < song1->next->s){
                Song tmp = song1->s;
                song1->s = song1->next->s;
                song1->next->s = tmp;
            }
        }
    }
}


      /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms -

         output parms -
      */

     //possibly wrong
void UtPod::clearMemory() { 
    SongNode* temp = songs;
    SongNode* prev;
    while(temp != NULL){
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    songs = NULL;
    memSize = 0;
    return;
}

      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms -

         output parms -
      */
     

int UtPod::getRemainingMemory() {
    return MAX_MEMORY-memSize;
}

UtPod::~UtPod() {
    clearMemory();
}