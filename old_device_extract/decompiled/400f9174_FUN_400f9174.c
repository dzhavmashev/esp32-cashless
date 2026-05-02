// Function : FUN_400f9174
// Address  : 0x400f9174
// Size     : 76 bytes


uint FUN_400f9174(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if (0xcffff < param_1 + 0xc0000000) {
    uVar1 = ((int)(param_1 + 0xc0000000) >> 0x10) + 0x40;
    if ((int)param_1 < 0x400d0000) {
      iVar2 = param_1 + 0xc0c00000;
      if ((int)(param_1 + 0xc0c00000) < 0) {
        iVar2 = param_1 + 0xc0c0ffff;
      }
      uVar1 = iVar2 >> 0x10;
    }
    if ((uVar1 < 0x100) && (uVar1 = (*(code *)&SUB_40081b1c)(), uVar1 != 0x100)) {
      return (uVar1 & 0xff) << 0x10 | param_1 & 0xffff;
    }
  }
  return 0xffffffff;
}

