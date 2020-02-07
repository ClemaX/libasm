section	.text
global	_ft_strcpy
extern	_ft_strlen

_ft_strncpy:			; RDI, RSI, RDX
	mov		rax, rdi	; Set RAX to dest
	mov		rcx, rdx	; Set RCX to RCX
	cld					; Clear DF / go forward
	rep		movsb		; Copy RCX bytes from RSI to RDI
	ret

_ft_strcpy:				; RDI, RSI
	push	rdi			; Save RDI
	mov		rdi, rsi	; Put RSI into RDI
	call	_ft_strlen	; Get total length
	pop		rdi			; Restore RDI
	mov		rdx, rax	; Put length into RDX
	inc		rdx			; Increment RDX to give size
	call	_ft_strncpy	; Copy total string
	ret
