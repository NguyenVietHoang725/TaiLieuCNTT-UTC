.MODEL small
.STACK 100h
.DATA

.CODE  
    main proc
        
        
        mov ah, 2
        mov dl, 'A'
back:
        int 21h
        
        mov bl, dl   ; cat tam ky tu  vao thanh ghi bl
        mov dl, 32   ; dat ky tu ' ' vao thanh ghi dl
        int 21h
        
        mov dl, bl   ; tra lai ky tu chu vao thanh ghi dl
        
        inc dl
        cmp dl, 'Z'
        jle back
        
        mov ah, 4ch
        int 21h       
        
                
        main endp
    end main