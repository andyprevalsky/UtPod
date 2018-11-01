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

      //* FUNCTION - int getLength
      // counts the number of songs currently in the UtPod
      // input : nothing
      // output : the number of songs in the UtPod
      int getLength();
   
   public:
      //Default constructor
      //set the memory size to MAX_MEMORY
      UtPod();

      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
      UtPod(int size);

      /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms - the address of a const Song object

       output parms - 0 if song was added and -1 if song could not be added due to memory overflow
      */

      int addSong(Song const &s);

      /* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -2 if nothing is removed


         input parms - the address of a const Song object

         output parms - 0 if removal of song was successful and -2 if nothing was added
      */

      int removeSong(Song const &s);

      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms - nothing

         output parms - the list of songs is randomly shuffled and the order is changed
      */

      void shuffle();

      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms - nothing

         output parms - the console has the songnodes all printed out in order
      */

      void showSongList();

      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms - nothing

         output parms - the song list is sorted in order from artist, title, then size
      */

      void sortSongList();


      /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms - nothing

         output parms - all the song nodes are deleted and the playlist is empty
      */
      void clearMemory();

      /* FUNCTION - int getTotalMemory
       *  returns the total amount of memory in the UtPod
          o will do nothing if there are less than two songs in the current list

         input parms - nothing

         output parms - returns the memory size that the UtPod has as its max memory
      */

      int getTotalMemory() {
        return memSize;
      }

      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms - nothing

         output parms - returns the amount of space (memory) available
      */

      int getRemainingMemory();

      ~UtPod();
 
};



#endif