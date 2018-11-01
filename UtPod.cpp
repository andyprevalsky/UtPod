#include "UtPod.h"
#include "song.h"
#include <stdlib.h>
#include <time.h>

UtPod::UtPod() {
    songs = NULL;
    this->memSize = MAX_MEMORY;
}

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
    return SUCCESS;
}

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

void UtPod::showSongList() {
    SongNode* temp = songs;
    while(temp!= NULL){
        cout << temp->s.getTitle() << ", " << temp->s.getArtist() << ", " << temp->s.getSize() << " MB" << endl;
        temp = temp->next;
    }
}

void UtPod::sortSongList() {
    int length = getLength();
    if(length < 2){
        return;
    }
    SongNode* song1;
    for(int i = 0;i < length; i++){
        song1 = songs;
        for(int j = 0;j < length-1;j++){
            if(song1->s > song1->next->s){
                Song tmp = song1->s;
                song1->s = song1->next->s;
                song1->next->s = tmp;
            }
            song1 = song1->next;
        }
    }
}

void UtPod::clearMemory() { 
    SongNode* temp = songs;
    SongNode* prev;
    while(temp != NULL){
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    songs = NULL;
    return;
}
     
int UtPod::getRemainingMemory() {
    SongNode *temp = songs;
    int size = 0;
    while(temp != NULL){
        size = size + temp->s.getSize();
        temp = temp->next;
    }
    return memSize-size;
}

UtPod::~UtPod() {
    clearMemory();
}