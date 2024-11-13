; Chuong trinh nhap mot ky tu tu ban phim va xuat ra man hinh ky tu vua nhap
.MODEL small
.STACK 100h
.DATA
    tb1     db  "Vui long nhap ky tu: $"
    tb2     db  10,13, "Ky tu vua nhap la: $"
    output  db  ?  
.CODE 
    main proc 
        mov ax, @data
        mov ds, ax
        
        ; thong bao nhap
        mov ah, 9
        lea dx, tb1
        int 21h
        
        ; nhap ky tu
        mov ah, 1
        int 21h
        mov output, al
        
        ; thong bao xuat
        mov ah, 9
        lea dx, tb2
        int 21h
        
        ; xuat ky tu
        mov ah, 2
        mov dl, output
        int 21h  
        
        mov ah, 4ch
        int 21h
        endp main
    end main
    
        