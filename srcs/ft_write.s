section	.text
global	ft_write
extern	__errno_location

ft_write:					; RDI, RSI, RDX - RAX
	test	rdx, rdx		; Check for negative length
	js		.error			;
	mov		rax, 1			; Write Call # (Linux)
;	mov		rax, 0x2000004	; Write Call # (BSD)
	syscall					; Call the system
	test	rax, rax		; Check for error (Linux)
	js		.error
;	jc		.error			; Check for error (BSD)
	ret
.error:
	mov		rdx, rax		; Get error code
	neg		rdx
	call	__errno_location wrt ..plt; Get errno pointer
	mov		[rax], rdx		; Set errno to error code
	mov		rax, -1			; Return -1
	ret
