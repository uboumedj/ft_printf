# 42 algorithmic project: ft_printf

This project is basically a re-coding of the well-known C function: **printf**. 

## Working flags and conversions

* The **%s, %S, %c, %C, %d, %D, %i, %o, %u, %U, %x, %X, %p** and **%%** conversions are all usable in my ft_printf.

* The **hh**, **h**, **l**, **ll**, **#**, **0**, **-**, **+**, **&ast;** and **space** flags are usable.

* **Minimum field-width** and **precision** as used in the original printf are also obviously usable.

* As a bonus, I created a **%b** conversion that outputs in binary mode.

The included Makefile compiles my **ft_printf** and my **libft** together to create a new library called **libftprintf.a**.
