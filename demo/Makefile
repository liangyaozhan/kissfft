

.PHONY: all clean


test-wave:test-wave.c wave-signal.h wave-signal.c
	gcc -Wall -O0 -g test-wave.c wave-signal.c -o $@ -lm



clean:
	-rm -f test-wave
