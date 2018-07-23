CORE=../core
TEMP=./
OBJECTS=$(TEMP)/test_alarm.o $(TEMP)/solar_alarm.o $(TEMP)/solar_log.o

test_alarm.exe: $(OBJECTS)
	gcc -o test_alarm.exe $(OBJECTS)

$(TEMP)/test_alarm.o: test_alarm.c
	gcc -c test_alarm.c

$(TEMP)/solar_alarm.o: $(CORE)/solar_alarm.c
	gcc -c $(CORE)/solar_alarm.c

$(TEMP)/solar_log.o: $(CORE)/solar_log.c
	gcc -c $(CORE)/solar_log.c