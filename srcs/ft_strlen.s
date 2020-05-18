section	.text
global	ft_strlen

ft_strlen:				; RDI - RAX, RCX
	sub		rcx, rcx	; Clear RCX
	not		rcx			; Set RCX to unsigned-max
	sub		al, al		; Clear AL
	cld					; Clear DF / go forward
	repne	scasb		; Scan byte-string
	not		rcx			; Invert bits on RCX
	dec		rcx			; Decrement RCX
	mov		rax, rcx	; Set RAX to RCX
	ret					; Return
