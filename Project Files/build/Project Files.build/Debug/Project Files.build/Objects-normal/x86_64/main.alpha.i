# 1 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c"
# 1 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 139 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c" 2
# 10 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c"
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 1 3 4
# 64 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/_types.h" 1 3 4
# 27 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/_types.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_types.h" 1 3 4
# 32 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_types.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/cdefs.h" 1 3 4
# 33 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_types.h" 2 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/_types.h" 1 3 4
# 34 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/_types.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/_types.h" 1 3 4
# 37 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/_types.h" 3 4
typedef signed char __int8_t;



typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
# 70 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/_types.h" 3 4
typedef int __darwin_ct_rune_t;





typedef union {
 char __mbstate8[128];
 long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;


typedef long int __darwin_ptrdiff_t;





typedef long unsigned int __darwin_size_t;





typedef __builtin_va_list __darwin_va_list;





typedef int __darwin_wchar_t;




typedef __darwin_wchar_t __darwin_rune_t;


typedef int __darwin_wint_t;




typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;
# 35 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/_types.h" 2 3 4
# 34 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_types.h" 2 3 4
# 58 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_types.h" 3 4
struct __darwin_pthread_handler_rec
{
 void (*__routine)(void *);
 void *__arg;
 struct __darwin_pthread_handler_rec *__next;
};
struct _opaque_pthread_attr_t { long __sig; char __opaque[56]; };
struct _opaque_pthread_cond_t { long __sig; char __opaque[40]; };
struct _opaque_pthread_condattr_t { long __sig; char __opaque[8]; };
struct _opaque_pthread_mutex_t { long __sig; char __opaque[56]; };
struct _opaque_pthread_mutexattr_t { long __sig; char __opaque[8]; };
struct _opaque_pthread_once_t { long __sig; char __opaque[8]; };
struct _opaque_pthread_rwlock_t { long __sig; char __opaque[192]; };
struct _opaque_pthread_rwlockattr_t { long __sig; char __opaque[16]; };
struct _opaque_pthread_t { long __sig; struct __darwin_pthread_handler_rec *__cleanup_stack; char __opaque[1168]; };
# 94 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_types.h" 3 4
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;



typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef struct _opaque_pthread_attr_t
   __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t
   __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t
   __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t
   __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t
   __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t
   __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t
   __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t
   __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t
   *__darwin_pthread_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];
# 28 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/_types.h" 2 3 4
# 39 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/_types.h" 3 4
typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;
# 65 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 2 3 4





typedef __darwin_va_list va_list;




typedef __darwin_off_t off_t;




typedef __darwin_size_t size_t;






typedef __darwin_off_t fpos_t;
# 98 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 3 4
struct __sbuf {
 unsigned char *_base;
 int _size;
};


struct __sFILEX;
# 132 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 3 4
typedef struct __sFILE {
 unsigned char *_p;
 int _r;
 int _w;
 short _flags;
 short _file;
 struct __sbuf _bf;
 int _lbfsize;


 void *_cookie;
 int (*_close)(void *);
 int (*_read) (void *, char *, int);
 fpos_t (*_seek) (void *, fpos_t, int);
 int (*_write)(void *, const char *, int);


 struct __sbuf _ub;
 struct __sFILEX *_extra;
 int _ur;


 unsigned char _ubuf[3];
 unsigned char _nbuf[1];


 struct __sbuf _lb;


 int _blksize;
 fpos_t _offset;
} FILE;



extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;
# 249 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 3 4
void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE * restrict, fpos_t *);
char *fgets(char * restrict, int, FILE *);



FILE *fopen(const char * restrict, const char * restrict) __asm("_" "fopen" );

int fprintf(FILE * restrict, const char * restrict, ...) ;
int fputc(int, FILE *);
int fputs(const char * restrict, FILE * restrict) __asm("_" "fputs" );
size_t fread(void * restrict, size_t, size_t, FILE * restrict);
FILE *freopen(const char * restrict, const char * restrict,
     FILE * restrict) __asm("_" "freopen" );
int fscanf(FILE * restrict, const char * restrict, ...) ;
int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void * restrict, size_t, size_t, FILE * restrict) __asm("_" "fwrite" );
int getc(FILE *);
int getchar(void);
char *gets(char *);

extern const int sys_nerr;
extern const char *const sys_errlist[];

void perror(const char *);
int printf(const char * restrict, ...) ;
int putc(int, FILE *);
int putchar(int);
int puts(const char *);
int remove(const char *);
int rename (const char *, const char *);
void rewind(FILE *);
int scanf(const char * restrict, ...) ;
void setbuf(FILE * restrict, char * restrict);
int setvbuf(FILE * restrict, char * restrict, int, size_t);
int sprintf(char * restrict, const char * restrict, ...) ;
int sscanf(const char * restrict, const char * restrict, ...) ;
FILE *tmpfile(void);
char *tmpnam(char *);
int ungetc(int, FILE *);
int vfprintf(FILE * restrict, const char * restrict, va_list) ;
int vprintf(const char * restrict, va_list) ;
int vsprintf(char * restrict, const char * restrict, va_list) ;

int asprintf(char **, const char *, ...) ;
int vasprintf(char **, const char *, va_list) ;
# 312 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 3 4
char *ctermid(char *);

char *ctermid_r(char *);




FILE *fdopen(int, const char *) __asm("_" "fdopen" );


char *fgetln(FILE *, size_t *);

int fileno(FILE *);
void flockfile(FILE *);

const char
 *fmtcheck(const char *, const char *);
int fpurge(FILE *);

int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);

int getw(FILE *);

int pclose(FILE *);



FILE *popen(const char *, const char *) __asm("_" "popen" );

int putc_unlocked(int, FILE *);
int putchar_unlocked(int);

int putw(int, FILE *);
void setbuffer(FILE *, char *, int);
int setlinebuf(FILE *);

int snprintf(char * restrict, size_t, const char * restrict, ...) ;
char *tempnam(const char *, const char *) __asm("_" "tempnam" );
int vfscanf(FILE * restrict, const char * restrict, va_list) ;
int vscanf(const char * restrict, va_list) ;
int vsnprintf(char * restrict, size_t, const char * restrict, va_list) ;
int vsscanf(const char * restrict, const char * restrict, va_list) ;

FILE *zopen(const char *, const char *, int);
# 369 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 3 4
FILE *funopen(const void *,
  int (*)(void *, char *, int),
  int (*)(void *, const char *, int),
  fpos_t (*)(void *, fpos_t, int),
  int (*)(void *));
# 384 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 3 4
int __srget(FILE *);
int __svfscanf(FILE *, const char *, va_list) ;
int __swbuf(int, FILE *);
# 395 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 3 4
static __inline int __sputc(int _c, FILE *_p) {
 if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
  return (*_p->_p++ = _c);
 else
  return (__swbuf(_c, _p));
}
# 443 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/secure/_stdio.h" 1 3 4
# 31 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/secure/_stdio.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/secure/_common.h" 1 3 4
# 32 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/secure/_stdio.h" 2 3 4
# 42 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/secure/_stdio.h" 3 4
extern int __sprintf_chk (char * restrict, int, size_t,
     const char * restrict, ...)
                                      ;




extern int __snprintf_chk (char * restrict, size_t, int, size_t,
      const char * restrict, ...)
                                       ;




extern int __vsprintf_chk (char * restrict, int, size_t,
      const char * restrict, va_list)
                                       ;




extern int __vsnprintf_chk (char * restrict, size_t, int, size_t,
       const char * restrict, va_list)
                                        ;
# 444 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdio.h" 2 3 4
# 11 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c" 2
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/time.h" 1 3 4
# 69 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/time.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/_structs.h" 1 3 4
# 24 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/_structs.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 1 3 4
# 88 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 3 4
struct timespec
{
 __darwin_time_t tv_sec;
 long tv_nsec;
};
# 25 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/_structs.h" 2 3 4
# 70 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/time.h" 2 3 4







typedef __darwin_clock_t clock_t;
# 87 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/time.h" 3 4
typedef __darwin_time_t time_t;


struct tm {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
 long tm_gmtoff;
 char *tm_zone;
};
# 113 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/time.h" 3 4
extern char *tzname[];


extern int getdate_err;

extern long timezone __asm("_" "timezone" );

extern int daylight;


char *asctime(const struct tm *);
clock_t clock(void) __asm("_" "clock" );
char *ctime(const time_t *);
double difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *localtime(const time_t *);
time_t mktime(struct tm *) __asm("_" "mktime" );
size_t strftime(char * restrict, size_t, const char * restrict, const struct tm * restrict) __asm("_" "strftime" );
char *strptime(const char * restrict, const char * restrict, struct tm * restrict) __asm("_" "strptime" );
time_t time(time_t *);


void tzset(void);



char *asctime_r(const struct tm * restrict, char * restrict);
char *ctime_r(const time_t *, char *);
struct tm *gmtime_r(const time_t * restrict, struct tm * restrict);
struct tm *localtime_r(const time_t * restrict, struct tm * restrict);


time_t posix2time(time_t);



void tzsetwall(void);
time_t time2posix(time_t);
time_t timelocal(struct tm * const);
time_t timegm(struct tm * const);



int nanosleep(const struct timespec *, struct timespec *) __asm("_" "nanosleep" );
# 12 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c" 2
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdlib.h" 1 3 4
# 61 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdlib.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/Availability.h" 1 3 4
# 126 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/Availability.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/AvailabilityInternal.h" 1 3 4
# 127 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/Availability.h" 2 3 4
# 62 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdlib.h" 2 3 4



# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/wait.h" 1 3 4
# 79 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/wait.h" 3 4
typedef enum {
 P_ALL,
 P_PID,
 P_PGID
} idtype_t;






typedef __darwin_pid_t pid_t;




typedef __darwin_id_t id_t;
# 116 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/wait.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 1 3 4
# 73 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/appleapiopts.h" 1 3 4
# 74 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 2 3 4







# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/signal.h" 1 3 4
# 34 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/signal.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/signal.h" 1 3 4
# 39 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/signal.h" 3 4
typedef int sig_atomic_t;
# 55 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/signal.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/_structs.h" 1 3 4
# 56 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/signal.h" 2 3 4
# 35 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/signal.h" 2 3 4
# 82 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 2 3 4
# 154 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 1 3 4
# 57 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/_structs.h" 1 3 4
# 31 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/_structs.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/_structs.h" 1 3 4
# 38 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/_structs.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 1 3 4
# 43 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_i386_thread_state
{
    unsigned int __eax;
    unsigned int __ebx;
    unsigned int __ecx;
    unsigned int __edx;
    unsigned int __edi;
    unsigned int __esi;
    unsigned int __ebp;
    unsigned int __esp;
    unsigned int __ss;
    unsigned int __eflags;
    unsigned int __eip;
    unsigned int __cs;
    unsigned int __ds;
    unsigned int __es;
    unsigned int __fs;
    unsigned int __gs;
};
# 89 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_fp_control
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
      :2,
    __pc :2,





    __rc :2,






             :1,
      :3;
};
typedef struct __darwin_fp_control __darwin_fp_control_t;
# 147 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_fp_status
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
    __stkflt :1,
    __errsumm :1,
    __c0 :1,
    __c1 :1,
    __c2 :1,
    __tos :3,
    __c3 :1,
    __busy :1;
};
typedef struct __darwin_fp_status __darwin_fp_status_t;
# 191 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_mmst_reg
{
 char __mmst_reg[10];
 char __mmst_rsrv[6];
};
# 210 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_xmm_reg
{
 char __xmm_reg[16];
};
# 232 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_i386_float_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
};
# 308 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_i386_exception_state
{
    unsigned int __trapno;
    unsigned int __err;
    unsigned int __faultvaddr;
};
# 326 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_x86_debug_state32
{
 unsigned int __dr0;
 unsigned int __dr1;
 unsigned int __dr2;
 unsigned int __dr3;
 unsigned int __dr4;
 unsigned int __dr5;
 unsigned int __dr6;
 unsigned int __dr7;
};
# 358 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_x86_thread_state64
{
 __uint64_t __rax;
 __uint64_t __rbx;
 __uint64_t __rcx;
 __uint64_t __rdx;
 __uint64_t __rdi;
 __uint64_t __rsi;
 __uint64_t __rbp;
 __uint64_t __rsp;
 __uint64_t __r8;
 __uint64_t __r9;
 __uint64_t __r10;
 __uint64_t __r11;
 __uint64_t __r12;
 __uint64_t __r13;
 __uint64_t __r14;
 __uint64_t __r15;
 __uint64_t __rip;
 __uint64_t __rflags;
 __uint64_t __cs;
 __uint64_t __fs;
 __uint64_t __gs;
};
# 413 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_x86_float_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
};
# 517 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_x86_exception_state64
{
    unsigned int __trapno;
    unsigned int __err;
    __uint64_t __faultvaddr;
};
# 535 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/mach/i386/_structs.h" 3 4
struct __darwin_x86_debug_state64
{
 __uint64_t __dr0;
 __uint64_t __dr1;
 __uint64_t __dr2;
 __uint64_t __dr3;
 __uint64_t __dr4;
 __uint64_t __dr5;
 __uint64_t __dr6;
 __uint64_t __dr7;
};
# 39 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/_structs.h" 2 3 4
# 48 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/_structs.h" 3 4
struct __darwin_mcontext32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_float_state __fs;
};
# 68 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/_structs.h" 3 4
struct __darwin_mcontext64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_float_state64 __fs;
};
# 91 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/_structs.h" 3 4
typedef struct __darwin_mcontext64 *mcontext_t;
# 32 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/_structs.h" 2 3 4
# 58 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 2 3 4
# 75 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 3 4
struct __darwin_sigaltstack
{
 void *ss_sp;
 __darwin_size_t ss_size;
 int ss_flags;
};
# 128 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 3 4
struct __darwin_ucontext
{
 int uc_onstack;
 __darwin_sigset_t uc_sigmask;
 struct __darwin_sigaltstack uc_stack;
 struct __darwin_ucontext *uc_link;
 __darwin_size_t uc_mcsize;
 struct __darwin_mcontext64 *uc_mcontext;



};
# 218 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 3 4
typedef struct __darwin_sigaltstack stack_t;
# 227 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 3 4
typedef struct __darwin_ucontext ucontext_t;
# 155 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 2 3 4








typedef __darwin_pthread_attr_t pthread_attr_t;




typedef __darwin_sigset_t sigset_t;
# 178 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 3 4
typedef __darwin_uid_t uid_t;


union sigval {

 int sival_int;
 void *sival_ptr;
};





struct sigevent {
 int sigev_notify;
 int sigev_signo;
 union sigval sigev_value;
 void (*sigev_notify_function)(union sigval);
 pthread_attr_t *sigev_notify_attributes;
};


typedef struct __siginfo {
 int si_signo;
 int si_errno;
 int si_code;
 pid_t si_pid;
 uid_t si_uid;
 int si_status;
 void *si_addr;
 union sigval si_value;
 long si_band;
 unsigned long __pad[7];
} siginfo_t;
# 292 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 3 4
union __sigaction_u {
 void (*__sa_handler)(int);
 void (*__sa_sigaction)(int, struct __siginfo *,
         void *);
};


struct __sigaction {
 union __sigaction_u __sigaction_u;
 void (*sa_tramp)(void *, int, int, siginfo_t *, void *);
 sigset_t sa_mask;
 int sa_flags;
};




struct sigaction {
 union __sigaction_u __sigaction_u;
 sigset_t sa_mask;
 int sa_flags;
};
# 354 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 3 4
typedef void (*sig_t)(int);
# 371 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 3 4
struct sigvec {
 void (*sv_handler)(int);
 int sv_mask;
 int sv_flags;
};
# 390 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 3 4
struct sigstack {
 char *ss_sp;
 int ss_onstack;
};
# 413 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/signal.h" 3 4
void (*signal(int, void (*)(int)))(int);
# 117 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/wait.h" 2 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/resource.h" 1 3 4
# 76 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/resource.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 1 3 4
# 100 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_structs.h" 3 4
struct timeval
{
 __darwin_time_t tv_sec;
 __darwin_suseconds_t tv_usec;
};
# 77 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/resource.h" 2 3 4
# 88 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/resource.h" 3 4
typedef __uint64_t rlim_t;
# 144 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/resource.h" 3 4
struct rusage {
 struct timeval ru_utime;
 struct timeval ru_stime;
# 155 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/resource.h" 3 4
 long ru_maxrss;

 long ru_ixrss;
 long ru_idrss;
 long ru_isrss;
 long ru_minflt;
 long ru_majflt;
 long ru_nswap;
 long ru_inblock;
 long ru_oublock;
 long ru_msgsnd;
 long ru_msgrcv;
 long ru_nsignals;
 long ru_nvcsw;
 long ru_nivcsw;


};
# 215 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/resource.h" 3 4
struct rlimit {
 rlim_t rlim_cur;
 rlim_t rlim_max;
};
# 238 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/resource.h" 3 4
int getpriority(int, id_t);

int getiopolicy_np(int, int);

int getrlimit(int, struct rlimit *) __asm("_" "getrlimit" );
int getrusage(int, struct rusage *);
int setpriority(int, id_t, int);

int setiopolicy_np(int, int, int);

int setrlimit(int, const struct rlimit *) __asm("_" "setrlimit" );
# 118 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/wait.h" 2 3 4
# 193 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/wait.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/endian.h" 1 3 4
# 37 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/endian.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/endian.h" 1 3 4
# 99 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/endian.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_endian.h" 1 3 4
# 124 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_endian.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/libkern/_OSByteOrder.h" 1 3 4
# 66 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/libkern/_OSByteOrder.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/libkern/i386/_OSByteOrder.h" 1 3 4
# 44 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/libkern/i386/_OSByteOrder.h" 3 4
static inline
__uint16_t
_OSSwapInt16(
    __uint16_t _data
)
{
    return ((_data << 8) | (_data >> 8));
}

static inline
__uint32_t
_OSSwapInt32(
    __uint32_t _data
)
{

    return __builtin_bswap32(_data);




}


static inline
__uint64_t
_OSSwapInt64(
    __uint64_t _data
)
{
    return __builtin_bswap64(_data);
}
# 67 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/libkern/_OSByteOrder.h" 2 3 4
# 125 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/_endian.h" 2 3 4
# 100 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/endian.h" 2 3 4
# 38 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/endian.h" 2 3 4
# 194 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/wait.h" 2 3 4







union wait {
 int w_status;



 struct {

  unsigned int w_Termsig:7,
    w_Coredump:1,
    w_Retcode:8,
    w_Filler:16;







 } w_T;





 struct {

  unsigned int w_Stopval:8,
    w_Stopsig:8,
    w_Filler:16;






 } w_S;
};
# 255 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/sys/wait.h" 3 4
pid_t wait(int *) __asm("_" "wait" );
pid_t waitpid(pid_t, int *, int) __asm("_" "waitpid" );

int waitid(idtype_t, id_t, siginfo_t *, int) __asm("_" "waitid" );


pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);
# 66 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdlib.h" 2 3 4

# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/alloca.h" 1 3 4
# 36 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/alloca.h" 3 4
void *alloca(size_t);
# 68 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdlib.h" 2 3 4
# 81 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdlib.h" 3 4
typedef __darwin_ct_rune_t ct_rune_t;




typedef __darwin_rune_t rune_t;






typedef __darwin_wchar_t wchar_t;



typedef struct {
 int quot;
 int rem;
} div_t;

typedef struct {
 long quot;
 long rem;
} ldiv_t;


typedef struct {
 long long quot;
 long long rem;
} lldiv_t;
# 134 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdlib.h" 3 4
extern int __mb_cur_max;
# 145 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdlib.h" 3 4
void abort(void) __attribute__((__noreturn__));
int abs(int) __attribute__((__const__));
int atexit(void (*)(void));
double atof(const char *);
int atoi(const char *);
long atol(const char *);

long long
  atoll(const char *);

void *bsearch(const void *, const void *, size_t,
     size_t, int (*)(const void *, const void *));
void *calloc(size_t, size_t);
div_t div(int, int) __attribute__((__const__));
void exit(int) __attribute__((__noreturn__));
void free(void *);
char *getenv(const char *);
long labs(long) __attribute__((__const__));
ldiv_t ldiv(long, long) __attribute__((__const__));

long long
  llabs(long long);
lldiv_t lldiv(long long, long long);

void *malloc(size_t);
int mblen(const char *, size_t);
size_t mbstowcs(wchar_t * restrict , const char * restrict, size_t);
int mbtowc(wchar_t * restrict, const char * restrict, size_t);
int posix_memalign(void **, size_t, size_t);
void qsort(void *, size_t, size_t,
     int (*)(const void *, const void *));
int rand(void);
void *realloc(void *, size_t);
void srand(unsigned);
double strtod(const char *, char **) __asm("_" "strtod" );
float strtof(const char *, char **) __asm("_" "strtof" );
long strtol(const char *, char **, int);
long double
  strtold(const char *, char **) ;

long long
  strtoll(const char *, char **, int);

unsigned long
  strtoul(const char *, char **, int);

unsigned long long
  strtoull(const char *, char **, int);

int system(const char *) __asm("_" "system" );
size_t wcstombs(char * restrict, const wchar_t * restrict, size_t);
int wctomb(char *, wchar_t);


void _Exit(int) __attribute__((__noreturn__));
long a64l(const char *);
double drand48(void);
char *ecvt(double, int, int *restrict, int *restrict);
double erand48(unsigned short[3]);
char *fcvt(double, int, int *restrict, int *restrict);
char *gcvt(double, int, char *);
int getsubopt(char **, char * const *, char **);
int grantpt(int);

char *initstate(unsigned, char *, size_t);



long jrand48(unsigned short[3]);
char *l64a(long);
void lcong48(unsigned short[7]);
long lrand48(void);
char *mktemp(char *);
int mkstemp(char *);
long mrand48(void);
long nrand48(unsigned short[3]);
int posix_openpt(int);
char *ptsname(int);
int putenv(char *) __asm("_" "putenv" );
long random(void);
int rand_r(unsigned *);

