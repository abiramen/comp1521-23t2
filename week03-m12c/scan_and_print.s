ARRAY_SIZE = 10

main:
        
	# Locals:
	#	- $t0: int i
read_loop__init:
	li	$t0, 0
read_loop__cond:
	bge	$t0, ARRAY_SIZE, read_loop__end

read_loop__body:
	li	$v0, 5			# syscall 5: read_int
	syscall

	la	$t1, numbers		# numbers
	mul	$t2, $t0, 4		# (4 * i)
	add	$t2, $t2, $t1		# (numbers + 4 * i)

	sw	$v0, ($t2)		# scanf("%d", &numbers[i]);

read_loop__step:
	addi	$t0, $t0, 1		# i++;
	j	read_loop__cond
read_loop__end:

print_loop__init:
	li	$t0, 0
print_loop__cond:
	bge	$t0, ARRAY_SIZE, print_loop__end

print_loop__body:
	li	$v0, 1			# syscall 1: print_int

	mul	$t1, $t0, 4		# (4 * i)
	lw	$a0, numbers($t1)	# numbers + (4 * i)
	syscall				# printf("%d", numbers[i]);

	li	$v0, 11			# syscall 11: print_char
	li	$a0, ' '		#
	syscall				# putchar(' ');


print_loop__step:
	addi	$t0, $t0, 1		# i++;
	j	print_loop__cond
print_loop__end:
        
	li	$v0, 0
	jr	$ra			# return 0;


        .data
numbers:
        .word	0:ARRAY_SIZE
