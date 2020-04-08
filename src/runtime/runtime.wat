  (import "host" "exit" (func $exit))
  (import "host" "getchar" (func $getchar (result i32)))
  (import "host" "putchar" (func $putchar (param i32)))

  (func $printi (param $num i32)
    (local.get $num)
    (i32.const 0)
    i32.ne
    if
        (local.get $num)
        (i32.const 10)
        i32.div_u
        call $printi

        (local.get $num)
        (i32.const 10)
        i32.rem_u

        i32.const 48
        i32.add 
        call $putchar
    end

  )
  (func $printb (param $bool i32) 
    (local.get $bool)
    i32.eqz
    if
      i32.const 116
      call $putchar
      i32.const 114
      call $putchar
      i32.const 117
      call $putchar
      i32.const 101
      call $putchar
    else
      i32.const 102
      call $putchar
      i32.const 97
      call $putchar
      i32.const 108
      call $putchar
      i32.const 115
      call $putchar
      i32.const 101
      call $putchar
    end
  )
  (func $printc (param $char i32)
    (local.get $char)
    call $putchar
  )
  (func $halt
    call $exit
  )

  ;; TODO add print string function

  ;; (func $main
  ;;   i32.const 0    ;; 'A' in ASCII
  ;;   call $printb
  ;; )
  ;; (start $main)
