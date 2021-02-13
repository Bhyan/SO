GCC = gcc
PTHREAD = -pthread
MATH = -lm

all: \
	main

%: %.c
	$(GCC) $< -o $@ $(PTHREAD) $(MATH)

run: 
	./main 6 120

clean:
	rm main