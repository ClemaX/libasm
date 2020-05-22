section	.data
buff:	times 256 db -1			; 256 bytes writeable -1-buff

section	.text
global	ft_atoi_base

ft_atoi_base:					; RDI, RSI - RAX, RBX!, RCX, RDX
	push	rbx					; Store RBX
	push	rdi					; Store RDI
	push	rsi					; Store RSI
	sub		rax,	rax			; Clear RAX
	sub		rbx,	rbx			; Clear RBX
	sub		rcx,	rcx			; Clear RCX
	lea		rdx,	[rel buff]	; 
.validate:
	mov		al,		[rsi + rcx]	; Read a char at RCX
	cmp		al,		'+'			; Check for invalid chars
	je		.error				; Cannot have signs
	cmp		al,		'-'			;
	je		.error				; Cannot have signs
	cmp		al,		9			; '\t'
	jl		.valid				; Not a whitespace
	cmp		al,		13			; '\r'
	jle		.error				; Cannot have whitespace
	cmp		al,		' '
	je		.error				; Cannot have space
.valid:
	mov		bl,		[rdx + rax]	; Load byte according to character
	cmp		bl,		-1			; Check if character has occurred
	jne		.error				; Cannot have duplicates
	test	al,		al			; Check for terminator
	jz		.validated			; Loop until terminator
	mov		[rdx + rax], cl		; Put position into buffer
	inc		rcx					; Increment RCX
	jmp		.validate
.validated:
	cmp		rcx,	2			; Check minimum length
	jb		.error				; Return if below
	sub		al,		al			; Clear AL
	sub		r10,	r10			; Set RSI to 0
.prefix:
	mov		bl,		[rdi]		; Read a char from RDI
	cmp		bl,		9			; Skip whitespace
	jl		.sign
	cmp		bl,		13
	jle		.skip				;
	cmp		bl,		' '
	je		.skip				;
.sign:
	cmp		bl,		'+'			; Skip plus sign
	je		.skip_sign
	cmp		bl,		'-'			; Continue if there is no sign 
	jne		.root
	inc		r10					; Increment '-' counter 
.skip_sign:
	inc		rdi
	mov		bl,		[rdi]		; Read a char from RDI
	jmp		.sign
.skip:
	inc		rdi					; Increment RDI
	jmp		.prefix
.root:
	mov		rsi,	rdx			; Set RSI to RDX
.convert:
	mov		bl,		[rsi + rbx]	; Read the characters magnitude
	cmp		bl,		-1			; Check for invalid character
	je		.negate
	mul		ecx					; Multiply EAX by ECX
	add		eax,	ebx			; Add the characters magnitude
	inc		rdi					; Increment RDI
	mov		bl,		[rdi]		; Read a char from RDI
	jmp		.convert			; Loop
.negate:
	test	r10,	1			; Check parity
	jz		.done
	neg		eax					; Negate EAX
.done:
	lea		rdx,	[rel buff]	; 
	pop		rsi					; Restore RSI
.clear:
	mov		bl,		[rsi + rcx]	; Read a char at RCX
	mov		byte [rdx + rbx], -1; Reset current char
	test	rcx, rcx			; 
	jz		.exit				; Continue if not zero
	dec		rcx					; Decrement RCX
	jmp		.clear
.exit:
	pop		rdi					; Restore RDI
	pop		rbx					; Restore RBX
	ret
.error:
	sub		rax,	rax			; Return 0
	jmp		.done
