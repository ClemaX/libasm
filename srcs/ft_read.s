section	.text
global	ft_read

ft_read:					; RDI, RSI, RDX
	test	rdx, rdx		; Check for negative length
	js		error			;
	mov		rax, 0			; Read Call # (Linux)
;	mov		rax, 0x2000003	; Read Call # (BSD)
	syscall					; Call the system
	jc		error			; Check for error
	ret

error:
	mov		rax, -1	; Return -1
	ret
