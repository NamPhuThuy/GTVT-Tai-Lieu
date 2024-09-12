.model small
.stack 100h
.data
    s1 db 'n = $'
    s2 db 10,13, 's = $'   
    n db 123
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov bl, 10
        mov al, n 
        mov cl,0  ;dem
chiatiep:        
        mov ah,0
        div bl    ;ax/bl <0123/10>
        cmp al, 0
        je thoat
        push ax   ;cat vao stack
        add cl,1  ;tang dem  
        jmp chiatiep
thoat:
        push ax
        add cl,1
intiep:        
        mov ah, 2
        pop dx
        mov dl,dh
        add dl,48
        int 21h
        sub cl,1
        ja intiep       
       
kt:    
        mov ah,4ch
        int 21h
    main endp
end main