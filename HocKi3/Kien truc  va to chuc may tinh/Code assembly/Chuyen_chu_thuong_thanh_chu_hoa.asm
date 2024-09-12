.model small
.stack 100h
.data
    s1 db "Nhap chu thuong: $"
    s2 db 10, 13, "Chu hoa tuong ung: $"
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        ;hien s1
        mov ah, 9
        lea dx, s1
        int 21h
        
        ;Nhap ki tu 
        mov ah, 1
        int 21h
        mov bl, al
        
        ;Hien s2
        mov ah, 9
        lea dx, s2
        int 21h
        
        ;Convert to upper case
        sub bl, 32
        mov dl, bl
        
        ;Hien ki tu
        mov ah, 2 ;In ky tu tu thanh ghi dl
        int 21h
        
        mov ah, 4ch
        int 21h
    main endp
end main