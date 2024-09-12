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
        
        mov ah, 9
        lea dx, s1
        int 21h
        
        mov ah, 1
        int 21h
        sub al, 48
        mov n, al
        
        mov cl, 1   ; i = 1
        mov al, 0   ; s = 0
congtiep:        
        add al, cl  ; s = s + i
        add cl, 1   ; i = i + 1
        cmp cl, n
        jbe congtiep
        
        mov bl, al
        
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
inso:        
        mov ah, 2
        pop dx
        mov dl, dh
        add dl, 48
        int 21h
        sub cl, 1
        cmp cl, 0
        jg inso
        
        
        
        mov ah, 4ch
        int 21h
    main endp
end main