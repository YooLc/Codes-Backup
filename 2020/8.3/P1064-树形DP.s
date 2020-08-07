	.file	"P1064-\312\367\320\316DP.cpp"
	.text
	.p2align 4,,15
	.globl	__Z3dfsii
	.def	__Z3dfsii;	.scl	2;	.type	32;	.endef
__Z3dfsii:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	_volume, %edx
	movl	64(%esp), %eax
	movl	_cost(,%eax,4), %eax
	cmpl	%edx, %eax
	jg	L5
	movl	64(%esp), %edi
	imull	$3205, %edi, %ebx
	movl	_val(,%edi,4), %ecx
	addl	%ebx, %eax
	addl	%ebx, %edx
	leal	_dp(,%eax,4), %eax
	leal	_dp+4(,%edx,4), %edx
	.p2align 4,,10
L6:
	movl	%ecx, (%eax)
	addl	$4, %eax
	cmpl	%edx, %eax
	jne	L6
L5:
	movl	64(%esp), %eax
	movl	_head(,%eax,4), %eax
	movl	%eax, 24(%esp)
	testl	%eax, %eax
	je	L1
	imull	$3205, 64(%esp), %eax
	movl	%eax, 28(%esp)
L8:
	movl	24(%esp), %eax
	movl	_ver(,%eax,4), %ebx
	cmpl	68(%esp), %ebx
	jne	L7
L9:
	movl	24(%esp), %eax
	movl	__next(,%eax,4), %eax
	movl	%eax, 24(%esp)
	testl	%eax, %eax
	jne	L8
L1:
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
L7:
	.cfi_restore_state
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	__Z3dfsii
	movl	64(%esp), %edi
	movl	_volume, %eax
	movl	_cost(,%edi,4), %edx
	cmpl	%edx, %eax
	jl	L9
	movl	28(%esp), %edi
	movl	%eax, %ebp
	subl	%edx, %ebp
	leal	1073741823(%eax,%edi), %eax
	leal	_dp(,%eax,4), %esi
	imull	$3205, %ebx, %eax
	imull	$12820, %ebx, %ebx
	addl	%ebp, %eax
	leal	_dp(,%eax,4), %edi
	leal	_dp(%ebx), %eax
	movl	%eax, 20(%esp)
	.p2align 4,,10
L12:
	testl	%ebp, %ebp
	je	L9
	movl	4(%esi), %ebx
	movl	20(%esp), %edx
	movl	%esi, %ecx
	.p2align 4,,10
L11:
	movl	4(%edx), %eax
	addl	(%ecx), %eax
	cmpl	%eax, %ebx
	jge	L10
	movl	%eax, %ebx
L10:
	addl	$4, %edx
	movl	%ebx, 4(%esi)
	subl	$4, %ecx
	cmpl	%edi, %edx
	jne	L11
	subl	$1, %ebp
	subl	$4, %esi
	subl	$4, %edi
	jmp	L12
	.cfi_endproc
LFE18:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "r\0"
LC1:
	.ascii "P1064.in\0"
LC2:
	.ascii "%d %d\0"
LC3:
	.ascii "%d\12\0"
LC4:
	.ascii "%d %d %d\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$32, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	call	___main
	movl	__imp___iob, %eax
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	movl	%eax, 8(%esp)
	call	_freopen
	movl	$_n, 8(%esp)
	movl	$_volume, 4(%esp)
	movl	$LC2, (%esp)
	call	_scanf
	movl	_volume, %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	sarl	$31, %ecx
	imull	%edx
	movl	_n, %eax
	sarl	$2, %edx
	subl	%ecx, %edx
	movl	%edx, _volume
	testl	%eax, %eax
	jle	L28
	movl	$1, %ebx
	leal	28(%esp), %edi
	movl	$1717986919, %esi
	.p2align 4,,10
L27:
	leal	0(,%ebx,4), %eax
	movl	%edi, 12(%esp)
	leal	_val(%eax), %edx
	addl	$_cost, %eax
	movl	$LC4, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	_scanf
	movl	_cost(,%ebx,4), %ecx
	movl	_val(,%ebx,4), %eax
	imull	%ecx, %eax
	movl	%eax, _val(,%ebx,4)
	movl	%ecx, %eax
	sarl	$31, %ecx
	imull	%esi
	movl	_tot, %eax
	addl	$1, %eax
	sarl	$2, %edx
	movl	%ebx, _ver(,%eax,4)
	subl	%ecx, %edx
	movl	%eax, _tot
	movl	%edx, _cost(,%ebx,4)
	movl	28(%esp), %edx
	addl	$1, %ebx
	movl	_head(,%edx,4), %ecx
	movl	%eax, _head(,%edx,4)
	movl	%ecx, __next(,%eax,4)
	cmpl	%ebx, _n
	jge	L27
L28:
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	call	__Z3dfsii
	movl	_volume, %eax
	movl	$LC3, (%esp)
	movl	_dp(,%eax,4), %eax
	movl	%eax, 4(%esp)
	call	_printf
	leal	-12(%ebp), %esp
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.globl	_volume
	.bss
	.align 4
_volume:
	.space 4
	.globl	_n
	.align 4
_n:
	.space 4
	.globl	_dp
	.align 32
_dp:
	.space 782020
	.globl	_val
	.align 32
_val:
	.space 244
	.globl	_cost
	.align 32
_cost:
	.space 244
	.globl	_tot
	.align 4
_tot:
	.space 4
	.globl	_ver
	.align 32
_ver:
	.space 244
	.globl	__next
	.align 32
__next:
	.space 244
	.globl	_head
	.align 32
_head:
	.space 244
	.ident	"GCC: (MinGW.org GCC-8.2.0-5) 8.2.0"
	.def	_freopen;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
