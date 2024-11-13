; ham 2ch, ngat 21h : lay ngay thang
; al: thu (0: SUN, 1: MON, ..., 6: SAT)
; dl: ngay (0-31), dh: thang (0-12)
;cx: nam (1980-2099)
.model small
.stack 100h
.data
     ngay       db ?
     thang      db ?
     nam        dw ?    
     chunhat    db 'Chu Nhat$'
     thuhai     db 'Thu Hai$'    
     thuba      db 'Thu Ba$'
     thutu      db 'Thu Tu$'
     thunam     db 'Thu Nam$'
     thusau     db 'Thu Sau$'
     thubay     db 'Thu Bay$'
     
   ; s db 100 dup(?)
    .code
    main proc
        mov ax, @data
        mov ds, ax  
        
        mov ah, 2ch
        int 21h
        
        mov ngay, dl
        mov thang, dh
        mov nam, cx    
        
        cmp al, 0
        je SUN
        cmp al, 1
        je MON
        cmp al, 2
        je TUE 
        cmp al, 3
        je WED
        cmp al, 4
        je THU
        cmp al, 5
        je FRI
        cmp al, 6
        je SAT
        
SUN:
    mov ah, 9
    lea dx, chunhat
    int 21h  
    jmp hienngay
MON: 
    mov ah, 9
    lea dx, thuhai
    int 21h 
    jmp hienngay
TUE:
    mov ah, 9
    lea dx, thuba
    int 21h    
    jmp hienngay 
WED:
    mov ah, 9
    lea dx, thutu
    int 21h    
    jmp hienngay
THU:
    mov ah, 9
    lea dx, thunam
    int 21h    
    jmp hienngay
FRI:
    mov ah, 9
    lea dx, thusau
    int 21h    
    jmp hienngay
SAT:
    mov ah, 9
    lea dx, thubay
    int 21h    
    jmp hienngay
        
hienngay:      
        mov ah, 4ch
        int 21h
        
        main endp    
    end main