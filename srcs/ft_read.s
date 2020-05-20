%ifidn __OUTPUT_FORMAT__, elf64
	%assign READ_CALL 0
	%macro JERR 1
		test	rax, rax	; Check for error (Linux)
		js		%1
	%endmacro
%elifidn __OUTPUT_FORMAT__, macho64
	%assign READ_CALL 0x2000003
	%macro JERR 1
		jc		%1			; Check for error (BSD)
	%endmacro
%endif

section	.text
global	ft_read
extern	__errno_location

ft_read:					; RDI, RSI, RDX
	test	rdx, rdx		; Check for negative length
	js		.error			;
	mov		rax, READ_CALL	; Read Call #
	syscall					; Call the system
	JERR	.error
	ret
.error:
	mov		rdx, rax		; Get error code
	neg		rdx
	call	__errno_location wrt ..plt; Get errno pointer
	mov		[rax], rdx		; Set errno to error code
	mov		rax, -1			; Return -1
	ret
