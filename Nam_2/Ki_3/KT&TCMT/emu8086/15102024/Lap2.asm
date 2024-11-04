.MODEL small
.STACK 100h
.DATA

.CODE  
    main proc
        
        
        mov cl, 1
back:        
        mov ah, 2    ; Ham DOS in ky tu
        mov dl, 'A'
        int 21h    
        
        mov dl, ' '
        int 21h
        
        inc cl       ; Giam gia tri cua cx
        cmp cl, 10    ; SO sanh gia tri cua cx voi 0
        jg exit     ; Neu khong lon hon 10, nhay ve nhan 'back'
        jmp back
exit:        
        mov ah, 4ch  ; Ham DOS de thoat chuong trinh
        int 21h        
        
                
        main endp
    end main