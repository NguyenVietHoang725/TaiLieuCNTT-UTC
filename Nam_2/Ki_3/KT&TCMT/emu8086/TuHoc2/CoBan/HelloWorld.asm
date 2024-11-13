; Chuong trinh hien thi xau "Hello World"
.MODEL small
.STACK 100h
.DATA
    tb1 db  'Hello World!$'
.CODE 
    main proc 
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, tb1
        int 21h  
        
        mov ah, 4ch
        int 21h
        endp main
    end main
    
        