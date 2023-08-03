#include <stdio.h>
#include "init.h"

int module_init_fn1(void)
{
    printf("%s: is called\n", __func__);
    return 0;
}

int module_init_fn2(void)
{
    printf("%s: is called\n", __func__);
    return 0;
}

int module_init_fn3(void)
{
    printf("%s: is called\n", __func__);
    return 0;
}

extern initcall_t __initcall_start[];
extern initcall_t __initcall1_start[];
extern initcall_t __initcall2_start[];
extern initcall_t __initcall_end[];

static initcall_t *initcalls[] = {
    __initcall_start,
    __initcall1_start,
    __initcall2_start,
    __initcall_end,
};

void do_initcall_level(int level)
{
    for (initcall_t *fn = initcalls[level]; fn < initcalls[level + 1]; fn++)
    {
        (*fn)();
    }
}
__attribute__((constructor)) void do_initcalls(void)
{
    printf("call initcalls of level 1\n");
    do_initcall_level(1);

    printf("\n\ncall initcalls of level 2\n");
    do_initcall_level(2);
}

int main(int argc, char **argv)
{
    return 0;
}

core_initcall(module_init_fn1);
postcore_initcall(module_init_fn2);
postcore_initcall(module_init_fn3);