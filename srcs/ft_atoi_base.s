section	.text
global	_ft_atoi_base
extern	_ft_strlen

_ft_atoi_base:					; RDI, RSI
	jmp		validate_base

validate_base:					; RDI
	sub		rcx, rcx			; Clear RCX
.valid:
	mov		al, [rdi + rcx]		; Read a char at RCX
	cmp		al, '+'				; Check for invalid chars
	je		.error				; Cannot have signs
	cmp		al, '-'				;
	je		.error				; Cannot have signs
	btc		occured, al			; Toggle bit and check value
	jc		.error				; Dupplicate characters
	test	al, al				; Check for terminator
	inc		rcx					; Increment RCX
	jnz		.valid				; Loop until terminator
	cmp		rcx, 2				; Check minimum length
	jb		.error				; Return if below
	mov		rax, 1				; Return 1 TEST
	ret
.error:
	sub		rax, rax			; Clear RAX
	ret
