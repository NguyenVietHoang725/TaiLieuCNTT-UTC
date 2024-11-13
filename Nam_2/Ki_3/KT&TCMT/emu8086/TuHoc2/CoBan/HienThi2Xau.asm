; Chuong trinh hien thi hai xau "Hello!" va "My name is David." tren hai dong khac nhau
.MODEL small
.STACK 100h
.DATA
    s1  db  "Hello!$"
    s2  db  10, 13, "My name is David.$" 
.CODE 
    main proc 
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, s1
        int 21h
        
        lea dx, s2
        int 21h  
        
        mov ah, 4ch
        int 21h
        endp main
    end main
    
        