char *realpath(const char * restrict, char * restrict) __asm("_" "realpath" "$DARWIN_EXTSN");



unsigned short
 *seed48(unsigned short[3]);
int setenv(const char *, const char *, int) __asm("_" "setenv" );

void setkey(const char *) __asm("_" "setkey" );



char *setstate(const char *);
void srand48(long);

void srandom(unsigned);



int unlockpt(int);

int unsetenv(const char *) __asm("_" "unsetenv" );







# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/types.h" 1 3 4
# 37 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/types.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/types.h" 1 3 4
# 78 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/i386/types.h" 3 4
typedef signed char int8_t;

typedef unsigned char u_int8_t;


typedef short int16_t;

typedef unsigned short u_int16_t;


typedef int int32_t;

typedef unsigned int u_int32_t;


typedef long long int64_t;

typedef unsigned long long u_int64_t;


typedef int64_t register_t;






typedef __darwin_intptr_t intptr_t;



typedef unsigned long uintptr_t;




typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;







typedef u_int64_t syscall_arg_t;
# 38 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/machine/types.h" 2 3 4
# 256 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/stdlib.h" 2 3 4


typedef __darwin_dev_t dev_t;




typedef __darwin_mode_t mode_t;



u_int32_t
  arc4random(void);
void arc4random_addrandom(unsigned char *dat, int datlen);
void arc4random_stir(void);

int atexit_b(void (^)(void));
void *bsearch_b(const void *, const void *, size_t,
     size_t, int (^)(const void *, const void *));



char *cgetcap(char *, const char *, int);
int cgetclose(void);
int cgetent(char **, char **, const char *);
int cgetfirst(char **, char **);
int cgetmatch(const char *, const char *);
int cgetnext(char **, char **);
int cgetnum(char *, const char *, long *);
int cgetset(const char *);
int cgetstr(char *, const char *, char **);
int cgetustr(char *, const char *, char **);

int daemon(int, int) __asm("_" "daemon" "$1050") __attribute__((deprecated,visibility("default")));
char *devname(dev_t, mode_t);
char *devname_r(dev_t, mode_t, char *buf, int len);
char *getbsize(int *, long *);
int getloadavg(double [], int);
const char
 *getprogname(void);

int heapsort(void *, size_t, size_t,
     int (*)(const void *, const void *));

int heapsort_b(void *, size_t, size_t,
     int (^)(const void *, const void *));

int mergesort(void *, size_t, size_t,
     int (*)(const void *, const void *));

int mergesort_b(void *, size_t, size_t,
     int (^)(const void *, const void *));

void psort(void *, size_t, size_t,
     int (*)(const void *, const void *));

void psort_b(void *, size_t, size_t,
     int (^)(const void *, const void *));

void psort_r(void *, size_t, size_t, void *,
     int (*)(void *, const void *, const void *));

void qsort_b(void *, size_t, size_t,
     int (^)(const void *, const void *));

void qsort_r(void *, size_t, size_t, void *,
     int (*)(void *, const void *, const void *));
int radixsort(const unsigned char **, int, const unsigned char *,
     unsigned);
void setprogname(const char *);
int sradixsort(const unsigned char **, int, const unsigned char *,
     unsigned);
void sranddev(void);
void srandomdev(void);
void *reallocf(void *, size_t);

long long
  strtoq(const char *, char **, int);
unsigned long long
  strtouq(const char *, char **, int);

extern char *suboptarg;
void *valloc(size_t);
# 13 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c" 2
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/string.h" 1 3 4
# 70 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/string.h" 3 4
typedef __darwin_ssize_t ssize_t;
# 81 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/string.h" 3 4
void *memchr(const void *, int, size_t);
int memcmp(const void *, const void *, size_t);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memset(void *, int, size_t);

char *stpcpy(char *, const char *);
char *strcasestr(const char *, const char *);

char *strcat(char *, const char *);
char *strchr(const char *, int);
int strcmp(const char *, const char *);
int strcoll(const char *, const char *);
char *strcpy(char *, const char *);
size_t strcspn(const char *, const char *);
char *strerror(int) __asm("_" "strerror" );
int strerror_r(int, char *, size_t);
size_t strlen(const char *);
char *strncat(char *, const char *, size_t);
int strncmp(const char *, const char *, size_t);
char *strncpy(char *, const char *, size_t);

char *strnstr(const char *, const char *, size_t);

char *strpbrk(const char *, const char *);
char *strrchr(const char *, int);
size_t strspn(const char *, const char *);
char *strstr(const char *, const char *);
char *strtok(char *, const char *);
size_t strxfrm(char *, const char *, size_t);



void *memccpy(void *, const void *, int, size_t);
char *strtok_r(char *, const char *, char **);
char *strdup(const char *);

int bcmp(const void *, const void *, size_t);
void bcopy(const void *, void *, size_t);
void bzero(void *, size_t);
int ffs(int);
int ffsl(long);
int fls(int);
int flsl(long);
char *index(const char *, int);
void memset_pattern4(void *, const void *, size_t);
void memset_pattern8(void *, const void *, size_t);
void memset_pattern16(void *, const void *, size_t);
char *rindex(const char *, int);
int strcasecmp(const char *, const char *);
size_t strlcat(char *, const char *, size_t);
size_t strlcpy(char *, const char *, size_t);
void strmode(int, char *);
int strncasecmp(const char *, const char *, size_t);
char *strsep(char **, const char *);
char *strsignal(int sig);
void swab(const void * restrict, void * restrict, ssize_t);
# 148 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/string.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/secure/_string.h" 1 3 4
# 55 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/secure/_string.h" 3 4
static __inline void *
__inline_memcpy_chk (void *__dest, const void *__src, size_t __len)
{
  return __builtin___memcpy_chk (__dest, __src, __len, __builtin_object_size (__dest, 0));
}






static __inline void *
__inline_memmove_chk (void *__dest, const void *__src, size_t __len)
{
  return __builtin___memmove_chk (__dest, __src, __len, __builtin_object_size (__dest, 0));
}






static __inline void *
__inline_memset_chk (void *__dest, int __val, size_t __len)
{
  return __builtin___memset_chk (__dest, __val, __len, __builtin_object_size (__dest, 0));
}






static __inline char *
__inline_strcpy_chk (char *restrict __dest, const char *restrict __src)
{
  return __builtin___strcpy_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}







static __inline char *
__inline_stpcpy_chk (char *__dest, const char *__src)
{
  return __builtin___stpcpy_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}







static __inline char *
__inline_strncpy_chk (char *restrict __dest, const char *restrict __src,
        size_t __len)
{
  return __builtin___strncpy_chk (__dest, __src, __len, __builtin_object_size (__dest, 2 > 1));
}






static __inline char *
__inline_strcat_chk (char *restrict __dest, const char *restrict __src)
{
  return __builtin___strcat_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}






static __inline char *
__inline_strncat_chk (char *restrict __dest, const char *restrict __src,
        size_t __len)
{
  return __builtin___strncat_chk (__dest, __src, __len, __builtin_object_size (__dest, 2 > 1));
}
# 149 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/string.h" 2 3 4
# 14 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c" 2
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/ctype.h" 1 3 4
# 69 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/ctype.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/runetype.h" 1 3 4
# 70 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/runetype.h" 3 4
typedef __darwin_wint_t wint_t;
# 81 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/runetype.h" 3 4
typedef struct {
 __darwin_rune_t __min;
 __darwin_rune_t __max;
 __darwin_rune_t __map;
 __uint32_t *__types;
} _RuneEntry;

typedef struct {
 int __nranges;
 _RuneEntry *__ranges;
} _RuneRange;

typedef struct {
 char __name[14];
 __uint32_t __mask;
} _RuneCharClass;

typedef struct {
 char __magic[8];
 char __encoding[32];

 __darwin_rune_t (*__sgetrune)(const char *, __darwin_size_t, char const **);
 int (*__sputrune)(__darwin_rune_t, char *, __darwin_size_t, char **);
 __darwin_rune_t __invalid_rune;

 __uint32_t __runetype[(1 <<8 )];
 __darwin_rune_t __maplower[(1 <<8 )];
 __darwin_rune_t __mapupper[(1 <<8 )];






 _RuneRange __runetype_ext;
 _RuneRange __maplower_ext;
 _RuneRange __mapupper_ext;

 void *__variable;
 int __variable_len;




 int __ncharclasses;
 _RuneCharClass *__charclasses;
} _RuneLocale;




extern _RuneLocale _DefaultRuneLocale;
extern _RuneLocale *_CurrentRuneLocale;
# 70 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/ctype.h" 2 3 4
# 146 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/ctype.h" 3 4
unsigned long ___runetype(__darwin_ct_rune_t);
__darwin_ct_rune_t ___tolower(__darwin_ct_rune_t);
__darwin_ct_rune_t ___toupper(__darwin_ct_rune_t);


static __inline int
isascii(int _c)
{
 return ((_c & ~0x7F) == 0);
}
# 165 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/ctype.h" 3 4
int __maskrune(__darwin_ct_rune_t, unsigned long);



static __inline int
__istype(__darwin_ct_rune_t _c, unsigned long _f)
{



 return (isascii(_c) ? !!(_DefaultRuneLocale.__runetype[_c] & _f)
  : !!__maskrune(_c, _f));

}

static __inline __darwin_ct_rune_t
__isctype(__darwin_ct_rune_t _c, unsigned long _f)
{



 return (_c < 0 || _c >= (1 <<8 )) ? 0 :
  !!(_DefaultRuneLocale.__runetype[_c] & _f);

}
# 205 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/ctype.h" 3 4
__darwin_ct_rune_t __toupper(__darwin_ct_rune_t);
__darwin_ct_rune_t __tolower(__darwin_ct_rune_t);



static __inline int
__wcwidth(__darwin_ct_rune_t _c)
{
 unsigned int _x;

 if (_c == 0)
  return (0);
 _x = (unsigned int)__maskrune(_c, 0xe0000000L|0x00040000L);
 if ((_x & 0xe0000000L) != 0)
  return ((_x & 0xe0000000L) >> 30);
 return ((_x & 0x00040000L) != 0 ? 1 : -1);
}






static __inline int
isalnum(int _c)
{
 return (__istype(_c, 0x00000100L|0x00000400L));
}

static __inline int
isalpha(int _c)
{
 return (__istype(_c, 0x00000100L));
}

static __inline int
isblank(int _c)
{
 return (__istype(_c, 0x00020000L));
}

static __inline int
iscntrl(int _c)
{
 return (__istype(_c, 0x00000200L));
}


static __inline int
isdigit(int _c)
{
 return (__isctype(_c, 0x00000400L));
}

static __inline int
isgraph(int _c)
{
 return (__istype(_c, 0x00000800L));
}

static __inline int
islower(int _c)
{
 return (__istype(_c, 0x00001000L));
}

static __inline int
isprint(int _c)
{
 return (__istype(_c, 0x00040000L));
}

static __inline int
ispunct(int _c)
{
 return (__istype(_c, 0x00002000L));
}

static __inline int
isspace(int _c)
{
 return (__istype(_c, 0x00004000L));
}

