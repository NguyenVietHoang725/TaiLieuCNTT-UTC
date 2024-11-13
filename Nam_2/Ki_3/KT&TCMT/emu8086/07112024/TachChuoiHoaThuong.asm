.model small
.stack 100h

.data
    s1 db 'nhap day: $'
    s2 db 10, 13, 'tach chu hoa: $'
    s3 db 10, 13, 'tach chu thuong :$' 
    s  db 100 dup(?)  
    hoa db 100 dup(?)
    thuong db 100 dup(?)

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
        mov si, 0
        mov di, 0
doitiep:        
        cmp s(bx), 'a' 
        jle chuhoa
        mov dl, s(bx)
        mov thuong(si), dl
        inc si
        jmp tiep
chuhoa: 
        mov dl, s(bx)   
        mov hoa(di), dl
        inc di
tiep:   
             
        loop doitiep 
        
        mov ah, 9
        lea dx, s2
        int 21h
        
        mov ah, 9
        mov hoa(si), '$'
        lea dx, hoa
        int 21h 
        
        lea dx, s3
        int 21h
        mov thuong(di), '$'
        lea dx, thuong
        int 21h
        
        
        mov ah, 4Ch
        int 21h
        
    main endp
end main
