//DOCUMENT HERE

#ifndef UTPOD_H
#define UTPOD_H
#include "song.h"

//UtPod class declaration
class UtPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;
      
      struct SongNode
      {
         Song s;
         SongNode *next;
      };
      
      SongNode *songs;  //the head pointer
      
      int memSize;
   
   public:
      //Default constructor
      //set the memory size to MAX_MEMORY
      UtPod() {
        songs = NULL;
        this->memSize = MAX_MEMORY;
      }

      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
      UtPod(int size) {
        songs = NULL;
        if (size > MAX_MEMORY || size < 0) {
          this->memSize = MAX_MEMORY;
        } else {
          this->memSize = size;
        }
      }

      /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms - the address of a const Song object

       output parms - 0 if song was added and -1 if song could not be added due to memory overflow
      */

      int addSong(Song const &s) {
        if(s.getSize() > memSize) {
          return NO_MEMORY;
        }
        SongNode newSong;
        newSong.s = s;
        if(songs == NULL){
          songs = &newSong;
        }
        else{
          newSong.next = songs;
          songs = &newSong;
        }
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

      int removeSong(Song const &s) {
        
      }

      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      void shuffle() {

      }

      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms -

         output parms -
      */

      void showSongList() {

      }


      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      void sortSongList();


      /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms -

         output parms -
      */
      void clearMemory() {

      }

      /* FUNCTION - int getTotalMemory
       *  returns the total amount of memory in the UtPod
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      int getTotalMemory() {
         return memSize;
      }

      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms -

         output parms -
      */

      int getRemainingMemory();


      ~UtPod();
 
};



#endif