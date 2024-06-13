section .data
  SPACE db ' '

section .bss
	buf: resb 2000000
	outbuf: resb 2000000

section .text
    global _start
    
_start:
	call readint
	loop:
	  mov r10, rax
	  xor r12,r12
	  jmp int_to_str
	  back:
	  cmp r10, 1
	  je exit
	  mov rax, r10
	  test rax, 1
	  jnz odd
    shr rax, 1
    jmp end
	  odd:
	    lea rax, [rax*3+1]
	  end:
	    jmp loop

int_to_str:
	mov rdx, 0
	mov rbx, 10
	div rbx ;; rax /= rbx
	add rdx, 48 ;; remainder is stored in rdx
	push rdx ;; push char to stack
	inc r12 ;; inc char count
	cmp rax, 0
	jne int_to_str
	jmp print

print:
	mov rsi, rsp
	printChar:
	mov rax, 1
	mov rdi, 1
	mov rdx, 1
	syscall
	add rsi, 8
	dec r12
	cmp r12, 0
	jnz printChar
	call printSpace
	jmp back

printSpace:
  mov rax, 1
  mov rdi, 1
  mov rsi, SPACE
  mov rdx, 1
  syscall
  ret

readint:
  mov rbx, buf ;; point rbx to buffer
	xor rdi, rdi ;; fildes 0 = stdin
	mov rsi, rbx ;; buffer
	mov rdx, 32 ;; size
	syscall
	xor rax, rax
	.loop:
		movzx rcx, byte [rbx] ;; faster mov, eliminates dependency on rcx
		cmp cl, 48 ;; byte 0 of rcx; 48 = '0'
		jl .end
		shl rax, 1 ;; rax = 2 * rax
		lea rax, [rax+rax*4-48] ;; rax = 5 * rax - 48 in a single instruction
		add rax, rcx ;; rax has been mul'd by 10, next digit is added
		add rbx, 1 ;; next char in buffer
		jmp .loop
	.end:
	add rbx, 1
	ret

exit:
    mov    rax, 60
    mov    rdi, 0
    syscall