#ifndef _INC_CPUID
#define _INC_CPUID

#define _CPU_FEATURE_MMX    0x0001
#define _CPU_FEATURE_SSE    0x0002
#define _CPU_FEATURE_SSE2   0x0004
#define _CPU_FEATURE_3DNOW  0x0008

#define _MAX_VNAME_LEN  13
#define _MAX_MNAME_LEN  30

typedef struct _processor_info {
    char v_name[_MAX_VNAME_LEN];        // vendor name
    char model_name[_MAX_MNAME_LEN];    // name of model
                                        // e.g. Intel Pentium-Pro
    int family;                         // family of the processor
                                        // e.g. 6 = Pentium-Pro architecture
    int model;                          // model of processor
                                        // e.g. 1 = Pentium-Pro for family = 6
    int stepping;                       // processor revision number
    int feature;                        // processor feature
                                        // (same as return value from _cpuid)
    int os_support;                     // does OS Support the feature?
    int checks;                         // mask of checked bits in feature
                                        // and os_support fields
} _p_info;

#ifdef __cplusplus
extern "C"
#endif
int _cpuid (_p_info *);

#endif
