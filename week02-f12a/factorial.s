# Iteratively calculate a factorial.

main:
	# Locals:
	# - $t0: int n

	li	$v0, 4			# syscall 4: print_string
	la	$a0, prompt_msg		#
	syscall				# printf("n = ");

	li	$v0, 5			# syscall 5: read_int
	syscall				# 
	move	$t0, $v0		# scanf("%d", &n);

	# TODO: implement a loop

	li	$v0, 4			# syscall 4: print_string
	la	$a0, result_msg		#
	syscall				# printf("n! = ");

	# TODO: print the result

	li	$v0, 11			# syscall 11: print_char
	li	$a0, '\n'		#
	syscall				# putchar('\n');

	li	$v0, 0
	jr	$ra			# return 0;

	.data
prompt_msg:
	.asciiz	"n = "
result_msg:
	.asciiz	"n! = "
