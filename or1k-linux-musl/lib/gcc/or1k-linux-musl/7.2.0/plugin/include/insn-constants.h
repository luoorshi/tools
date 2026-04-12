/* Generated automatically by the program `genconstants'
   from the machine description file `md'.  */

#ifndef GCC_INSN_CONSTANTS_H
#define GCC_INSN_CONSTANTS_H

#define SR_F_REG 34
#define SR_CY_REG 35
#define LINK_REGNUM 9
#define SP_REG 1
#define FP_REG 2

enum unspec {
  UNSPEC_GOT = 0,
  UNSPEC_GOTOFF = 1,
  UNSPEC_TPOFF = 2,
  UNSPEC_GOTTPOFF = 3,
  UNSPEC_TLSGD = 4,
  UNSPEC_SET_GOT = 5,
  UNSPEC_MSYNC = 6
};
#define NUM_UNSPEC_VALUES 7
extern const char *const unspec_strings[];

enum unspecv {
  UNSPECV_LL = 0,
  UNSPECV_SC = 1
};
#define NUM_UNSPECV_VALUES 2
extern const char *const unspecv_strings[];

#endif /* GCC_INSN_CONSTANTS_H */
