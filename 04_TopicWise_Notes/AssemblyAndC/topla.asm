section .data

section .text

global Topla

Topla:
	PUSH EBP
	PUSH EDI
	PUSH ECX
	MOV EBP, ESP
	MOV EDI, [EBP + 16]  ; Dizinin adresine erişilir.
	MOV ECX, [EBP + 20]  ; Dizinin boyutu olan n değerine erişilir
	XOR EAX, EAX

L1:	ADD EAX, [EDI]
	ADD EDI, 4
	LOOP L1
	POP ECX
	POP EDI
	POP EBP
	RET

; C removes the argumanets from the stack
; First compile this asm file, nasm -f elf32 -o ornek1.o ornek1.asm
; gcc –m32 ornek1.c ornek1.o -o combine_casm 
