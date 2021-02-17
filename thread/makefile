GCC = gcc
PTHREAD = -pthread
MATH = -lm

all: \
	main_reta \
	main_seno

%: %.c
	$(GCC) $< -o $@ $(PTHREAD) $(MATH)

reta: 
	./main_reta 6 120
	
seno:
	./main_seno 7 200

clean:
	rm main_reta main_seno