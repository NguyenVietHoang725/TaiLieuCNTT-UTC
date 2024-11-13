.model small
.stack 100h

.data
    s1 db 'nhap day: $'
    s2 db 10, 13, 'chuyen chu hoa: $'
    s  db 100 dup(?)

.code
    main proc           
        mov ax, @data
        mov ds, ax
        
        ; Hien thi chuoi "nhap day: "
        mov ah, 9
        lea dx, s1
        int 21h
        
        ; Vong lap nhap ki tu
        mov bx, 0
nhaptiep:        
        mov ah, 1
        int 21h            ; Doc mot ki tu tu ban phim va luu vao al
        cmp al, 13         ; Kiem tra neu ki tu la Enter thi nhay den "hienday:"
        je hienday         ; Neu la Enter thi nhay den "hienday:"
        mov s(bx), al      ; Luu ki tu vao 's' tai vi tri bx
        inc bx             ; Tang bx de tro den o nho tiep theo
        jmp nhaptiep
hienday:
        ; Hien thi thong bao "
        mov ah, 9
        lea dx, s2
        int 21h
        
        mov cx, bx
        
        mov bx, 0
doitiep:   
        cmp s(bx), 'a'
        jge doichuhoa 
        jmp khongdoi
        
doichuhoa:     
        sub s(bx), 32
khongdoi:        
        inc bx
        loop doitiep
        
        mov s(bx), '$'
        mov ah, 9
        lea dx, s
        int 21h
        
        mov ah, 4Ch
        int 21h
        
    main endp
end main
