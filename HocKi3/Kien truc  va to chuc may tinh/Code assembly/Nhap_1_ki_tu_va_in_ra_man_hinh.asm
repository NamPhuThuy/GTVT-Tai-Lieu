.model small
.stack 100h
.data
    Tbao1 db "Hay nhap mot ki tu:$"
    Tbao2 db 0DH, 0AH, "Ky tu da nhap la: $"
    KyTu db ?

.code
    main proc
        mov ax, @data
        mov ds, ax  
        
        ;thong bao nhap
        
        lea dx, Tbao1
        mov ah, 9  
        int 21h
        
        ; Nhap ki tu
        mov ah, 1
        int 21h
        mov KyTu, al 
        
        ; Thong bao ket qua
        lea dx, Tbao2
        mov ah, 9
        int 21h
        
        ; hien ki tu
        mov ah, 2
        mov dl, KyTu
        int 21h
        
        ; ket thuc
        mov ah, 4ch
        int 21h
        
    main endp
end main
        
        
        



