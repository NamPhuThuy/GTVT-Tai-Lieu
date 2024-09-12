.model small
.stack 100h
.data
    s1  db  'n = $'
    s2  db  10, 13, 's = $'
    n   db  0
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov bl, 10
        mov ah, 9
        lea dx, s1
        int 21h
nhaptiep:        
        mov ah, 1
        int 21h
        cmp al, 13
        je thoat
        sub al, 48
        mov bh, al
        mov al, n   ; so cu
        mul bl      ; so * 10
        add al, bh  ; so * 10 + bh
        mov n, al
        jmp nhaptiep
thoat:        
        
        mov bl, n
        
        mov ah, 9
        lea dx, s2
        int 21h
        
        mov al, bl
        mov cl, 0
        mov bl, 10
chiatiep:
        mov ah, 0
        div bl
        push ax
        add cl, 1
        cmp al, 0
        jne  chiatiep
        mov ch, 0
inso:        
        mov ah, 2
        pop dx
        mov dl, dh
        add dl, 48
        int 21h
        loop inso
        
        
        
        mov ah, 4ch
        int 21h
    main endp
end main