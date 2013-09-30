EXAMPLES := ex0 ex1 ex2

all: $(EXAMPLES)

%: %.c
	gcc -g -o $@ $<

clean:
	rm -f $(EXAMPLES)
