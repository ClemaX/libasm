section	.text
global	ft_write
extern	__error

ft_write:					; RDI, RSI, RDX - RAX
	test	rdx, rdx		; Check for negative length
	js		.error			;
	mov		rax, 0x2000004	; Write Call #
	syscall					; Call the system
	mov		rdx, rax		; Get error code
	jc		.error			; Check for error (BSD)
	ret
.error:
	call	__error			; Get errno pointer
	mov		[rax], rdx		; Set errno to error code
	mov		rax, -1			; Return -1
	ret
