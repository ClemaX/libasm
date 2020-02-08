section	.text
global	_ft_strcmp

_ft_strcmp:					; RDI, RSI
	match:					; While the strings match
	mov		al, [rdi]	;
	mov		bl, [rsi]	;
	cmp		al, bl			; Compare both chars
	ja		above
	jb		below
	test	al, al			; Check for terminator
	jz		zero
	inc		rdi				; Increment counter
	inc		rsi				; Increment counter
	jmp		match			;

zero:
	mov		eax, 0			; Return 0
	ret

above:
	mov		eax, 1			; Return 1
	ret

below:
	mov		eax, -1			; Return -1
	ret