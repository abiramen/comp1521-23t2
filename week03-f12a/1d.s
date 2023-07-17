main:

	li	$t0, 4

	# la	$t1, array		# (array +
	# mul	$t2, $t0, 4		#  4 * i)
	# add	$t1, $t1, $t2
	# lw	$a0, ($t1)

	mul	$t1, $t0, 4		# (4 * i)
	lw	$a0, array($t1)


	li	$v0, 1			# syscall 1: print_int
	syscall

	li	$v0, 11
	la	$a0, '\n'
	syscall



	li	$v0, 0
	jr	$ra			# return 0;

	.data

array:
	.word	3, 1, 4, 1, 5
