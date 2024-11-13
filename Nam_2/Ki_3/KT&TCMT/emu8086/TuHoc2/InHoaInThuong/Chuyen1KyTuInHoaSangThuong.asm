; Chuong trinh chuyen ky tu thuong thanh ky tu in hoa
.MODEL small
.STACK 100h
.DATA
    tb1     db  "Vui long nhap 1 ky tu in hoa: $"
    tb2     db  10,13, "Chuyen sang ky tu thuong la: $"
    output  db  ?, '$'
     
.CODE 
    main proc 
        mov ax, @data
        mov ds, ax
        
        ; thong bao nhap
        mov ah, 9
        lea dx, tb1
        int 21h
        
        ; nhap va chuyen in thuong
        mov ah, 1
        int 21h    
        add al, 32      ; cong di 32 de co ky tu thuong tuong ung trong bang ma ASCII
        mov output, al
        
        ; thong bao xuat
        mov ah, 9
        lea dx, tb2
        int 21h
        
        ; xuat
        mov ah, 2
        mov dl, output  
        int 21h
        
        mov ah, 4ch
        int 21h
        endp main
    end main
    
        