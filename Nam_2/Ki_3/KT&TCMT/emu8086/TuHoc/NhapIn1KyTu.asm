.model small
.stack 100h
.data
     s1 db          "Hay nhap mot ky tu: $" ; Xau thong bao 1
     s2 db  13,10,  "Ky tu da nhap: $"      ; Xau thong bao 2                    
     s3 db          ?                       ; Bien ky tu khong co gia tri ban dau
.code
    main proc  
        mov ax, @data
        mov ds, ax
        
        ; In ra man hinh xau s1 
        mov ah, 9
        lea dx, s1
        int 21h
        
        ; Nhap 1 ky tu tu ban phim
        mov ah, 1
        int 21h
        mov s3, al
        
        ; In ra man hinh xau s2
        mov ah, 9
        lea dx, s2
        int 21h
        
        ; Hien thi ky tu da nhap
        mov ah, 2
        mov dl, s3
        int 21h
        
        mov ah, 4ch
        int 21h
        
        
    main endp
end
        