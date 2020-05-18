section	.text
extern	malloc
global	ft_list_push_front

ft_list_push_front:				; RDI, RSI
	push	rdi
	push	rsi
	mov		rdi,		16
	call	malloc wrt ..plt	; malloc(sizeof(t_list))
	pop		rsi
	pop		rdi
	test	rax, rax			; Check for NULL
	jz		.end
	mov		[rax],		rsi
	mov		r10,		[rdi]	; Dereference RDI
	mov		[rax + 8],	r10
	mov		[rdi],		rax
.end:
	ret
