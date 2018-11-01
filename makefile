final: UtPodDriver.o UtPod.o song.o
	g++ -o test UtPodDriver.o UtPod.o song.o

UtPodDriver.o: UtPodDriver.cpp UtPod.h song.h
	g++ -c UtPodDriver.cpp

UtPod.o: UtPod.cpp UtPod.h song.h
	g++ -c UtPod.cpp

Song.o: song.cpp song.h
	g++ -c song.cpp  