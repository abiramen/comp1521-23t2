main:
	# Locals:
	#	- $t0: int n
main__prologue:
	begin
	push	$ra

main__body:
	li	$v0, 4				# syscall 4: print_string
	la	$a0, main__enter_number_prompt	#
	syscall					# printf("Enter a number: ");

	li	$v0, 5				# syscall 5: read_int
	syscall					#
	move	$t0, $v0			# scanf("%d", &n);


	li	$v0, 4				# syscall 4: print_string
	la	$a0, main__fibonacci_msg_1	#
	syscall					# printf("Fibonacci of ");

	li	$v0, 1				# syscall 1: print_int
	move	$a0, $t0			#
	syscall					# printf("%d", n);


	li	$v0, 4				# syscall 4: print_string
	la	$a0, main__fibonacci_msg_2	#
	syscall					# printf("Fibonacci of ");

	move	$a0, $t0
	jal	fib				# fib(n)

	move	$a0, $v0
	li	$v0, 1				# syscall 1: print_int
	syscall					# printf("%d", fib(n));

	li	$v0, 11
	li	$a0, '\n'
	syscall					# putchar('\n')

	li	$v0, 0

main__epilogue:
	pop	$ra
	end
	jr	$ra


fib:
	# Args:
	#	- $a0: int n
	# Returns:
	#
	# Stack: 	[$ra, $s0, $s1]
	# Uses:		[$ra, $s0, $s1, $a0, $v0]
	# Clobbers:	[$a0, $v0]
	#
	# Locals:
	#	- $s0: int n
	#	- $s1: return value of fib(n - 1)
	#
	# Structure:
	#	-> [prologue]
	#	-> [body]
	#	  -> n_lt_2
	#	-> [epilogue]
fib__prologue:
	begin
	push	$ra
	push	$s0
	push	$s1

fib__body:
	blt	$a0, 2, fib__n_lt_2

	move	$s0, $a0

	addi	$a0, $s0, -1
	jal	fib			# fib(n - 1)

	move	$s1, $v0

	addi	$a0, $s0, -2
	jal	fib			# fib(n - 2)

	add	$v0, $s1, $v0		# retval = fib(n - 1) + fib(n - 2);
	j	fib__epilogue

fib__n_lt_2:
	move	$v0, $a0		# retval = n;

fib__epilogue:
	pop	$s1
	pop	$s0
	pop	$ra
	end
	jr	$ra



	.data
main__enter_number_prompt:
	.asciiz	"Enter a number: "
main__fibonacci_msg_1:
	.asciiz	"Fibonacci of "
main__fibonacci_msg_2:
	.asciiz	" is "
