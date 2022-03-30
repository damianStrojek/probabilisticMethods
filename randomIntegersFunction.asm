public random

.data
znakM dd 01111111111111111111111111111111b

.code
random PROC
	push rbx
	push rsi
	push rdi

	mov rbx, rdx
	xor rdx, rdx
	mov edx, znakM
	mov r9, rdx
	xor rdx, rdx
	; RCX = prev, RBX = A, R8 = C, R9 = M

	xor rax, rax
	xor rdx, rdx

	mov rax, rcx
	mul rbx
	add rax, r8
	div r9
	mov rax, rdx

	pop rdi
	pop rsi
	pop rbx
	ret
random ENDP
END