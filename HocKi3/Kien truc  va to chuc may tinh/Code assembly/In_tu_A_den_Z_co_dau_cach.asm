.model small
.stack 100h
.data
    
    
.code
    main proc
        mov ax, @data
        mov ds, ax  
        
        mov ah, 2
        mov dl,'A'
intiep:     
        int 21h
        mov dh,dl
        mov dl,' '
        int 21h
        mov dl, dh
        add dl,1
        cmp dl, 'Z'
        jle intiep
    
kt:    
        ;kt
        mov ah,4ch
        int 21h
    main endp
end main