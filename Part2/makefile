all: tdQ

tdQ: testDriver_BH.o EmptyDataCollectionException.o
	g++ -o tdQ -Wall testDriver_BH.o EmptyDataCollectionException.o
	
testDriver_BH.o: testDriver_BH.cpp 
	g++ -c -Wall testDriver_BH.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h 
	g++ -c -Wall EmptyDataCollectionException.cpp

clean:	
	rm -f tdQ *.o
