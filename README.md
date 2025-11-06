# fe
A *tiny*, embeddable language implemented in ANSI C

```clojure
(= reverse (fn (lst)
  (let res nil)
  (while lst
    (= res (cons (car lst) res))
    (= lst (cdr lst))
  )
  res
))

(= animals '("cat" "dog" "fox"))

(print (reverse animals)) ; => ("fox" "dog" "cat")
```

## Overview
* Single-Header library — just include `fe.h`, define FE_IMPLEMENTATION and you ready to go
* Easy to use C API
* Small memory usage within a fixed-sized memory region — no mallocs
* Portable C11 — works on 32 and 64bit
* Supports numbers, symbols, strings, pairs, lambdas, macros
* Lexically scoped variables, closures
* Simple mark and sweep garbage collector
* Concise — less than 1000 sloc
* Usable without libc (FE_NO_STD but needs to have some functions)

---

* **[Examples](examples)**
* **[C API Overview](doc/capi.md)**
* **[Language Overview](doc/lang.md)**
* **[Implementation Overview](doc/impl.md)**


## Contributing
The library focuses on being lightweight and minimal; Bug reports and questions are welcome.


## License
This library is free software; you can redistribute it and/or modify it under
the terms of the MIT license. See [LICENSE](LICENSE) for details.
