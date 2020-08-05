	.file	"P1064-\312\367\320\316DP.cpp"
	.text
	.section .rdata,"dr"
	.align 4
__ZL4MAXN:
	.long	3205
	.align 4
__ZL4MAXM:
	.long	61
	.globl	_head
	.bss
	.align 32
_head:
	.space 244
	.globl	__next
	.align 32
__next:
	.space 244
	.globl	_ver
	.align 32
_ver:
	.space 244
	.globl	_tot
	.align 4
_tot:
	.space 4
	.globl	_cost
	.align 32
_cost:
	.space 244
	.globl	_val
	.align 32
_val:
	.space 244
	.globl	_dp
	.align 32
_dp:
	.space 782020
	.globl	_n
	.align 4
_n:
	.space 4
	.globl	_volume
	.align 4
_volume:
	.space 4
	.section	.text$_Z3maxii,"x"
	.linkonce discard
	.globl	__Z3maxii
	.def	__Z3maxii;	.scl	2;	.type	32;	.endef
__Z3maxii:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jle	L2
	movl	8(%ebp), %eax
	jmp	L4
L2:
	movl	12(%ebp), %eax
L4:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.text
	.globl	__Z3dfsii
	.def	__Z3dfsii;	.scl	2;	.type	32;	.endef
__Z3dfsii:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	_cost(,%eax,4), %eax
	movl	%eax, -12(%ebp)
L7:
	movl	_volume, %eax
	cmpl	%eax, -12(%ebp)
	jg	L6
	movl	8(%ebp), %eax
	movl	_val(,%eax,4), %eax
	movl	8(%ebp), %edx
	imull	$3205, %edx, %ecx
	movl	-12(%ebp), %edx
	addl	%ecx, %edx
	movl	%eax, _dp(,%edx,4)
	addl	$1, -12(%ebp)
	jmp	L7
L6:
	movl	8(%ebp), %eax
	movl	_head(,%eax,4), %eax
	movl	%eax, -16(%ebp)
L14:
	cmpl	$0, -16(%ebp)
	je	L15
	movl	-16(%ebp), %eax
	movl	_ver(,%eax,4), %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	cmpl	12(%ebp), %eax
	je	L16
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z3dfsii
	movl	_volume, %eax
	movl	%eax, -20(%ebp)
L13:
	movl	8(%ebp), %eax
	movl	_cost(,%eax,4), %eax
	cmpl	%eax, -20(%ebp)
	jl	L10
	movl	$1, -24(%ebp)
L12:
	movl	8(%ebp), %eax
	movl	_cost(,%eax,4), %eax
	movl	-20(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	%eax, -24(%ebp)
	jg	L11
	movl	-20(%ebp), %eax
	subl	-24(%ebp), %eax
	movl	8(%ebp), %edx
	imull	$3205, %edx, %edx
	addl	%edx, %eax
	movl	_dp(,%eax,4), %edx
	movl	-28(%ebp), %eax
	imull	$3205, %eax, %ecx
	movl	-24(%ebp), %eax
	addl	%ecx, %eax
	movl	_dp(,%eax,4), %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	imull	$3205, %eax, %ecx
	movl	-20(%ebp), %eax
	addl	%ecx, %eax
	movl	_dp(,%eax,4), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z3maxii
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	imull	$3205, %eax, %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	%ecx, _dp(,%eax,4)
	addl	$1, -24(%ebp)
	jmp	L12
L11:
	subl	$1, -20(%ebp)
	jmp	L13
L16:
	nop
L10:
	movl	-16(%ebp), %eax
	movl	__next(,%eax,4), %eax
	movl	%eax, -16(%ebp)
	jmp	L14
L15:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "r\0"
LC1:
	.ascii "P1064.in\0"
LC2:
	.ascii "%d %d\0"
LC3:
	.ascii "%d %d %d\0"
LC4:
	.ascii "%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	__imp___iob, %eax
	movl	%eax, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_freopen
	movl	$_n, 8(%esp)
	movl	$_volume, 4(%esp)
	movl	$LC2, (%esp)
	call	_scanf
	movl	_volume, %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, _volume
	movl	$1, 28(%esp)
L19:
	movl	_n, %eax
	cmpl	%eax, 28(%esp)
	jg	L18
	movl	28(%esp), %eax
	sall	$2, %eax
	leal	_val(%eax), %ecx
	movl	28(%esp), %eax
	sall	$2, %eax
	leal	_cost(%eax), %edx
	leal	24(%esp), %eax
	movl	%eax, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	movl	28(%esp), %eax
	movl	_val(,%eax,4), %edx
	movl	28(%esp), %eax
	movl	_cost(,%eax,4), %eax
	imull	%eax, %edx
	movl	28(%esp), %eax
	movl	%edx, _val(,%eax,4)
	movl	28(%esp), %eax
	movl	_cost(,%eax,4), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	28(%esp), %eax
	movl	%edx, _cost(,%eax,4)
	movl	_tot, %eax
	addl	$1, %eax
	movl	%eax, _tot
	movl	_tot, %eax
	movl	28(%esp), %edx
	movl	%edx, _ver(,%eax,4)
	movl	24(%esp), %edx
	movl	_tot, %eax
	movl	_head(,%edx,4), %edx
	movl	%edx, __next(,%eax,4)
	movl	24(%esp), %eax
	movl	_tot, %edx
	movl	%edx, _head(,%eax,4)
	addl	$1, 28(%esp)
	jmp	L19
L18:
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	call	__Z3dfsii
	movl	_volume, %eax
	movl	_dp(,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.ident	"GCC: (MinGW.org GCC-8.2.0-5) 8.2.0"
	.def	_freopen;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
