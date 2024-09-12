.model small
.stack 100h
.data
    s1 db 'n = $'
    s2 db 10,13, 's = $'   
    n db 0
.code
    main proc
        mov ax, @data
        mov ds, ax  
        
        mov ah,9 
        lea dx,s1
        int 21h
        
        mov ah, 1
        int 21h
        sub al, 48  ;doi thanh so
        mov n, al
        
        mov ah,9
        lea dx,s2
        int 21h
        
        mov bl, 0  ;s = 0
        mov cl, 1  ;i  = 1          
congtiep:
        add bl, cl ;s = s + i
        add cl,1 ;i = i + 1
        cmp cl, n
        jbe congtiep
        ;jg thoat
        ;jmp congtiep
;thoat:  
        mov ah,2
        mov dl, bl
        add dl, 48
        int 21h
kt:    
        mov ah,4ch
        int 21h
    main endp
end main