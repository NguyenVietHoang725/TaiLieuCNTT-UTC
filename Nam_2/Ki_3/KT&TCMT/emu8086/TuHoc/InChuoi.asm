.model small
.stack 100h
.data
     newline    db  13, 10,'$'  ; Ky tu xuong dong
     s1         db  'hello!$'
     s2         db  'xin chao!$'
.code
    main proc  
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, s1
        int 21h
        
        lea dx, newline
        int 21h
        
        lea dx, s2
        int 21h
        
        mov ah, 4ch
        int 21h
    main endp
end
        