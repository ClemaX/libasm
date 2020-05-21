section	.text
global	ft_write
extern	__error

ft_write:					; RDI, RSI, RDX - RAX
	test	rdx, rdx		; Check for negative length
	js		.fail			;
	mov		rax, 0x2000004	; Write Call #
	syscall					; Call the system
	mov		rdx, rax		; Get error code
	jc		.error			; Check for error (BSD)
	ret
.error:
	sub		rsp, 8			; Align stack to 16 bytes
	call	__error			; Get errno pointer
	mov		[rax], rdx		; Set errno to error code
	add		rsp, 8			; Restore alignment
.fail:
	mov		rax, -1			; Return -1
	ret
