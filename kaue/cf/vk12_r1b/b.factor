USING: formatting kernel math io kernel math.parser ;
IN: factorial-example

: factorial ( n -- n! )
    dup
    1 <
    [ 1 ]
    [ 
      dup dup

      dup even?
      [ 0 swap ]
      [ 1 swap 1 - ]
      if

      2 /

      factorial
      drop
      "%d" printf ]
    if
    ! swap over "%d! = %d\n" printf ;
    drop ; 

readln string>number
factorial
drop
"\n" printf
