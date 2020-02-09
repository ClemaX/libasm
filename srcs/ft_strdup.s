section	.text
global	_ft_strdup
extern	_malloc
extern	_ft_strlen
extern	_ft_strncpy

_ft_strdup:				; RDI
	mov		rsi, rdi	; Set RSI to src
	call	_ft_strlen	; ft_strlen(RDI)
	inc		rax			; Increment length
	mov		rcx, rax	; Set RDI to size
	mov		rdx, rax	; Set RDX to size
	call	_malloc		; malloc(RCX)
	mov		rdi, rax	; Set RDI to dst
	call	_ft_strncpy	; ft_strncpy(RDI, RSI, RDX)
	ret
