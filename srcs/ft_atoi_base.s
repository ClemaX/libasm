section .data
buff:		times 32 dq -1		; 256 bytes writeable zero-buff

section	.text
global	_ft_atoi_base

_ft_atoi_base:					; RDI, RSI
	sub		rcx,	rcx			; Clear RCX
	sub		rax,	rax			; Clear RAX
	mov		rdx,	buff		; 
.validate:
	mov		al,		[rsi + rcx]	; Read a char at RCX
	cmp		al,		'+'			; Check for invalid chars
	je		.error				; Cannot have signs
	cmp		al,		'-'			;
	je		.error				; Cannot have signs
	mov		bl,		[rdx + rax]	; Load byte according to character
	cmp		bl,		-1			; Check if character has occurred
	jne		.error				; Cannot have duplicates
	mov		[rdx + rax], cl		; Put position into buffer
	inc		rcx					; Increment RCX
	test	al,		al			; Check for terminator
	jnz		.validate			; Loop until terminator
	sub		rcx,	1			; Get length from size
	cmp		rcx,	2			; Check minimum length
	jb		.error				; Return if below
	sub		al,		al			; Clear AL
	sub		rbx,	rbx			; Clear RBX
	sub		rsi,	rsi			; Set RSI to 0
.prefix:
	mov		bl,		[rdi]		; Read a char from RDI
	cmp		bl,		'+'			; Skip '+' sign
	je		.skip
	cmp		bl,		9			; Skip whitespace
	jl		.sign
	cmp		bl,		13
	jl		.skip				;
	cmp		bl,		' '
	je		.skip				;
.sign:
	cmp		bl,		'-'			; Continue if there is no sign 
	jne		.convert
	inc		rsi					; Increment '-' counter TODO: inc si should be enough
.skip:
	inc		rdi					; Increment RDI
	jmp		.prefix				; TODO: push rsi
.convert:
	mov		bl,		[rdx + rbx]	; Read the characters magnitude
	cmp		bl,		-1			; Check for invalid character
	je		.exit
	mul		ecx					; Multiply EAX by ECX
	add		eax,	ebx			; Add the characters magnitude
	inc		rdi					; Increment RDI
	mov		bl,		[rdi]		; Read a char from RDI
	jmp		.convert			; Loop
.negate:
	test	si,	1				; Check parity
	jz		.exit
	neg		eax
.exit:
	ret
.error:
	sub		rax,	rax			; Return 0
	jmp		.exit

