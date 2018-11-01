final: UtPodDriver.o UtPod.o Song.o
	g++ -o UtPodDriver UtPodDriver.o UtPod.o Song.o

UtPodDriver.o: UtPodDriver.cpp UtPod.h song.h
	g++ -c UtPodDriver.cpp

UtPod.o: UtPod.h song.h
	g++ -c UtPod.cpp
	
Song.o: song.h
	g++ -c Song.cpp  