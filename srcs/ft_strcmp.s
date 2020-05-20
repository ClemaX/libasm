section	.text
global	ft_strcmp

ft_strcmp:					; RDI, RSI - RAX, RBX!
	.match:					; While the strings match
	mov		al, [rdi]		; Read the actual chars
	mov		bl, [rsi]		;
	cmp		al, bl			; Compare both chars
	ja		.above			;
	jb		.below			;
	test	al, al			; Check for terminator
	jz		.zero			;
	inc		rdi				; Increment pointers
	inc		rsi				;
	jmp		.match			;

.zero:
	mov		eax, 0			; Return 0
	ret

.above:
	mov		eax, 1			; Return 1
	ret

.below:
	mov		eax, -1			; Return -1
	ret
