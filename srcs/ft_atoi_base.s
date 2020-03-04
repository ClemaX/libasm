section	.text
global	_ft_atoi_base
extern	_ft_strlen

_ft_atoi_base:					; RDI, RSI
	push	rbp					; Save the stack base pointer
	mov		rbp, rsp			; Set the base pointer to the top of the stack
	sub		rsp, 32				; Reserve 32 bytes for 256 boolleans
	sub		rcx, rcx			; Clear RCX
	sub		rsi, rsi			; Clear RSI
.valid:
	mov		al, [rdi + rcx]		; Read a bhar at RCX
	cmp		al, '+'				; Check for invalid chars
	je		.error				; Cannot have signs
	cmp		al, '-'				;
	je		.error				; Cannot have signs
	sub		ah, ah				; Clear ah
	mov		bx, 16				; Set bx to 16
	div		bl					; AX/BL -> AL: Q, AH: R
	mov		sil, al				; Set sil to Q
	mov		bh, ah				; Set bh to R
	mov		ax, [rbp + rsi]		; Load 2 bytes at Q
	bts		ax, bx				; Set bit at R and check value -> CF
	mov		[rbp + rsi], ax		; Store bytes at Q
	jc		.error				; Dupplicate characters
	test	al, al				; Check for terminator
	inc		rcx					; Increment RCX
	jnz		.valid				; Loop until terminator
	cmp		rcx, 2				; Check minimum length
	jb		.error				; Return if below
	mov		rax, 1				; Return 1 TEST
.exit:
	mov		rsp, rbp			; 
	pop		rbp
	ret		32
.error:
	sub		rax, rax			; Return 0
	jmp		.exit

