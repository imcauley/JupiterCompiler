;; (module   
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
  (func $prints (param $string_index i32) (param $string_offeset i32)
    (local $string_counter i32)
    (local.get $string_index)
    (local.set $string_counter)

    (block $B
      (loop $L
      (local.get $string_counter)
      (local.get $string_offeset)
      (i32.eq)
      br_if $B

      (local.get $string_counter)
      (i32.load)
      (call $putchar)

      (i32.const 1)
      (local.get $string_counter)
      (i32.add)
      (local.set $string_counter)

      br $L
      )
    )
  )
  (func $halt
    call $exit
  )


;;   (func $main
;;     (i32.const 0)
;;     (i32.const 6)
;;     call $prints
;;   )
;;   (start $main)

;;   (data (i32.const 0) "hello\n")
;;   (memory 5)
;; )