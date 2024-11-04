.MODEL small
.STACK 100h
.DATA

.CODE  
    main proc
        
        
        mov cx, 26      
        mov ah, 2    ; Ham DOS in ky tu
        mov dl, 'A'  ; Dat ky tu 'A' vao thanh ghi dl     
inkytu:        
        int 21h      ; Ngat va in ky tu hien tai trong thanh dl
        inc dl       ; Tang gia tri trong thanh dl len 1          
        
        loop inkytu
        
        mov ah, 4ch  ; Ham DOS de thoat chuong trinh
        int 21h        
        
                
        main endp
    end main