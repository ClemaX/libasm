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
	cmp		rcx,	2			; Check minimum length
	jb		.error				; Return if below
	mov		al,		1			; Set AL to 1
	mov		rsi,	0			; Set RDI to 0
.skip_whitespace:
	cmp		bl,		'\t'
	jl		.sign
	cmp		bl,		'\r'
	jl		.whitespace
	cmp		bl,		' '
	je		.whitespace
.sign:
	mov		bl,		[rdi]		; Read a char from RDI
	cmp		bl,		'+'			; 
	je		.skip				; Skip '+' sign
	cmp		bl,		'-'			; 
	jne		.negate				; Continue if there is no sign
	inc		rsi					; Increment '-' counter
	inc		rdi					; Increment RDI
	jmp		.sign
.negate:
	test	rsi,	1			; Check parity
	jz		.convert
	neg		eax
.convert:
	mov		bl,		[rdi]		; Read a char from RDI
	mov		al,		[rdx + rax]	; Read the characters magnitude
	cmp		al,		-1			; Check for invalid character
	je		.exit
	imul	ecx					; Multiply EAX by ECX
	add		eax,	al			;
.exit:
	ret
.error:
	sub		rax,	rax			; Return 0
	jmp		.exit
.skip:
	inc		rdi					; Skip whitespace
	jmp		.skip_whitespace	
