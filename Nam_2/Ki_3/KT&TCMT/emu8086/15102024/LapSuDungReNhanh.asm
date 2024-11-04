.MODEL small
.STACK 100h
.DATA

.CODE  
    main proc
        
        
        mov cx, 10
back:        
        mov ah, 2    ; Ham DOS in ky tu
        mov dl, 'A'
        int 21h  
        
        dec cx       ; Giam gia tri cua cx
        cmp cx, 0    ; SO sanh gia tri cua cx voi 0
        jne back     ; Neu khong bang 0, nhay ve nhan 'back'
        
        mov ah, 4ch  ; Ham DOS de thoat chuong trinh
        int 21h        
        
                
        main endp
    end main