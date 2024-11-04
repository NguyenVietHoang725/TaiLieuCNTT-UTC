.MODEL small
.STACK 100h
.DATA

    tb1 db 'Nhap mot ky tu: $'
    tb2 db 10, 13, 'Ky tu vua nhap la: $'

.CODE  
    main proc
        
        mov ah, 9
        lea dx, tb1
        int 21h
        
        mov ah, 1
        mov bl, ah 
        
        mov ah, 9
        lea dx, tb2
        int 21h    
        
        mov ah, bl
        int 21h
              
        
                
        main endp
    end main