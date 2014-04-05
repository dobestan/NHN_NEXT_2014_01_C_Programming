	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$76, %esp
	calll	L0$pb
L0$pb:
	popl	%eax
	leal	L_.str-L0$pb(%eax), %ecx
	movl	$0, -16(%ebp)
	movl	%ecx, (%esp)
	movl	%eax, -32(%ebp)         ## 4-byte Spill
	calll	_printf
	movl	-32(%ebp), %ecx         ## 4-byte Reload
	leal	L_.str1-L0$pb(%ecx), %edx
	leal	-20(%ebp), %esi
	leal	-24(%ebp), %edi
	leal	-28(%ebp), %ebx
	movl	%edx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edi, 8(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, -36(%ebp)         ## 4-byte Spill
	calll	_scanf
	movl	-20(%ebp), %ecx
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %esi
	movl	-20(%ebp), %edi
	movl	-24(%ebp), %ebx
	movl	%eax, -40(%ebp)         ## 4-byte Spill
	movl	-28(%ebp), %eax
	movl	%edi, (%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	%esi, -44(%ebp)         ## 4-byte Spill
	movl	%ecx, -48(%ebp)         ## 4-byte Spill
	movl	%edx, -52(%ebp)         ## 4-byte Spill
	calll	_getMaxNum
	movl	-32(%ebp), %ecx         ## 4-byte Reload
	leal	L_.str2-L0$pb(%ecx), %edx
	movl	%edx, (%esp)
	movl	-48(%ebp), %edx         ## 4-byte Reload
	movl	%edx, 4(%esp)
	movl	-52(%ebp), %esi         ## 4-byte Reload
	movl	%esi, 8(%esp)
	movl	-44(%ebp), %edi         ## 4-byte Reload
	movl	%edi, 12(%esp)
	movl	%eax, 16(%esp)
	calll	_printf
	movl	$0, %ecx
	movl	%eax, -56(%ebp)         ## 4-byte Spill
	movl	%ecx, %eax
	addl	$76, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	ret

	.globl	_getMaxNum
	.align	4, 0x90
_getMaxNum:                             ## @getMaxNum
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	12(%ebp), %ecx
	movl	8(%ebp), %edx
	movl	%edx, -4(%ebp)
	movl	%ecx, -8(%ebp)
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
	movl	-4(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jle	LBB1_2
## BB#1:
	movl	-4(%ebp), %eax
	movl	%eax, -20(%ebp)         ## 4-byte Spill
	jmp	LBB1_3
LBB1_2:
	movl	-8(%ebp), %eax
	movl	%eax, -20(%ebp)         ## 4-byte Spill
LBB1_3:
	movl	-20(%ebp), %eax         ## 4-byte Reload
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jle	LBB1_5
## BB#4:
	movl	-16(%ebp), %eax
	movl	%eax, -24(%ebp)         ## 4-byte Spill
	jmp	LBB1_6
LBB1_5:
	movl	-12(%ebp), %eax
	movl	%eax, -24(%ebp)         ## 4-byte Spill
LBB1_6:
	movl	-24(%ebp), %eax         ## 4-byte Reload
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	addl	$24, %esp
	popl	%ebp
	ret

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Enter 3 numbers : "

L_.str1:                                ## @.str1
	.asciz	"%d %d %d"

L_.str2:                                ## @.str2
	.asciz	"getMaxNum( %d , %d , %d) = %d\n"


.subsections_via_symbols
