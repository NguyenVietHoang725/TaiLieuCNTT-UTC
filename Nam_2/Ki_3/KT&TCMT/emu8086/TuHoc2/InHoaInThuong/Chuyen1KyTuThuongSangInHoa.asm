; Chuong trinh chuyen ky tu thuong thanh ky tu in hoa
.MODEL small
.STACK 100h
.DATA
    tb1     db  "Vui long nhap 1 ky tu thuong: $"
    tb2     db  10,13, "Chuyen sang ky tu in hoa la: $"
    output  db  ?, '$'
     
.CODE 
    main proc 
        mov ax, @data
        mov ds, ax
        
        ; thong bao nhap
        mov ah, 9
        lea dx, tb1
        int 21h
        
        ; nhap va chuyen in hoa
        mov ah, 1
        int 21h    
        sub al, 32      ; tru di 32 de co ky tu in hoa tuong ung trong bang ma ASCII
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
    
        