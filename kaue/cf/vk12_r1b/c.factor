USING: formatting kernel math io kernel math.parser shuffle ;
IN: factorial-example

: factorial ( x x x -- x x x )
    ! 2dup "%d, %d\n" printf

    2dup
    <
    [ ]
    [ 
      2dup
      rem
      ! dup "rem: %d\n" printf
      0 =
      [
        3dup
        drop
        drop
        0 =
        [
          spin
          1 +
          spin
        ] [ "*" printf ]
        if

        dup "%d" printf
        swap
        2dup
        swap
        /
        swap
        drop
        swap
      ]
      [ 1 + ]
      if

      factorial
    ]
    if ;

0
readln string>number
2
factorial
drop
drop
drop
"\n" printf
