; Chuong trinh nhap mot ky tu, sau do in ra ky tu truoc va sau ky tu vua nhap
.MODEL small
.STACK 100h
.DATA
    tb1     db  "Vui long nhap 1 ky tu: $"
    tb2     db  10,13, "Ky tu lien truoc la: $"     
    tb3     db  10,13, "Ky tu lien sau la: $"
     
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
        mov bl, al
        
        ; xuat ky tu lien truoc
        mov ah, 9
        lea dx, tb2
        int 21h
                
        mov ah, 2
        mov dl, bl
        sub dl, 1   ; hoac su dung: dec dl  
        int 21h  
        
        ; xuat ky tu lien sau
        mov ah, 9
        lea dx, tb3
        int 21h
        
        mov ah, 2
        mov dl, bl
        add dl, 1   ; hoac su dung: add dl 
        int 21h
        
        mov ah, 4ch
        int 21h
        endp main
    end main
    
        