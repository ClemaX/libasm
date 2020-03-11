section	.text
global	_ft_list_size

_ft_list_size:					; RDI
	sub		rax,	rax			; Clear RCX
.loop:
	test	rdi,	rdi			; Check for NULL
	jz	.end
	mov		rdi,	[rdi + 8]	; Load next pointer
	inc	rax
	jmp	.loop					; Loop
.end:
	ret
