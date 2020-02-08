section	.text
global	_ft_write

_ft_write:					; RDI, RSI, RDX
	test	rdx, rdx
	js		error			;
	mov		rax, 0x2000004	; Write Call #
	syscall					; Call the system
	jc		error			; Check for error
	ret

error:
	mov		rax, -1	; Return -1
	ret