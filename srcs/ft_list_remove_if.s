section	.text
;void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
global	_ft_list_remove_if		; RDI, RSI, RDX, RCX

extern	_free

_ft_list_remove_if:
	mov		r12,	rdi			; Set R12 to RDI
	mov		r13,	[r12]		; Set R13 to list pointer
.start:
	test	r13,	r13			; Check for NULL
	jz		.end				; End on NULL
	mov		rdi,	[r13]		; Set RDI to data pointer
	call	rdx					; cmp(RDI, RSI)
	test	eax,	eax			; Check for match
	jnz		.loop				; Continue loop if no match
	call	rcx					; free_fct(RDI)
	mov		rdi,	r13			; Set RDI to list pointer
	mov		r13,	[r13 + 8]	; Set R13 to next pointer
	call	_free				; free(RDI)
	mov		[r12],	r13			; Set *R12 to next pointer
	jmp		.start				; Loop on next pointer
.loop:
	mov		r14,	[r13 + 8]	; Set R14 to next pointer
	mov		rdi,	[r14]		; Set RDI to data pointer
	call	rdx					; cmp(RDI, RSI)
	test	eax,	eax			; Check for match
	jz		.delete				; Delete if matching
	mov		r13,	r14			; Set R13 to list pointer
	test	r14,	r14			; Check for NULL
	jnz		.loop				; End on NULL
.end:
	ret
.delete:
	call	rcx					; free_fct(RDI)
	mov		rdi,	r14			; Set RDI to list pointer
	mov		r14,	[r14 + 8]	; Set R14 to next pointer
	call	_free
	mov		[r13 + 8], r14		; Set previous next pointer to R14
	jmp		.loop				; Continue loop