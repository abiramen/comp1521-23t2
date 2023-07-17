	.data
a:
	.word	1521
b:
	.byte	42


	.text
main:
	la	$t0, a
	la	$t1, b

	lw	$t2, ($t0)
	lb	$t3, ($t1)

	# lw	$t2, a
	# lb	$t3, b

	add	$t2, $t2, $t3

	sw	$t2, ($t0)		# a = a + b