static __inline int
isupper(int _c)
{
 return (__istype(_c, 0x00008000L));
}


static __inline int
isxdigit(int _c)
{
 return (__isctype(_c, 0x00010000L));
}

static __inline int
toascii(int _c)
{
 return (_c & 0x7F);
}

static __inline int
tolower(int _c)
{
        return (__tolower(_c));
}

static __inline int
toupper(int _c)
{
        return (__toupper(_c));
}


static __inline int
digittoint(int _c)
{
 return (__maskrune(_c, 0x0F));
}

static __inline int
ishexnumber(int _c)
{
 return (__istype(_c, 0x00010000L));
}

static __inline int
isideogram(int _c)
{
 return (__istype(_c, 0x00080000L));
}

static __inline int
isnumber(int _c)
{
 return (__istype(_c, 0x00000400L));
}

static __inline int
isphonogram(int _c)
{
 return (__istype(_c, 0x00200000L));
}

static __inline int
isrune(int _c)
{
 return (__istype(_c, 0xFFFFFFF0L));
}

static __inline int
isspecial(int _c)
{
 return (__istype(_c, 0x00100000L));
}
# 15 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c" 2
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/math.h" 1 3 4
# 28 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/math.h" 3 4
# 1 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 1 3 4
# 49 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 3 4
 typedef float float_t;
 typedef double double_t;
# 108 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 3 4
extern unsigned int __math_errhandling ( void );
# 128 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 3 4
extern int __fpclassifyf(float );
extern int __fpclassifyd(double );
extern int __fpclassify (long double);
# 163 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 3 4
 static __inline__ int __inline_isfinitef (float ) __attribute__ ((always_inline));
 static __inline__ int __inline_isfinited (double ) __attribute__ ((always_inline));
 static __inline__ int __inline_isfinite (long double) __attribute__ ((always_inline));
 static __inline__ int __inline_isinff (float ) __attribute__ ((always_inline));
 static __inline__ int __inline_isinfd (double ) __attribute__ ((always_inline));
 static __inline__ int __inline_isinf (long double) __attribute__ ((always_inline));
 static __inline__ int __inline_isnanf (float ) __attribute__ ((always_inline));
 static __inline__ int __inline_isnand (double ) __attribute__ ((always_inline));
 static __inline__ int __inline_isnan (long double) __attribute__ ((always_inline));
 static __inline__ int __inline_isnormalf (float ) __attribute__ ((always_inline));
 static __inline__ int __inline_isnormald (double ) __attribute__ ((always_inline));
 static __inline__ int __inline_isnormal (long double) __attribute__ ((always_inline));
 static __inline__ int __inline_signbitf (float ) __attribute__ ((always_inline));
 static __inline__ int __inline_signbitd (double ) __attribute__ ((always_inline));
 static __inline__ int __inline_signbit (long double) __attribute__ ((always_inline));

 static __inline__ int __inline_isinff( float __x ) { return __builtin_fabsf(__x) == __builtin_inff(); }
 static __inline__ int __inline_isinfd( double __x ) { return __builtin_fabs(__x) == __builtin_inf(); }
 static __inline__ int __inline_isinf( long double __x ) { return __builtin_fabsl(__x) == __builtin_infl(); }
 static __inline__ int __inline_isfinitef( float __x ) { return __x == __x && __builtin_fabsf(__x) != __builtin_inff(); }
 static __inline__ int __inline_isfinited( double __x ) { return __x == __x && __builtin_fabs(__x) != __builtin_inf(); }
 static __inline__ int __inline_isfinite( long double __x ) { return __x == __x && __builtin_fabsl(__x) != __builtin_infl(); }
 static __inline__ int __inline_isnanf( float __x ) { return __x != __x; }
 static __inline__ int __inline_isnand( double __x ) { return __x != __x; }
 static __inline__ int __inline_isnan( long double __x ) { return __x != __x; }
 static __inline__ int __inline_signbitf( float __x ) { union{ float __f; unsigned int __u; }__u; __u.__f = __x; return (int)(__u.__u >> 31); }
 static __inline__ int __inline_signbitd( double __x ) { union{ double __f; unsigned int __u[2]; }__u; __u.__f = __x; return (int)(__u.__u[1] >> 31); }
 static __inline__ int __inline_signbit( long double __x ){ union{ long double __ld; struct{ unsigned int __m[2]; short __sexp; }__p; }__u; __u.__ld = __x; return (int) (((unsigned short) __u.__p.__sexp) >> 15); }
 static __inline__ int __inline_isnormalf( float __x ) { float fabsf = __builtin_fabsf(__x); if( __x != __x ) return 0; return fabsf < __builtin_inff() && fabsf >= 1.17549435e-38F; }
 static __inline__ int __inline_isnormald( double __x ) { double fabsf = __builtin_fabs(__x); if( __x != __x ) return 0; return fabsf < __builtin_inf() && fabsf >= 2.2250738585072014e-308; }
 static __inline__ int __inline_isnormal( long double __x ) { long double fabsf = __builtin_fabsl(__x); if( __x != __x ) return 0; return fabsf < __builtin_infl() && fabsf >= 3.36210314311209350626e-4932L; }
# 253 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 3 4
extern double acos( double );
extern float acosf( float );

extern double asin( double );
extern float asinf( float );

extern double atan( double );
extern float atanf( float );

extern double atan2( double, double );
extern float atan2f( float, float );

extern double cos( double );
extern float cosf( float );

extern double sin( double );
extern float sinf( float );

extern double tan( double );
extern float tanf( float );

extern double acosh( double );
extern float acoshf( float );

extern double asinh( double );
extern float asinhf( float );

extern double atanh( double );
extern float atanhf( float );

extern double cosh( double );
extern float coshf( float );

extern double sinh( double );
extern float sinhf( float );

extern double tanh( double );
extern float tanhf( float );

extern double exp ( double );
extern float expf ( float );

extern double exp2 ( double );
extern float exp2f ( float );

extern double expm1 ( double );
extern float expm1f ( float );

extern double log ( double );
extern float logf ( float );

extern double log10 ( double );
extern float log10f ( float );

extern double log2 ( double );
extern float log2f ( float );

extern double log1p ( double );
extern float log1pf ( float );

extern double logb ( double );
extern float logbf ( float );

extern double modf ( double, double * );
extern float modff ( float, float * );

extern double ldexp ( double, int );
extern float ldexpf ( float, int );

extern double frexp ( double, int * );
extern float frexpf ( float, int * );

extern int ilogb ( double );
extern int ilogbf ( float );

extern double scalbn ( double, int );
extern float scalbnf ( float, int );

extern double scalbln ( double, long int );
extern float scalblnf ( float, long int );

extern double fabs( double );
extern float fabsf( float );

extern double cbrt( double );
extern float cbrtf( float );

extern double hypot ( double, double );
extern float hypotf ( float, float );

extern double pow ( double, double );
extern float powf ( float, float );

extern double sqrt( double );
extern float sqrtf( float );

extern double erf( double );
extern float erff( float );

extern double erfc( double );
extern float erfcf( float );






extern double lgamma( double );
extern float lgammaf( float );

extern double tgamma( double );
extern float tgammaf( float );

extern double ceil ( double );
extern float ceilf ( float );

extern double floor ( double );
extern float floorf ( float );

extern double nearbyint ( double );
extern float nearbyintf ( float );

extern double rint ( double );
extern float rintf ( float );

extern long int lrint ( double );
extern long int lrintf ( float );

extern double round ( double );
extern float roundf ( float );

extern long int lround ( double );
extern long int lroundf ( float );




    extern long long int llrint ( double );
    extern long long int llrintf ( float );

    extern long long int llround ( double );
    extern long long int llroundf ( float );



extern double trunc ( double );
extern float truncf ( float );

extern double fmod ( double, double );
extern float fmodf ( float, float );

extern double remainder ( double, double );
extern float remainderf ( float, float );

extern double remquo ( double, double, int * );
extern float remquof ( float, float, int * );

extern double copysign ( double, double );
extern float copysignf ( float, float );

extern double nan( const char * );
extern float nanf( const char * );

extern double nextafter ( double, double );
extern float nextafterf ( float, float );

extern double fdim ( double, double );
extern float fdimf ( float, float );

extern double fmax ( double, double );
extern float fmaxf ( float, float );

extern double fmin ( double, double );
extern float fminf ( float, float );

extern double fma ( double, double, double );
extern float fmaf ( float, float, float );

extern long double acosl(long double);
extern long double asinl(long double);
extern long double atanl(long double);
extern long double atan2l(long double, long double);
extern long double cosl(long double);
extern long double sinl(long double);
extern long double tanl(long double);
extern long double acoshl(long double);
extern long double asinhl(long double);
extern long double atanhl(long double);
extern long double coshl(long double);
extern long double sinhl(long double);
extern long double tanhl(long double);
extern long double expl(long double);
extern long double exp2l(long double);
extern long double expm1l(long double);
extern long double logl(long double);
extern long double log10l(long double);
extern long double log2l(long double);
extern long double log1pl(long double);
extern long double logbl(long double);
extern long double modfl(long double, long double *);
extern long double ldexpl(long double, int);
extern long double frexpl(long double, int *);
extern int ilogbl(long double);
extern long double scalbnl(long double, int);
extern long double scalblnl(long double, long int);
extern long double fabsl(long double);
extern long double cbrtl(long double);
extern long double hypotl(long double, long double);
extern long double powl(long double, long double);
extern long double sqrtl(long double);
extern long double erfl(long double);
extern long double erfcl(long double);






extern long double lgammal(long double);

extern long double tgammal(long double);
extern long double ceill(long double);
extern long double floorl(long double);
extern long double nearbyintl(long double);
extern long double rintl(long double);
extern long int lrintl(long double);
extern long double roundl(long double);
extern long int lroundl(long double);



    extern long long int llrintl(long double);
    extern long long int llroundl(long double);


extern long double truncl(long double);
extern long double fmodl(long double, long double);
extern long double remainderl(long double, long double);
extern long double remquol(long double, long double, int *);
extern long double copysignl(long double, long double);
extern long double nanl(const char *);
extern long double nextafterl(long double, long double);
extern double nexttoward(double, long double);
extern float nexttowardf(float, long double);
extern long double nexttowardl(long double, long double);
extern long double fdiml(long double, long double);
extern long double fmaxl(long double, long double);
extern long double fminl(long double, long double);
extern long double fmal(long double, long double, long double);
# 510 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 3 4
extern double __inf( void );
extern float __inff( void );
extern long double __infl( void );
extern float __nan( void );


extern double j0 ( double );

extern double j1 ( double );

extern double jn ( int, double );

extern double y0 ( double );

extern double y1 ( double );

extern double yn ( int, double );

extern double scalb ( double, double );
# 546 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 3 4
extern int signgam;
# 560 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 3 4
extern long int rinttol ( double );

extern long int roundtol ( double );
# 571 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 3 4
struct exception {
 int type;
 char *name;
 double arg1;
 double arg2;
 double retval;
};
# 600 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/architecture/i386/math.h" 3 4
extern int finite ( double );

extern double gamma ( double );




