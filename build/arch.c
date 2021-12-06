
#if defined(__arm__) || defined(__TARGET_ARCH_ARM) || defined(_M_ARM)
    #if defined(__ARM64_ARCH_8__)
        #error cmake_ARCH armv8
    #elif defined(__aarch64__)
        #error cmake_ARCH arm64
    #elif defined(__ARM_ARCH_7__) \
        || defined(__ARM_ARCH_7A__) \
        || defined(__ARM_ARCH_7R__) \
        || defined(__ARM_ARCH_7M__) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM-0 >= 7)
        #error cmake_ARCH armv7
    #elif defined(__ARM_ARCH_7S__)
        #error cmake_ARCH armv7s
    #elif defined(__ARM_ARCH_6__) \
        || defined(__ARM_ARCH_6J__) \
        || defined(__ARM_ARCH_6T2__) \
        || defined(__ARM_ARCH_6Z__) \
        || defined(__ARM_ARCH_6K__) \
        || defined(__ARM_ARCH_6ZK__) \
        || defined(__ARM_ARCH_6M__) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM-0 >= 6)
        #error cmake_ARCH armv6
    #elif defined(__ARM_ARCH_5TEJ__) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM-0 >= 5)
        #error cmake_ARCH armv5
    #else
        #error cmake_ARCH arm32
    #endif
#elif defined(__i386) || defined(__i386__) || defined(_M_IX86)
    #error cmake_ARCH i386
#elif defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(_M_X64)
    #error cmake_ARCH x86_64
#elif defined(__ia64) || defined(__ia64__) || defined(_M_IA64)
    #error cmake_ARCH ia64
#elif defined(__ppc__) || defined(__ppc) || defined(__powerpc__) \
      || defined(_ARCH_COM) || defined(_ARCH_PWR) || defined(_ARCH_PPC)  \
      || defined(_M_MPPC) || defined(_M_PPC)
    #if defined(__ppc64__) || defined(__powerpc64__) || defined(__64BIT__)
        #error cmake_ARCH ppc64
    #else
        #error cmake_ARCH ppc
    #endif
#elif defined(__mips__) || defined(__mips)
    #if defined(__LP64__) || defined(_LP64)
        #error cmake_ARCH mips64
    #else
        #error cmake_ARCH mips32
    #endif
#elif defined(__sparc__)
    #if defined(__LP64__) || defined(_LP64)
        #error cmake_ARCH sparc64
    #else
        #error cmake_ARCH sparc32
    #endif
#elif defined(__alpha__)
    #error cmake_ARCH alpha
#elif defined(__hppa__) || defined(__hppa)
    #error cmake_ARCH hppa
#elif defined(__m68k__)
    #error cmake_ARCH m68k
#elif defined(__sh__)
    #error cmake_ARCH sh
#elif defined(__s390x__)
    #error cmake_ARCH s390x
#elif defined(__s390__)
    #error cmake_ARCH s390
#endif

#error cmake_ARCH unknown
