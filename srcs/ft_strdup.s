section	.text
global	ft_strdup
extern	malloc
extern	ft_strlen
extern	ft_strncpy

ft_strdup:						; RDI
	push	rdi					; Save src
	call	ft_strlen			; ft_strlen(RDI)
	inc		rax					; Increment len
	mov		rdi, rax			; Set RDI to size
	push	rax					; Save size
	call	malloc wrt ..plt	; malloc(RDI)
	mov		rdi, rax			; Set RDI to dst
	pop		rdx					; Set RDX to size
	pop		rsi					; Set RSI to src
	call	ft_strncpy			; ft_strncpy(RDI, RSI, RDX)
	ret
