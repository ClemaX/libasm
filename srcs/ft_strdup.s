section	.text
global	_ft_strdup
extern	_malloc
extern	_ft_strlen
extern	_ft_strncpy

_ft_strdup:				; RDI
	push	rdi			; Save src
	call	_ft_strlen	; ft_strlen(RDI)
	inc		rax			; Increment len
	mov		rdi, rax	; Set RDI to size
	push	rax			; Save size
	call	_malloc		; malloc(RDI)
	mov		rdi, rax	; Set RDI to dst
	pop		rdx			; Set RDX to size
	pop		rsi			; Set RSI to src
	call	_ft_strncpy	; ft_strncpy(RDI, RSI, RDX)
	ret
