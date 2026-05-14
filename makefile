.PHONY: comp clean run

comp:
	gcc -O3 src/*.c -o output -lraylib -lm -lX11

clean:
	rm -f output

run: comp 
	./output 
	$(MAKE) clean



