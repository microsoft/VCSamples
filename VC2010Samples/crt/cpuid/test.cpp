#include <stdio.h>
#include "cpuid.h"

void expand(int avail, int mask)
{
    if (mask & _CPU_FEATURE_MMX) {
        printf("\t%s\t_CPU_FEATURE_MMX\n",
               avail & _CPU_FEATURE_MMX ? "yes" : "no");
    }
    if (mask & _CPU_FEATURE_SSE) {
        printf("\t%s\t_CPU_FEATURE_SSE\n",
               avail & _CPU_FEATURE_SSE ? "yes" : "no");
    }
    if (mask & _CPU_FEATURE_SSE2) {
        printf("\t%s\t_CPU_FEATURE_SSE2\n",
               avail & _CPU_FEATURE_SSE2 ? "yes" : "no");
    }
    if (mask & _CPU_FEATURE_3DNOW) {
        printf("\t%s\t_CPU_FEATURE_3DNOW\n",
               avail & _CPU_FEATURE_3DNOW ? "yes" : "no");
    }
}

void main(void)
{
    _p_info info;

    _cpuid(&info);

    printf("v_name:\t\t%s\n", info.v_name);
    printf("model:\t\t%s\n", info.model_name);
    printf("family:\t\t%d\n", info.family);
    printf("model:\t\t%d\n", info.model);
    printf("stepping:\t%d\n", info.stepping);
    printf("feature:\t%08x\n", info.feature);
    expand(info.feature, info.checks);
    printf("os_support:\t%08x\n", info.os_support);
    expand(info.os_support, info.checks);
    printf("checks:\t\t%08x\n", info.checks);
}
