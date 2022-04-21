#Dumistracel Eduard-Costin <eduard.dumistracel@stud.acs.upb.ro>
CC = g++

build: walsh.o statistics.o #prinel.o regele.o crypto.o

run-p1:
	./walsh

run-p2:
	./statistics

#run-p3:
	./prinel

# run-p4:
# 	./regele

# run-p5:
# 	./crypto

walsh.o: walsh.cpp
	$(CC) walsh.cpp -o walsh

statistics.o: statistics.cpp
	$(CC) statistics.cpp -o statistics

prinel.o: prinel.cpp
	$(CC) prinel.cpp -o prinel

.PHONY: clean

clean:
	rm -rf *.o walsh *.out statistics