extern int matherr ( struct exception * );





extern double significand ( double );




extern double drem ( double, double );
# 29 "/Developer/SDKs/MacOSX10.6.sdk/usr/include/math.h" 2 3 4
# 16 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c" 2
# 25 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c"
void make_upper( char string[]);

void make_lower( char string[]);

int strdlm(char output[],char input[], char delms[], int inclusive);

int ctrl_dispatch(char ctrl_str[] );

int read_in(char word[],int vector[]);

void new_game(void);

char next_tile(int tile_bag[]);

void fill_rack(int tile_bag[], char rack[]);

void empty_rack(char rack[]);

int check_rack(char word[],int vector[], char tiles[][16], char rack[]);




int NorY(void);

int toss_tiles(int tile_bag[], char rack[] );

void persist(char tiles[][16],int tile_bag[],char rack[], char tag[] );

int load_crrnt(char tiles[][16],int tile_bag[],char rack[], char tag[],int *size );

int word_searcher(char tiles[][16],int size);

int chk_dict(char query[]);

int endgame(void);

int score_word(char word[]);

double calc_net_score(FILE * alt_out);

int bffr_print(char sbuf[][128],FILE * output);


void Draw_board(char tiles[][16], char rack[], char sbuf[][128]);

int strovr(char dest[], char src[], int pos);

void update_save(double score, char sbuf[][128]);

int sort_scores(int n, char names[][20], double high[], double avg[] );

void swapD (double* dx, double* dy);

int chk_tag(char tag[20]);

void place_word(char word[], char tiles[][16], int vector[]);

int bffr_cache(char sbuf[][128],int ovr_wrt);

void word_updater(void);

void delay(double secs);

int show_rules(void);



int main ()
{

 char tiles[16][16];
 int size=15;
 int tile_bag[230];



 char rack[8 +1];
 int vector[3];

 char word[16];
 char tag[20];


 char sbuf[40][128]={};


 int stop = 1;

 srand(time(0));
 bffr_print(sbuf, ((void *)0));
 bffr_print(sbuf, ((void *)0));
 new_game();
 load_crrnt(tiles, tile_bag, rack, tag, &size);
 fill_rack(tile_bag, rack);
 while(stop){
  persist(tiles, tile_bag, rack, tag);
  Draw_board(tiles, rack,sbuf);
  bffr_print(sbuf, __stdoutp);
  switch( read_in(word,vector) ){
   case 0:
    printf("\n No word was found. Try again");
    break;
   case -1:
    if (strcmp("#END#", word) ==0)
     stop=0;
    break;
   default:
    printf("\n Fantastic. You managed to play the word %s ...",word);
    delay(5);
    if ( check_rack(word, vector, tiles, rack) ){
     place_word(word, tiles, vector);
    }else {
     printf("\n\n Word cannot be played.");
     delay(5);
    }
    Draw_board(tiles, rack,sbuf);
    bffr_print(sbuf, __stdoutp);
    delay(.7);
    empty_rack(rack);
    Draw_board(tiles, rack,sbuf);
    bffr_print(sbuf, __stdoutp);
    delay(.7);
    fill_rack(tile_bag, rack);
    Draw_board(tiles, rack,sbuf);
    bffr_print(sbuf, __stdoutp);
    delay(.7);

  }
 }
 return(0);
}



int read_in( char word[], int vector[] )

{
 int flag=-1;
 char input[80] = {};
 char temp[16];

 printf("\n What is your input ? \n >> ");
 do{ ((__builtin_object_size (input, 0) != (size_t) -1) ? __builtin___memset_chk (input, 0, 80, __builtin_object_size (input, 0)) : __inline_memset_chk (input, 0, 80));
  fgets(input,80, __stdinp);
  __builtin___sprintf_chk (strchr(input,'\n'), 0, __builtin_object_size (strchr(input,'\n'), 2 > 1), "%c",'\0');
 } while(strlen(input) <3);
 make_upper(input);

 ((__builtin_object_size (vector, 0) != (size_t) -1) ? __builtin___memset_chk (vector, 0, sizeof(vector[0])*3, __builtin_object_size (vector, 0)) : __inline_memset_chk (vector, 0, sizeof(vector[0])*3));
 while (1){
  ((__builtin_object_size (temp, 0) != (size_t) -1) ? __builtin___memset_chk (temp, '\0', 16, __builtin_object_size (temp, 0)) : __inline_memset_chk (temp, '\0', 16));
  switch (flag)
  {
   case -1:
    if (strdlm(temp, input,"#", 0) >0){
     ((__builtin_object_size (input, 0) != (size_t) -1) ? __builtin___memset_chk (input, 0, 80, __builtin_object_size (input, 0)) : __inline_memset_chk (input, 0, 80));
     __builtin___sprintf_chk (input, 0, __builtin_object_size (input, 2 > 1), "#%s#",temp);
     if (ctrl_dispatch(input)){
      ((__builtin_object_size (word, 0) != (size_t) -1) ? __builtin___strcpy_chk (word, input, __builtin_object_size (word, 2 > 1)) : __inline_strcpy_chk (word, input));
      return(-1);
     }
     return(0);
    }
    break;
   case 0:
    __builtin___sprintf_chk (temp, 0, __builtin_object_size (temp, 2 > 1), "%c%c",(char)34,(char)39);
    ((__builtin_object_size (word, 0) != (size_t) -1) ? __builtin___memset_chk (word, '\0', 16, __builtin_object_size (word, 0)) : __inline_memset_chk (word, '\0', 16));
    strdlm(word, input, temp, 0);
    ((__builtin_object_size (strstr(input,word), 0) != (size_t) -1) ? __builtin___strncpy_chk (strstr(input,word), "----------------", strlen(word), __builtin_object_size (strstr(input,word), 2 > 1)) : __inline_strncpy_chk (strstr(input,word), "----------------", strlen(word)));
    if (word && 1)
     printf("\n Found word: %s",word);
    break;
   case 1:
    strdlm(temp, input, "0123456789", 1);
    vector[1] = atoi(temp);
    if (vector[1] && 1)
     printf("\n Found row: %d",vector[1]);
    break;
   case 2:
    strdlm(temp, input, "XY", 1);
    vector[0] =( ( (int)temp[0] - 88) * -2) +1;
    if (vector[0] && 1)
     printf("\n Found direction: %d",vector[0]);
    break;
   case 3:
    strdlm(temp, input, "ABCDEFGHIJKLMNO", 1);
    vector[2]=( (int)temp[0]-64 );
    if (vector[2] && 1)
     printf("\n Found column: %d",vector[2]);
    break;
   default:
    if (strlen(word) && vector[0] && vector[1] && vector[2] ){
     return(strlen(word));
    } else{
     printf("\n Not all segments found.");
     return(0);
    }
  }
  flag++;
 }
}

void make_upper( char string[])
{
 int i;
 for (i=0; i<=strlen(string); i++)
 {
  if ( (string[i]>='a') && (string[i]<='z') )
  {
   string[i] = (char)((int)string[i] - 32);
  }
 }
}
void make_lower( char string[])
{
 int i;
 for (i=0; i<=strlen(string); i++)
 {
  if ( (string[i]>='A') && (string[i]<='Z') )
  {
   string[i] = (char)((int)string[i] + 32);
  }
 }
}

int strdlm(char output[],char input[], char delms[], int inclusive)
{
 int i=0 ;
 char * pch1;
 char * pch2;

 char * temp1 = ((void *)0);
 temp1 = (char *) calloc(strlen(input), sizeof(char));
 ((__builtin_object_size (temp1, 0) != (size_t) -1) ? __builtin___memset_chk (temp1, '\0', strlen(input), __builtin_object_size (temp1, 0)) : __inline_memset_chk (temp1, '\0', strlen(input)));

 pch1 = strpbrk(input, delms);
 switch (inclusive)
 {
  case 1:
   for (pch1 = strpbrk(input, delms); pch1 ;pch1 = strpbrk(pch1 +1,delms))
   {
    ((__builtin_object_size (temp1, 0) != (size_t) -1) ? __builtin___strncat_chk (temp1, pch1, 1, __builtin_object_size (temp1, 2 > 1)) : __inline_strncat_chk (temp1, pch1, 1)); i++;
   }
   break;
  case 0:
   for (pch2 = pch1 + 1;
     (long int)pch1 ? (pch2 < strpbrk(pch1+1,delms)) : (long int)pch1 ;
     pch2++)
   {
    ((__builtin_object_size (temp1, 0) != (size_t) -1) ? __builtin___strncat_chk (temp1, pch2, 1, __builtin_object_size (temp1, 2 > 1)) : __inline_strncat_chk (temp1, pch2, 1)); i++;
   }
   break;
  default:
   return(-1);
 }
 ((__builtin_object_size (output, 0) != (size_t) -1) ? __builtin___strcpy_chk (output, temp1, __builtin_object_size (output, 2 > 1)) : __inline_strcpy_chk (output, temp1));
 free(temp1);
 temp1 = ((void *)0);
 return(i);
}

int ctrl_dispatch(char ctrl_str[])


{
 char ctrl_key[9][10] = { "#RULES#", "#WORDS#", "#END#",
            "#SCORE#", "#TOSS#", "#RESTART#",
            "#SPELL#", "#SWAP#", ""};
 int i;

 int tile_bag[230] = {};
 char rack[8 +1] = {};
 char temp[16]={};


 for (i=0; strlen(ctrl_key[i]); ++i){
  if (0 == strcmp(ctrl_str, ctrl_key[i]) )
   break;
 }
 switch (i) {
  case 0:

   printf("\n So these are the rules..");
   return(1);
  case 1:
   word_updater();
   return(1);
  case 2:
   endgame();
   return(1);
  case 3:
   printf("\n What word would you like to check the point value of? \n >>");
   scanf("%s",temp);
   make_upper(temp);
   strdlm(temp, temp, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1);
   printf("\n The point value of %s is %d pts. ",temp,score_word(temp));
   delay(1);
   return(1);
  case 4:
  case 7:
   load_crrnt(((void *)0), tile_bag, rack, ((void *)0), ((void *)0));
   if( (tile_bag != ((void *)0)) && (rack != ((void *)0)) )
    if( toss_tiles(tile_bag,rack) )
     persist(((void *)0), tile_bag, rack, ((void *)0));
   return(1);
  case 5:
   printf("\n Are you sure you want to restart the game? >> ");
   if(NorY())
    new_game();
   return(1);
  case 6:
   printf("\n What word would you like to check? >> ");
   scanf("%s",temp);
   if ( chk_dict(temp) ) {
    printf("\n Yes, %s is a recognized word.",temp);
   }else {
    printf("\n Sorry, %s is not a recognized word.",temp);
   }
   delay(2);
   return(1);
  default :
   printf("\n %c %s %c is not a recognized #CTRL# sequence.",'"',ctrl_str,'"');
   delay(1);
   return(0);
 }
}

