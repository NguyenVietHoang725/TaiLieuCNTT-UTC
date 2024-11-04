.model small
.stack 100h
.data
    s1 db 'nhap a: $'
    s2 db 10, 13, 'nhap b: $'
    s3 db 10, 13, 'a = b $'
    s4 db 10, 13, 'a > b $'
    s5 db 10, 13, 'a < b $'  
    a db ?
    b db ?
    
.code 
main proc
    mov ah, 9
    lea dx, s1
    int 21h
    
    mov ah, 1
    int 21h
    sub al, '0'      
    mov a, al      

    mov ah, 9
    lea dx, s2
    int 21h
    
    mov ah, 1
    int 21h
    sub al, '0'     
    mov b, al       


    mov al, a
    cmp al, b
    je Equal       
    ja Greater     
    jl Less         

Equal:
    mov ah, 9
    lea dx, s3
    int 21h
    jmp Exit

Greater:
    mov ah, 9
    lea dx, s4
    int 21h
    jmp Exit

Less:
    mov ah, 9
    lea dx, s5
    int 21h
    jmp Exit

Exit:   
    mov ax, 4C00h
    int 21h

main endp
end main
