#include <iostream>
#ifndef SONG_H
#define SONG_H
using namespace std;

class Song {
    private:
        string artist;
        string title;
        int size;
    public:
        //declarations for functions

        //declarations for constructers
        Song();

        Song(string artist, string title, int size);

        //overload operators for sort functions
        bool operator < (Song const &s);

        bool operator > (Song const &s);

        bool operator == (Song const &s);

        //getters and setters
        void setArtist(string artist) {
            this->artist = artist;
        }

        void setTitle(string title) {
            this->title = title;
        }

        void setSize(int size) {
            this->size = size;
        }

        string getArtist() const {
            return artist;
        }

        string getTitle() const {
            return title;
        }

        int getSize() const {
            return size;
        }

        //deconstructor
        ~Song();
};

#endif