void new_game(void)
# 366 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c"
{
 int size=0;
 int tile_bag[230] = {};
 char tiles[16][16] = {};
 char rack[8 +1] = {};
 char tag[20] = {};

 int ref_freq[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};
 int freq_dst[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};
 int i,r,j,k,sum;


 do {
  printf("\n What name would you like to save your games under?\n >> ");
  do{ ((__builtin_object_size (tag, 0) != (size_t) -1) ? __builtin___memset_chk (tag, 0, 20, __builtin_object_size (tag, 0)) : __inline_memset_chk (tag, 0, 20));
   fgets(tag, 20, __stdinp);
   make_upper(tag);
   tag[strcspn(tag, "\n")] = '\0';
  }while(strlen(tag)<2);
  printf(" You entered: %s as your tag. Is that correct? >> ",tag);
 } while (NorY() == 0) ;

 printf("\n How big of a board would you like (5-%d)? >> ",(16 -1) );
 scanf("%d",&size);
 while ((size > 16 -1) || (size < 5))
 {
  printf(" I'm sorry, %d is not a valid option.",size);
  printf("\n Please enter a value between 5 and %d, inclusive.\n >> ",(16 -1));
  scanf("%d",&size);
 }
 if (size%2 == 0){
  printf(" Scrabble boards are always an odd size.");
  if (size == 6) {
   size =5;
  }else { size++; }
 }
 printf("\n Right. Board size %d it is. \n",size);

 tile_bag[0] = size * size;
 for (i=1; i<=tile_bag[0]; i++)
 {
  do{
   sum = 0;
   for (j=0; j<26; j++)
    sum += freq_dst[j];
   if (sum <= 0){
    for (j=0; j<26; j++)
     freq_dst[j] = ref_freq[j];
   }
  } while (sum <= 0);

  r = 0;
  if(sum )
   r=rand()%sum;
  j = 0;
  for (k=0; k<26; ++k) {
   j += freq_dst[k];
   if( ((j>r) && (sum==0)) || ((j>=r) && sum) ) { break;}
  }
  tile_bag[i] = 65+k;
  freq_dst[k]--;
 }
 tile_bag[tile_bag[0]+1] = -999;

 for (i=0; i<size; i++){
  ((__builtin_object_size (tiles[i], 0) != (size_t) -1) ? __builtin___memset_chk (tiles[i], ' ', size, __builtin_object_size (tiles[i], 0)) : __inline_memset_chk (tiles[i], ' ', size));
  if (1)
   fill_rack(tile_bag, tiles[i]);
 }
 if(1)
  tile_bag[0] = size * size;
 tiles[size/2][size/2] = '@';
 for (i=size; i<16; i++)
  ((__builtin_object_size (tiles[i], 0) != (size_t) -1) ? __builtin___memset_chk (tiles[i], 0, 16, __builtin_object_size (tiles[i], 0)) : __inline_memset_chk (tiles[i], 0, 16));

 ((__builtin_object_size (rack, 0) != (size_t) -1) ? __builtin___memset_chk (rack, '_', 8, __builtin_object_size (rack, 0)) : __inline_memset_chk (rack, '_', 8));
 bffr_cache(0, 1);

 persist(tiles, tile_bag, rack, tag);
}


char next_tile(int tile_bag[])
{
 int position;
 char letter;

 position = tile_bag[0];
 letter = (char)tile_bag[position];
 position = position - 1;
 tile_bag[0] = position;

 return(letter);
}


void fill_rack(int tile_bag[], char rack[])
{
 int i;

 for (i=0; i<strlen(rack); i++)
 {
  if (isalpha(rack[i]) == 0)
   rack[i] = next_tile(tile_bag);
 }
}


void empty_rack(char rack[])
{
 char temp[8 +1]={};
 int i,p=0;

 for (i=0; i<8; i++)
 {
  if ( isalpha(rack[i]) )
  { temp[p]=rack[i]; p++; }
 }
 for (i=p; i<8; i++)
 { temp[i] = '_'; }

 ((__builtin_object_size (rack, 0) != (size_t) -1) ? __builtin___strcpy_chk (rack, temp, __builtin_object_size (rack, 2 > 1)) : __inline_strcpy_chk (rack, temp));
}


int check_rack(char word[],int vector[], char tiles[][16], char rack[])

{
 char used[8 +1] = {};
 char temp[8 +1] = {};
 int board[16] = {};
 int i=0,k=0,c=0,b=0,length,m=0;

 length = strlen(word);
 if( (vector != ((void *)0)) && (tiles != ((void *)0) ) ){
  switch (vector[0])
  {
   case 1:
    for (i=0; i<length; i++) {
     if ( tiles[vector[1]-1][(vector[2]+i-1)] == word[i] ){ board[i]=1; b++; }
    }
    break;
   case -1:
    for (i=0; i<length; i++) {
     if ( tiles[(vector[1]+i-1)][vector[2]-1] == word[i] ){ board[i]=1; b++; }
    }
    break;
  }
 }
 for (i=0; i<length; i++)
 {
  if (board[i]==0) { used[k]=word[i]; k++; }
 }
 ((__builtin_object_size (temp, 0) != (size_t) -1) ? __builtin___strncpy_chk (temp, rack, 8, __builtin_object_size (temp, 2 > 1)) : __inline_strncpy_chk (temp, rack, 8));

 for (i=0; i<k; i++)
 {
  if (used[i]=='\0')
  { break; }
  for (m=0; m<8; m++)
  {
   if (used[i] == temp[m])
   {
    temp[m] = '_';
    c++; m=8;
   }
  }
 }
 if ( (length - b) == c )
 {
  ((__builtin_object_size (rack, 0) != (size_t) -1) ? __builtin___strcpy_chk (rack, temp, __builtin_object_size (rack, 2 > 1)) : __inline_strcpy_chk (rack, temp));
  return(1);
 } else {
  return(0);
 }
}


int NorY(void)
{
 char str[20] = {};
 while ( 1){
  scanf("%s", str);
  make_upper(str);
  if ((strcmp(str, "YES")==0) || (str[0] == 'Y') )
   return(1);
  if ((strcmp(str, "NO")==0) || (str[0] == 'N'))
   return(0);
  printf(" Only yes or no responses will be accepted. \n >> ");
 }
 printf("ERROR");
 return(-1);
}


int toss_tiles(int tile_bag[], char rack[] )
{
 char junk[80]={};

 do{ ((__builtin_object_size (junk, 0) != (size_t) -1) ? __builtin___memset_chk (junk, 0, 80, __builtin_object_size (junk, 0)) : __inline_memset_chk (junk, 0, 80));
  printf("\n What tiles would you like to toss? \n >> ");
  fgets(junk,80, __stdinp);
  __builtin___sprintf_chk (strchr(junk,'\n'), 0, __builtin_object_size (strchr(junk,'\n'), 2 > 1), "%c",'\0');
 } while(strlen(junk) <1);
 make_upper(junk);
 strdlm(junk, junk, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1);
 printf(" Are you sure you want to throw out the tiles : %s?\n >> ",junk);
 if(NorY()){
  if (check_rack(junk, ((void *)0), ((void *)0), rack) ){
   empty_rack(rack);
   fill_rack(tile_bag, rack);
  }return (1);
 }else {
  return (0);
 }
}


void persist(char tiles[][16],int tile_bag[],char rack[], char tag[] )


{
 FILE * current_game;
 int i;
 int size;
 char temp[80] = {};
 char filename[30] = {};
 char str[32] = {};

 if (strspn(rack, "#") == strlen(rack)) {
  ((__builtin_object_size (filename, 0) != (size_t) -1) ? __builtin___strcpy_chk (filename, tag, __builtin_object_size (filename, 2 > 1)) : __inline_strcpy_chk (filename, tag));
  ((__builtin_object_size (filename, 0) != (size_t) -1) ? __builtin___strcat_chk (filename, ".txt", __builtin_object_size (filename, 2 > 1)) : __inline_strcat_chk (filename, ".txt"));
 } else {
  ((__builtin_object_size (filename, 0) != (size_t) -1) ? __builtin___strcpy_chk (filename, "current.txt", __builtin_object_size (filename, 2 > 1)) : __inline_strcpy_chk (filename, "current.txt"));
 }
 size = strlen(tiles[0]);
 current_game = fopen(filename, "w");
 for (i=-3; i<16; i++)
 {
     switch (i)
  {
   case -3:
    __builtin___sprintf_chk (str, 0, __builtin_object_size (str, 2 > 1), "%s",tag);
    break;
   case -2:
    __builtin___sprintf_chk (str, 0, __builtin_object_size (str, 2 > 1), "%d",size);
    break;
   case -1:
    __builtin___sprintf_chk (str, 0, __builtin_object_size (str, 2 > 1), "%s",rack);
    break;
   default:
    __builtin___sprintf_chk (str, 0, __builtin_object_size (str, 2 > 1), "%s",tiles[i]);
    break;
  }
  ((__builtin_object_size (temp, 0) != (size_t) -1) ? __builtin___memset_chk (temp, 0, 80, __builtin_object_size (temp, 0)) : __inline_memset_chk (temp, 0, 80));
  ((__builtin_object_size (temp, 0) != (size_t) -1) ? __builtin___strcpy_chk (temp, "###############################", __builtin_object_size (temp, 2 > 1)) : __inline_strcpy_chk (temp, "###############################"));
  strovr(temp, str, 2);
  fprintf(current_game,"%s\n", temp);
 }
 for( i=0; i<=tile_bag[0]+1; i++)
  fprintf(current_game, "%d ",tile_bag[i]);
 fclose(current_game);
}


int load_crrnt(char tiles[][16],int tile_bag[],char rack[], char tag[],int *size )


{
 FILE * current_game;
 int i;
 char temp[80] = {};
 char temp2[80] = "0123456789 @_ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 current_game = fopen("current.txt","r");

 if (current_game == ((void *)0)) {
  printf("\n No current game persistence found.");
  fclose(current_game);
  return(0);
 }
 for (i=-3; i<16; i++)
 { switch (i)
  { case -3:
    if (tag == ((void *)0)){
     fseek(current_game, 33, 1);
    }else{
     fgets(temp, 33, current_game);
     strdlm(tag, temp, temp2, 1);
    }break;
   case -2:
    if (size == ((void *)0)){
     fseek(current_game, 32, 1);
    }else{
     fgets(temp, 33, current_game);
     strdlm(temp, temp, temp2, 1);
     *size = atoi(temp);
    }break;
   case -1:
    if (rack == ((void *)0)){
     fseek(current_game, 32, 1);
    }else{
     fgets(temp, 33, current_game);
     strdlm(rack, temp, temp2, 1);
    }break;
   default:
    if (tiles == ((void *)0)){
     fseek(current_game, 32*16, 1);
    }else{
     fgets(temp, 33, current_game);
     strdlm(tiles[i], temp, temp2, 1);
    }break;
  }
 }
 if (tile_bag != ((void *)0))
  for (i=0;(tile_bag[i-1] != -999);i++)
   fscanf(current_game, "%d",&tile_bag[i]);
 fclose(current_game);
 return(1);
}

int word_searcher(char tiles[][16], int size)

