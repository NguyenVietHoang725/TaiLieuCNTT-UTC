.model small
.stack 100h
.data

a1 db ?                          ; Bi?n luu s? th?p ph�n
a2 db 16 dup('$')                ; M?ng luu chu?i nh? ph�n

s1 db 'Nhap vao mot so thap phan: $'    ; L?i nh?c nh?p
s2 db 'So nhi phan tuong ung la: $'     ; L?i nh?n k?t qu?
newline db 13, 10, '$'           ; Xu?ng d�ng

.code 
main proc 
    mov ax, @data
    mov ds, ax
    
    ; Hi?n th? s1
    lea dx, s1
    mov ah, 9
    int 21h      


    mov ah, 1
    int 21h
    sub al, '0'
    mov a1, al                   ; Luu s? v�o bi?n a1

    ; Kh?i t?o cho vi?c chuy?n d?i sang nh? ph�n
    mov bl, 2                    ; Chia cho 2
    mov al, a1                   ; L?y gi� tr? t? a1 d? chia
    xor cx, cx                   ; �?m s? bit luu trong cx (s? bit nh? ph�n)

chiatiep:
    xor ah, ah                   ; X�a ah d? chu?n b? chia
    div bl                       ; Chia cho 2, ph?n du n?m trong ah
    add ah, '0'                  ; Chuy?n ph?n du th�nh k� t? ('0' ho?c '1')
    push ax                      ; �?y ph?n du v�o stack
    inc cx                       ; Tang b? d?m bit
    cmp al, 0                    ; Ki?m tra n?u thuong b?ng 0
    jne chiatiep                 ; N?u thuong kh�c 0, ti?p t?c chia

hienso:  
    ; Hi?n th? s2
    lea dx, newline
    mov ah, 9
    int 21h

    lea dx, s2
    mov ah, 9
    int 21h

intiep:    
    pop ax                       ; L?y ph?n du t? stack (nh? ph�n t? du?i l�n)
    mov dl, ah                   ; L?y ph?n du t? ah
    mov ah, 2   
    int 21h                      ; In k� t?
    loop intiep                  ; L?p l?i cho d?n khi cx = 0

    ; K?t th�c chuong tr�nh
    mov ah, 4ch
    int 21h
main endp
end main
