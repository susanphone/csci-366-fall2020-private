        global    find_max
        section   .text
find_max:

        array: db rdi;; rdi has the array in it
        length: dw rsi;; rsi has the length in it
        mov rax, DATA;; move the first value in the array into rax
        mov DS, rax
        lea rdi, array;; you will need to loop through the array and
        mov AL, array,SI;;
        mov large, AL;;
        mov CX, length;;
        mov AL, array,SI;;
        cmp large, AL;;
        sub rdi, 2;; after the comparison, decrement the count, bump the
        jge maxloop;; and if the counter is greater than zero, loop
        ret