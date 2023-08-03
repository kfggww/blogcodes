#ifndef INIT_H
#define INIT_H

typedef int (*initcall_t)(void);

#define ___define_initcall(fn, id, __sec) \
    static initcall_t __initcall##id##_##fn __attribute__((section(#__sec ".init"))) = fn

#define __define_initcall(fn, id) ___define_initcall(fn, id, .initcall##id)

#define core_initcall(fn) __define_initcall(fn, 1)
#define postcore_initcall(fn) __define_initcall(fn, 2)

#endif