{
 char row[16] = {};
 char string[16] = {};
 char word[16] = {};
 int i,j,flag;
 int first_letter,last_letter;
 int numwrds=0,numrow=0;
 FILE * found_words;
 FILE * not_words;
 char* ptr;


 found_words = fopen("found_words.txt", "w");
 not_words = fopen("not_words.txt", "w");

 for (flag=1; flag<3; flag++)
 {
  for (numrow=0; numrow<=size; numrow++)
  {
   switch (flag)
   {
    case 1:
     ((__builtin_object_size (row, 0) != (size_t) -1) ? __builtin___strcpy_chk (row, tiles[numrow], __builtin_object_size (row, 2 > 1)) : __inline_strcpy_chk (row, tiles[numrow]));
     break;
    case 2:
     for (i=0; i<size; i++)
      row[i] = tiles[i][numrow];
     break;
    default:
     fclose(not_words);
     fclose(found_words);
     return(numwrds);
   }
   for ( ptr = strtok(row,"- |\0\n"); ptr ; ptr = strtok(((void *)0),"- |\0\n") )
   {
    __builtin___sprintf_chk (string, 0, __builtin_object_size (string, 2 > 1), "%s",ptr);
    for (first_letter=0; first_letter<strlen(string); first_letter++)
    {
     for (last_letter=first_letter+1; last_letter<strlen(string); last_letter++)
     {
      j=0; ((__builtin_object_size (word, 0) != (size_t) -1) ? __builtin___memset_chk (word, 0, 16, __builtin_object_size (word, 0)) : __inline_memset_chk (word, 0, 16));
      for (i=first_letter; i<=last_letter; i++){
       if (!( isalpha(string[i]) )){
        first_letter= (++i);
        ((__builtin_object_size (word, 0) != (size_t) -1) ? __builtin___memset_chk (word, 0, 16, __builtin_object_size (word, 0)) : __inline_memset_chk (word, 0, 16));
        j=0;
       }
       word[j] = string[i];
       j++;
      }
      switch (chk_dict(word))
      {
       case 1:
        fprintf(found_words,"%s\n", word);
        numwrds++;
        break;
       case 2:
        fprintf(not_words, "%s\n",word);
       default:
        break;
      }
     }
    }
   }
  }
 }
 fclose(not_words);
 fclose(found_words);
 return(numwrds);
}


int chk_dict(char query[])
# 779 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c"
{
 FILE * dict_src;
 int length = strlen(query);
 int skip=0,i;
 char filename[10]={};
 int dir[27] = {};
 fpos_t wrdz_start;
 int top,bottom,middle,found;
 char word[16]={};

 make_lower(query);
 if (length<=1) { return(0); }

 __builtin___sprintf_chk (filename, 0, __builtin_object_size (filename, 2 > 1), "%c%d.txt",query[0],length);
 dict_src = fopen(filename,"r");
 if (dict_src == ((void *)0)){
  if(1)
   printf("\nERROR: No File for %s",filename);
  return(0); }
 for (i=0;i<27 ; i++) {
  fscanf(dict_src,"%d",&dir[i]); }
 for (i=0; i<( (int)query[1] -97); i++) {
  skip += dir[i]; }
 fgetpos(dict_src, &wrdz_start );


 bottom = skip;
 top = dir[i] - 1 + skip;
 found = -1;
 while ( (bottom<=top)
     && (found == -1) )
 {
  middle = (top-bottom)/2 + bottom ;
  fsetpos(dict_src, &wrdz_start);
  fseek(dict_src, ( middle * (length +1) ) + 3 , 1);
  fscanf(dict_src,"%s",word);
  if (strcmp(word,query)==0){
   found = middle;
  }else if(strcmp(word,query) > 0){
   top = middle -1;
  }else {
   bottom = middle +1;
  }
 }
 fclose(dict_src);
 make_upper(query);
 if (found!=-1) {
  return(1);
 } else {
  return (2);
 }


}


int endgame(void)
{
 char tiles[16][16];
 int tile_bag[230];
 char rack[8 +1];
 char tag[20];
 int size = (strchr(tiles[0], 0) - tiles[0] );
 double score,hiscore,avg;
 FILE * file_ptr ;
 char temp[80]={};
 char sbuf[40][128]={};
 int i=0;


 if (load_crrnt(tiles, tile_bag, rack, tag, &size) == 0 )
  return (0);
 word_searcher(tiles,size);
 score = calc_net_score(((void *)0));
 printf("\n\n Your board has a lexical density of %.4lf words per unit area.",score);
 printf("\n Would you like to see the list of words you used?\n >>");
 if (NorY())
 { file_ptr= fopen("scores.txt", "r");
  while ( fgets(temp, 80, file_ptr) != ((void *)0) )
  { if ( strcmp(temp, "#EOF#") )
   { printf("\n ");
    fputs(temp, __stdoutp);
    delay(.2);
   }
  }
  fclose(file_ptr);
 }
 fclose(file_ptr);
 printf("\n\n Would you like to see the high score list?\n >> ");
 if ( NorY() )
 { file_ptr= fopen("master_save.txt", "r");
  if (fscanf(file_ptr, "%s",temp) != (-1)){
   printf("\n%s",temp);
   while ( fscanf(file_ptr, "%s %lf %lf",temp,&hiscore,&avg) != (-1) ) {
    i++;
    if ( hiscore < score) {
     printf("\n%-20s %15.6lf %15.6lf",tag,score,score);
    }
    printf("\n%-20s %+15.6lf %+15.6lf",temp,hiscore,avg);
   }
  }
  if(i==0)
   printf("\n Your score is currently the only high score.");
  fclose(file_ptr);
 }
 fclose(file_ptr);
 printf("\n\n Would you like to save your game before quitting? >> ");
 if ( NorY() )
  update_save(score, sbuf);

 return(0);
}

int score_word(char word[])
{
 char points[11][11] = { "", "EAIONRTLSU", "DG", "BCMP", "FHVWY",
            "K", "", "", "JX", "", "QZ"};
 int score = 0;
 int i,j;
 make_upper(word);
 for(i=0;i<strlen(word);i++) {
  for (j=1; j<11; ++j) {
   if (strchr(points[j], (int)word[i]) != ((void *)0)) {
    score += j;
   }
  }
 }
 return(score);
}

double calc_net_score(FILE * alt_out)
{
 double totscore=0;
 FILE * infile;
 FILE * scr_lst;
 char temp[16] = {};
 int tik=0;
 int wrd_scr=0;
 int size;

 load_crrnt(((void *)0), ((void *)0), ((void *)0), ((void *)0), &size);

 if (size == 0) { return(0);}
 if (alt_out){
  scr_lst = alt_out;
 } else{
  scr_lst = fopen("scores.txt", "w");
 }
 do{
  switch (tik++)
  {
   case 0:
    infile = fopen("found_words.txt", "r");
    wrd_scr = 1;
    if (!(alt_out))
     fprintf(scr_lst, "#CORRECT#          #VALUE#\n");
    break;
   case 1:
    fclose(infile);
    break;
   case 2:
    infile = fopen("not_words.txt", "r");
    wrd_scr = -1;
    if (!(alt_out))
     fprintf(scr_lst, "\n#INCORRECT#        #VALUE#\n");
    break;
   case 3:
    fclose(infile);
    break;
   default:
    totscore = totscore / pow( (double)size,2.0) ;
    fprintf(scr_lst, "#EOF#");
    fclose(scr_lst);
    return(totscore);
    break;
  }
  while (fscanf(infile, "%s", temp) != (-1))
  {
   if (abs(wrd_scr) == wrd_scr)
    wrd_scr = 1 ;
   if (abs(wrd_scr) == (wrd_scr*-1))
    wrd_scr = -1 ;
   wrd_scr *= score_word(temp);
   totscore += (double) wrd_scr;
   fprintf(scr_lst, "%-20s%5d\n",temp,wrd_scr);
  }
 } while(1);

 return(0);
}

int bffr_print(char sbuf[][128],FILE * output)

{
 int i,numlines=0;
 if(!(**sbuf)){
  for (i=0; i<40; i++){
   ((__builtin_object_size (sbuf[i], 0) != (size_t) -1) ? __builtin___memset_chk (sbuf[i], ' ', (128 -2), __builtin_object_size (sbuf[i], 0)) : __inline_memset_chk (sbuf[i], ' ', (128 -2)));
   sbuf[i][128 -1] = '\0';
  }
  if (1) {
   sbuf[0][0] = '#';
   sbuf[0][128 -2] = '#';
   sbuf[40 -1][0] = '#';
   sbuf[40 -1][128 -2] = '#';
  }
  return(0);
 }
 if(output){
  fprintf(output, "\n");
  for (i=0; i<40; i++)
  {
   if (strspn(sbuf[i], " ") >=(128 -4) )
    continue;
   fputs(sbuf[i], output);
   fprintf(output, "\n");
   numlines++;
  }
 }
 bffr_cache(sbuf, 1);
 delay(.5);
 return(numlines);
}

void Draw_board(char tiles[][16], char rack[], char sbuf[][128])
# 1023 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c"
{
 int i,j;
 char values[9][9] = {"Value:","1  EAION","1  RTLSU","2  DG","3  BCMP","4  FHVWY","5  K","8  JX","10 QZ"};
 char temp1[16*4 +4] = {};
 char temp2[16*4 +4] = {};
 int size = strlen(tiles[0]);



 bffr_cache(sbuf, 0);


 for (i=0; i<size; i++) {
  __builtin___sprintf_chk (temp1, 0, __builtin_object_size (temp1, 2 > 1), "   %c", (char)(65 +i));
  ((__builtin_object_size (temp2, 0) != (size_t) -1) ? __builtin___strcat_chk (temp2, temp1, __builtin_object_size (temp2, 2 > 1)) : __inline_strcat_chk (temp2, temp1));
 }
 strovr(sbuf[1], temp2, 3);


 for (i=0; i<9; i++)
  strovr(sbuf[i+1], values[i], (16 + (4*(size -1))) );


 __builtin___sprintf_chk (temp1, 0, __builtin_object_size (temp1, 2 > 1), "+");
 __builtin___sprintf_chk (temp2, 0, __builtin_object_size (temp2, 2 > 1), "|");
 for (i=1; i<=size; i++) {
  ((__builtin_object_size (temp1, 0) != (size_t) -1) ? __builtin___strcat_chk (temp1, " - +", __builtin_object_size (temp1, 2 > 1)) : __inline_strcat_chk (temp1, " - +"));
  ((__builtin_object_size (temp2, 0) != (size_t) -1) ? __builtin___strcat_chk (temp2, "   |", __builtin_object_size (temp2, 2 > 1)) : __inline_strcat_chk (temp2, "   |"));
 }
 strovr(sbuf[2],temp1,4);
 for (i=0; i<(2*size); i++) {
  if(i%2) {
   strovr(sbuf[i+3], temp1, 4);
   continue;
  }
  strovr(sbuf[i+3], temp2, 4);
 }

 for (i=0; i<size; i++) {
  __builtin___sprintf_chk (temp1, 0, __builtin_object_size (temp1, 2 > 1), " %02d", (i+1));
  strovr(sbuf[3+ (i*2)], temp1, 0);
  for (j=0; j<size; j++) {
   sbuf[3+ (i*2)][(j*4)+6] = tiles[i][j];
  }
 }

 if (rack != ((void *)0)){
  __builtin___sprintf_chk (temp1, 0, __builtin_object_size (temp1, 2 > 1), "Your Letters:");
  for (i=0; i<8; i++) {
   __builtin___sprintf_chk (temp2, 0, __builtin_object_size (temp2, 2 > 1), "%2c",rack[i]);
   ((__builtin_object_size (temp1, 0) != (size_t) -1) ? __builtin___strcat_chk (temp1, temp2, __builtin_object_size (temp1, 2 > 1)) : __inline_strcat_chk (temp1, temp2));
  }
  sbuf[4+ size*2][8] = '\0';
  strovr(sbuf[4+ size*2 +1], temp1, 4);
 }
}


