; je label  -> jump if equal
; jne label -> jump if not equal
; jz label  -> jump if zero
; jnz label -> jump if not zero
; ja label  -> jump if above
; jna label -> jump if not above
; jg label  -> jump if greater than
; jng label -> jump if not greater than
; jb label  -> jump if below
; jnb label -> jump if not below
; jl label  -> jump if less than
; jnl label -> jump if not less than

; jmp label -> jump to everywhere    

; loop label : nap so lan lap vao thanh ghi cx  

.MODEL small
.STACK 100h
.DATA

.CODE  

    ProgramStart:        
    
    mov cx, 10
back:
    mov ah, 2
    mov dl, 'A'
    int 21h    
    loop back
    
    End ProgramStart