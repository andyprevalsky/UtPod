#include <iostream>
using namespace std;

class Song {
    private:
        string artist;
        string title;
        int size;
    public:

    Song(string artist, string title, int size) {
        this->artist = artist;
        this->title = title;
        this->size = size;
    }

    void setArtist(string artist) {
        this->artist = artist;
    }

    void setTitle(string title) {
        this->title = title;
    }

    void setSize(int size) {
        this->size = size;
    }

    string getArtist() {
        return artist;
    }

    string getTitle() {
        return title;
    }

    int getSize() {
        return size;
    }

};