int strovr(char dest[], char src[], int pos)
{
 int i=0;
 if (strlen(dest) - strlen(src) <= 0)
  return(0);
 while( i < strlen(src) &&
    pos < strlen(dest) )
  dest[pos++] = src[i++];
 return(1);
}


void update_save(double score, char sbuf[][128])
# 1105 "/Developer/ECS 102 Projects/Final Project/Project Files/main.alpha.c"
{
 FILE * savfile;
 int number=0, i=0;
 char tag[20];

 char names[50][20]={};
 double highs[50]={};
 double avgs[50]={};

 char tiles[16][16]={};
 int size;
 char filename[80] = {};
 load_crrnt(tiles, ((void *)0), ((void *)0), tag, &size);
 savfile = fopen("master_save.txt", "r");
 ((__builtin_object_size (names[0], 0) != (size_t) -1) ? __builtin___strcpy_chk (names[0], tag, __builtin_object_size (names[0], 2 > 1)) : __inline_strcpy_chk (names[0], tag));
 highs[0] = score;
 avgs[0] = 0;
 if (fscanf(savfile, "%s",filename) != (-1) )
 {

  while (fscanf(savfile, " %s %lf %lf",names[49],highs[49],avgs[49]) != (-1)){
   sort_scores(number, names, highs, avgs);
  }
 }
 fclose(savfile);
 savfile = fopen("master_save.txt", "w");
 fprintf(savfile, "PLAYER_TAG```````````````HIGH_SCORE```````AVERAGES");
 for (i=0;i<50; i++){
  if (highs[i])
   fprintf(savfile,"\n%-20s %+12.6lf %+15.6lf", names[i], highs[i], avgs[i]);
 }
 fclose(savfile);

}

int sort_scores(int n, char names[][20], double high[], double avg[] )

{
    int last;
    int i=0,j;
 int flag=1;
 char tmp[20]={};

 for (j=0;j<2;j++)
 { for (last = n-1; last>=1; last--)
  { for (i=0; i<= last-1; i++)
   { switch (j)
    {
     case 0:
      if (high[i]<high[i+1]){
       swapD( &high[i], &high[i+1] );
       if(avg){
        swapD( &avg[i], &avg[i+1] );
       }else {
        ((__builtin_object_size (tmp, 0) != (size_t) -1) ? __builtin___strcpy_chk (tmp, names[i], __builtin_object_size (tmp, 2 > 1)) : __inline_strcpy_chk (tmp, names[i]));
        ((__builtin_object_size (names[i], 0) != (size_t) -1) ? __builtin___strcpy_chk (names[i], names[i+1], __builtin_object_size (names[i], 2 > 1)) : __inline_strcpy_chk (names[i], names[i+1]));
        ((__builtin_object_size (names[i+1], 0) != (size_t) -1) ? __builtin___strcpy_chk (names[i+1], tmp, __builtin_object_size (names[i+1], 2 > 1)) : __inline_strcpy_chk (names[i+1], tmp));
       }
      }
      break;
     case 1:
      if(avg==((void *)0)) { return(0); }
      if (strcmp(names[i],names[last])==0)
      { if (avg[i] - avg[last] == -avg[i])
        flag=0;
       ((__builtin_object_size (names[last], 0) != (size_t) -1) ? __builtin___memset_chk (names[last], 0, 20, __builtin_object_size (names[last], 0)) : __inline_memset_chk (names[last], 0, 20));
       avg[i] = (avg[i] + avg[last] +high[last])/2.0;
       high[last]=0;
      }
      break;
    }
   }
  }
 }
 return(flag);
}


void swapD (double* dx, double* dy)
{
    double dz;
    dz = *dx;
    *dx = *dy;
    *dy = dz;
}

int chk_tag(char tag[20])
{
 char temp[80];
 char name[20];
 int i=0;
 FILE * inf;

 inf = fopen("master_save.txt", "r");

 while (fgets(temp, 80, inf) != ((void *)0)) {
  fscanf(inf, "%s",name);
  make_upper(name);
  make_upper(tag);
  if(strcmp(name, tag) == 0)
   i=1;
 }
 fclose(inf);
 return(i);
}


void place_word(char word[], char tiles[][16], int vector[])
{
 int i=0;

 for (i=0; i<strlen(word); i++)
 {
  switch (vector[0])
  {
  case 1:
   tiles[vector[1]-1][vector[2]+i-1] = word[i];
   break;

  case -1:
   tiles[vector[1]+i-1][vector[2]-1] = word[i];
   break;
  }
 }
}

int bffr_cache(char sbuf[][128],int ovr_wrt)
{


 FILE * cache;
 int i,j;

 switch ((int)(ovr_wrt && 1)) {
  case 1:
   cache = fopen("cache.txt", "w");

   if(cache == ((void *)0))
    return(0);
   if(sbuf)
    for (i=0; i<40; i++) {
     for (j=0; j<128; j++) {
      putc((int)(sbuf[i][j]), cache);
     }
     fprintf(cache,"\n");
    }
   fclose(cache);
   break;
  case 0:
   cache = fopen("cache.txt", "r");
   if(cache == ((void *)0))
    return(0);
   if(sbuf)
    for (i=0; i<40; i++) {
     for (j=0; j<128; j++) {

      fscanf(cache, "%c",&(sbuf[i][j]));
     }
     fscanf(cache, "%*c");
    }
   fclose(cache);
   break;
  default:
   return(-1);
   break;
 }


 fclose(cache);
 return(1);
}

void word_updater(void)
{
 char buffer[40][128];
 char words[40][20]={};
 double scores[40] ={};
 char tiles[16][16] = {};
 int size,i,j;
 char temp[40]={};
 char file[1024] = {};
 FILE * ftmp;
 ftmp = fopen(tmpnam(file),"w");

 load_crrnt(tiles, ((void *)0), ((void *)0), ((void *)0), &size);
 word_searcher(tiles,size);
 calc_net_score(ftmp);
 ftmp = freopen(file, "r" ,ftmp);
 do {
  sort_scores(40, words, scores, ((void *)0));
  fscanf(ftmp, "%s %lf",words[40*3/5],&scores[40*3/5]);
 } while (strcmp(words[40*3/5],"#EOF#"));
 ((__builtin_object_size (words[40*3/5], 0) != (size_t) -1) ? __builtin___memset_chk (words[40*3/5], 0, 20, __builtin_object_size (words[40*3/5], 0)) : __inline_memset_chk (words[40*3/5], 0, 20));
 scores[40*3/5] = 0;
 bffr_cache(buffer, 0);
 for (i=0 ;i<(3+ (size*2) *3/5); i++) {
  __builtin___sprintf_chk (temp, 0, __builtin_object_size (temp, 2 > 1), "%-20s%5.0lf", words[i], scores[i]);
  strovr(buffer[i], temp, (30+ (4*(size -1))));
 }
 for (j=40,i=(3+ (size*2)); i>(3+ (size*2) *3/5); i--) {
  __builtin___sprintf_chk (temp, 0, __builtin_object_size (temp, 2 > 1), "%-20s%5.0lf", words[--j], scores[j]);
  strovr(buffer[i], temp, (30+ (4*(size -1))));
 }
 bffr_cache(buffer, 1);
 fclose(ftmp);
 remove(file);
}

void delay(double secs)
{
 int c0;
 int cps=1000000;
 int clicksToDelay;

 clicksToDelay = cps*secs;
 c0=clock();
 while (clock()-c0 < clicksToDelay);

}


int show_rules()
{
 char option='\0';
 int exit = 0;

 printf("\n\n");
 printf("		Welcome to the Lexical-Density #RULES page.\n");

 do {
  printf("Which section would you like to see?\n");
  printf("1) Introduction \n2) Gameplay \n3) Winning \n4) Saving \n5) Exit\n\n");

  while (option<49 || option>53) { scanf("%c",&option); }

  switch (option)
  {
   case '1':
   {
    printf("1) INTRODUCTION\n\n");

    printf("The goal of the game is to put as many words on the board as possible. \n");
    printf("Playing is easy, if you know how to play Bananagrams and/or Scrabble, \n");
    printf("than you should have no problems playing this game. However, to win you \n");
    printf("will need to think outside the box (or /inside/ the box in this case). \n");
    printf("The goal of the game is to place as many words as possible in the \n");
    printf("smallest area possible, using letters as efficiently as possible. \n");
   }
    break;

   case '2':
   {
    printf("2) GAME PLAY\n\n");

    printf("Every turn you will be given letters up the up to the size of your \n");
    printf("board. From these you must pick those you wish to place on the board. On \n");
    printf("the first turn, your word must intersect the starting character '@'. On \n");
    printf("every subsequent turn your word must intersect some portion of the what \n");
    printf("is already on the board. Words may overlap, be lengthened and can even \n");
    printf("be overwritten. Be careful though, you the total number of letters you \n");
    printf("get is equal to the number of spots on your board.\n\n");

    printf("When playing words, you must specify:\n");
    printf("- The WORD with quotes (\" or ')\n");
    printf("- The COLUMN (A,B,C,D,..etc.)\n");
    printf("- The ROW number\n");
    printf("- What AXIS you want your letters placed on (X or Y)\n");

    printf("If you are stuck you also have the option to #TRASH letters that you \n");
    printf("can't use. \n");
   }
    break;

   case '3':
   {
    printf("3) WINNING\n\n");

    printf("At the end of play the number of correctly spelled words on the board \n");
    printf("will be tallied and scored according to the per letter point-values of \n");
    printf("Scrabble. Incorrectly spelled words will be subtracted from this score. \n");
    printf("You word-score will then by your by the area of the board (hence the \n");
    printf("name \"Lexical-Density\").\n\n");

    printf("When calculating the Lexical-Density of the board, any adjacent sequence \n");
    printf("of letters will be counted as a word. All 'words' will be checked \n");
    printf("against the SOWPODS dictionary, so regular Scrabble rules apply in terms \n");
    printf("of word choice.\n");
   }
    break;

   case '4':
   {
    printf("4) SAVING\n\n");

    printf("You may #SAVE your game at anytime. Players using a specified 'tag' are \n");
    printf("able to save multiple completed games, and will be able to see pertinent \n");
    printf("statistics across them.\n");
    printf("\n\n");
   }
    break;

   case '5':
   {
    exit = 1;
   }

   default:
    printf("\n\nBAD INPUT\n\n");
    break;
  }
 } while (exit ==0);
 return(0);
}
