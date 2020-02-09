section	.text
global	_ft_read

_ft_read:					; RDI, RSI, RDX
	test	rdx, rdx		; Check for negative length
	js		error			;
	mov		rax, 0x2000003	; Read Call #
	syscall					; Call the system
	jc		error			; Check for error
	ret

error:
	mov		rax, -1	; Return -1
	ret