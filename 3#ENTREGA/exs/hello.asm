; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_entry:function
; LABEL
$_entry:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 16
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; LABEL
$_i1:
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 10
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i2
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; LABEL
$_i4:
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 10
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i5
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i7:
; CHAR
	db	0x6A
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i7
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; PUSH
	push	eax
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; LABEL
$_i8:
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 10
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i9
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 6
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 4
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; AND
	pop	eax
	and	dword [esp], eax
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i11
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i12:
; CHAR
	db	0x77
; CHAR
	db	0x69
; CHAR
	db	0x74
; CHAR
	db	0x68
; CHAR
	db	0x20
; CHAR
	db	0x6B
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i12
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i13:
; CHAR
	db	0x20
; CHAR
	db	0x61
; CHAR
	db	0x6E
; CHAR
	db	0x64
; CHAR
	db	0x20
; CHAR
	db	0x6A
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i13
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i14:
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x20
; CHAR
	db	0x77
; CHAR
	db	0x69
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x20
; CHAR
	db	0x6E
; CHAR
	db	0x6F
; CHAR
	db	0x77
; CHAR
	db	0x20
; CHAR
	db	0x63
; CHAR
	db	0x6F
; CHAR
	db	0x6E
; CHAR
	db	0x74
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x75
; CHAR
	db	0x65
; CHAR
	db	0x20
; CHAR
	db	0x32
; CHAR
	db	0x20
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i14
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i2
; LABEL
$_i11:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i15:
; CHAR
	db	0x6B
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i15
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; PUSH
	push	eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i16:
; CHAR
	db	0x33
; CHAR
	db	0x72
; CHAR
	db	0x64
; CHAR
	db	0x20
; CHAR
	db	0x66
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i16
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LABEL
$_i10:
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; JMP
	jmp	dword $_i8
; LABEL
$_i9:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i17:
; CHAR
	db	0x32
; CHAR
	db	0x6E
; CHAR
	db	0x64
; CHAR
	db	0x20
; CHAR
	db	0x66
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i17
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LABEL
$_i6:
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; JMP
	jmp	dword $_i4
; LABEL
$_i5:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i18:
; CHAR
	db	0x31
; CHAR
	db	0x73
; CHAR
	db	0x74
; CHAR
	db	0x20
; CHAR
	db	0x66
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i18
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i19:
; CHAR
	db	0x69
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i19
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LABEL
$_i3:
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; JMP
	jmp	dword $_i1
; LABEL
$_i2:
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; EXTRN
extern	$_println
; EXTRN
extern	$_prints
; EXTRN
extern	$_printi
