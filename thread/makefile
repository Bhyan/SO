GCC = gcc
PTHREAD = -pthread

all: \
	main

%: %.c
	$(GCC) $< -o $@ $(PTHREAD)

run: 
	./main

clean:
	rm main