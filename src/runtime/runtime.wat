(module
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

  (func $main
    i32.const 32423    ;; 'A' in ASCII
    call $printi
  )
  (start $main)
)
