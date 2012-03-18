USING: formatting kernel math io kernel math.parser shuffle ;
IN: factorial-example

: count ( x x -- x x )
    ! 2dup "count %d %d\n" printf

    dup
    5 <
    [ ]
    [ swap 1 +
      swap 5 /

      dup 5 rem
      0 = [ ] [ drop 4 ] if

      count ]
    if
    ! 2dup "res count %d %d\n" printf
    ;
 

: factorial ( x x x -- x x x )
    ! 3dup "main %d %d %d\n" printf

    2dup
    <
    [ ]
    [ 
      dup
      5
      rem

      ! dup "rem: %d\n" printf

      0 =
      [ ! 0 25 5
        swap  ! 0 5 25
        spin  ! 25 5 0
        swap  ! 25 0 5

        dup ! 25 0 5 5
        0 ! 25 0 5 5 0
        swap ! 25 0 5 0 5

        count ! 25 0 5 1 1

      ! 2dup "after count %d %d \n" printf

        drop ! 25 0 5 1

        swap ! 25 0 1 5

        spin ! 25 5 1 0
        + ! 25 5 1
        spin
        swap

        ! 3dup "+count %d %d %d\n" printf
      ] [ ]
      if

      1 +

      factorial
    ]
    if ;

0
readln string>number
2
factorial
drop
drop
"%d\n" printf
