.model small
.stack 100h
.data   
    s1 db 'Nhap mot ky tu: $'
    s2 db 10, 13, 'Ky tu truoc la: $'     
    s3 db 10, 13, 'Ky tu vua nhap la: $'
    s4 db 10, 13, 'Ky ty sau la: $'
    
.code
    main proc   
        
       ; Thiet lap doan du lieu
       mov ax, @data
       mov ds, ax
       
       ; Hien thi chuoi yeu cau nhap ky tu
       mov ah, 9
       lea dx, s1
       int 21h
       
       ; Nhap ky tu tu nguoi dung
       mov ah, 1
       int 21h
       mov bl, al      ; Luu ky tu vua nhap vao thanh ghi bl
       
       ; Hien thi ky tu truoc
       mov ah, 9
       lea dx, s2
       int 21h
       dec al          ; Giam gia tri ASCII de co ky tu truoc do
       mov dl, al
       mov ah, 2
       int 21h         ; Hien thi ky tu truoc
       
       ; Hien thi ky tu vua nhap
       mov ah, 9
       lea dx, s3
       int 21h
       mov dl, bl      ; PPhuc hoi lai ky tu vua nhap
       mov ah, 2
       int 21h         ; Hien thi ky tu vua nhap
       
       ; Hien thi ky tu sau
       mov ah, 9
       lea dx, s4
       int 21h
       inc bl          ; Tang gia tri ASCII de co ky tu sau do
       mov dl, bl
       mov ah, 2
       int 21h         ; Hien thi ky tu sau
       
       ; Ket thuc chuong trinh
       mov ah, 4ch
       int 21h
        
        main endp
    end main