; ham 2ch, ngat 21h : lay thoi gian
; ch : gio, cl : phut, dh : giay, dl, : %giay
.model small
.stack 100h
.data
     s db '00:00:00$'
   ; s db 100 dup(?)
    .code
    main proc
        mov ax, @data
        mov ds, ax  
        
        mov ah, 2ch
        int 21h
        
        mov bl, 10
        mov al, ch
        mov ah, 0
        div bl
        
        add al, 48
        add ah, 48
        mov s, al
        mov s+1, ah
        
        mov bl, 10
        mov al, cl
        mov ah, 0
        div bl
        
        add al, 48
        add ah, 48
        mov s+3, al
        mov s+4, ah  
        
         mov bl, 10
        mov al, dh
        mov ah, 0
        div bl
        
        add al, 48
        add ah, 48
        mov s+6, al
        mov s+7, ah
        
        mov ah, 9
        lea dx, s
        int 21h
        
        mov ah, 4ch
        int 21h
        
        main endp
    end main