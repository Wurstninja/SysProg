.DEFAULT_GOAL := asm
.PHONY:	clean

asm: print_num.o
	@ld print_num.o
	@./a.out

print_num.o: print_num.s
	@nasm -f elf64 print_num.s

clean:
	@rm *.o *.out
