section .data
buff:	times 32 dq -1			; 256 bytes writeable zero-buff

section	.text
global	_ft_atoi_base

_ft_atoi_base:					; RDI, RSI
	sub		rcx, rcx			; Clear RCX
	sub		rax, rax			; Clear RAX
	mov		rdx, buff			; 
.valid:
	mov		al, [rsi + rcx]		; Read a char at RCX
	cmp		al, '+'				; Check for invalid chars
	je		.error				; Cannot have signs
	cmp		al, '-'				;
	je		.error				; Cannot have signs
	mov		bl, [rdx + rax]		; Load byte according to character
	cmp		bl, -1				; Check if character has occurred
	jne		.error				; Cannot have duplicates
	mov		[rdx + rax], cl		; Put position into buffer
	inc		rcx					; Increment RCX
	test	al, al				; Check for terminator
	jnz		.valid				; Loop until terminator
	cmp		rcx, 2				; Check minimum length
	jb		.error				; Return if below
	mov		al, 1				; Set AL to 1
	mov		rsi, 0				; Set RDI to 0
.sign:
	mov		bl, [rdi + rsi]
	cmp		bl, '+'
	je		.sign				; Skip '+' sign
	cmp		bl, '-'
	jne		.convert
	inc		rdi					; Increment '-' counter
	jmp		.sign
.convert:
	imul	eax
.exit:
	ret
.error:
	sub		rax, rax			; Return 0
	jmp		.exit

