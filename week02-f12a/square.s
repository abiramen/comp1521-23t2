	.text
main:
	# Locals:
	# - $t0: int x
	# - $t1: int y

	li	$v0, 4			# syscall 4: print_string
	la	$a0, enter_number_msg	# 
	syscall				# printf("Enter a number: ");

	li	$v0, 5			# syscall 5: read_int
	syscall				#
	move	$t0, $v0		# scanf("%d", &x);

	mul	$t1, $t0, $t0		# y = x * x;

	li	$v0, 1			# syscall 1: print_int
	move	$a0, $t1		#
	syscall				# printf("%d", y);

	li	$v0, 11			# syscall 11: print_char
	li	$a0, '\n'		#
	syscall				# putchar('\n');



	li	$v0, 0			#
	jr	$ra			# return 0;

	.data
enter_number_msg:
	.asciiz	"Enter a number: "
        