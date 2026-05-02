// Function : FUN_40122c40
// Address  : 0x40122c40
// Size     : 124 bytes


undefined4 FUN_40122c40(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 + 0xc0052000U < 0x52000) {
    if ((uint)(param_2 + -0x3ffae001 + param_1) < 0x52000) {
      return 1;
    }
LAB_40122c5c:
    if (param_1 + 0xc0800000U < 0x400000) {
      if (0x3fffff < (uint)(param_2 + -0x3f800001 + param_1)) {
        return 0;
      }
      return 1;
    }
  }
  else {
    uVar2 = 0x1fff;
    if (0x1fff < param_1 + 0xb0000000U) {
      if (param_1 + 0xc0080000U < 0x2000) {
        iVar1 = -0x3ff80001;
        goto LAB_40122caf;
      }
      goto LAB_40122c5c;
    }
    if ((uint)(param_2 + -0x50000001 + param_1) < 0x2000) {
      return 1;
    }
  }
  uVar2 = 0x1ffff;
  if (0x1ffff < param_1 + 0xbff80000U) {
    return 0;
  }
  iVar1 = -0x40080001;
LAB_40122caf:
  if (uVar2 < (uint)(param_2 + iVar1 + param_1)) {
    return 0;
  }
  return 1;
}

