	.data
fib__enter_number_msg:
	.asciiz	"Enter a number: "
fib__result_msg_1:
	.asciiz	"Fibonacci of "
fib__result_msg_2:
	.asciiz	" is "


	.text
main:
	# Args: void
	# Returns:
	#	- $v0: int
	#
	# Stack:	[$ra]
	# Uses:		[$ra, $v0, $a0, $t0]
	# Clobbers:	[$v0, $a0, $t0]
	#
	# Locals:
	#	- $t0: int n
	#
	# Structure:
	#	-> [prologue]
	#	-> [body]
	#	-> [epilogue]

main__prologue:
	begin
	push	$ra

main__body:
	li	$v0, 4
	la	$a0, fib__enter_number_msg
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

	li	$v0, 4
	la	$a0, fib__result_msg_1
	syscall

	li	$v0, 1
	move	$a0, $t0
	syscall

	li	$v0, 4
	la	$a0, fib__result_msg_2
	syscall

	move	$a0, $t0
	jal	fib

	move	$a0, $v0
	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

	li	$v0, 0

main__epilogue:
	pop	$ra
	end
	jr	$ra

fib:
	# Args:
	#	- $a0: int n
	# Returns:
	#	- $v0: int
	#
	# Stack:	[$ra, $s0, $s1]
	# Uses:		[]
	# Clobbers:	[]
	#
	# Locals:
	#
	#	- $s0: int n
	#	- $s1: fib(n - 1)
	# Structure:
	# -> [prologue]
	# -> [body]
	#	-> n_lt_2
	# -> [epilogue]
fib__prologue:
	begin
	push	$ra
	push	$s0
	push	$s1

fib__body:
	move	$s0, $a0

	blt	$a0, 2, fib__n_lt_2

	addi	$a0, $s0, -1
	jal	fib

	move	$s1, $v0

	addi	$a0, $s0, -2
	jal	fib

	add	$v0, $v0, $s1

	j	fib__epilogue

fib__n_lt_2:
	move	$v0, $a0


fib__epilogue:
	pop	$s1
	pop	$s0
	end

	jr	$ra
