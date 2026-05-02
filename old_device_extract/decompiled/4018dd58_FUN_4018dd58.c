// Function : FUN_4018dd58
// Address  : 0x4018dd58
// Size     : 156 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_4018dd58(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  memw();
  uVar3 = _DAT_3ff48074 >> 0x1d & 3;
  uVar2 = _DAT_3ff48074 >> 0x1b & 3;
  uVar1 = _DAT_3ff48074 >> 0x19 & 3;
  if ((_DAT_3ff48074 & 0x400000) == 0) {
    memw();
    if ((_DAT_3ff5a010 & 0x10000) == 0) {
      uVar2 = uVar2 << 5;
      memw();
      uVar3 = (_DAT_3ff44038 >> 5 & 1 ^ 1) << 2 | 2 | uVar3 << 3;
    }
    else {
      memw();
      if ((_DAT_3ff5a00c & 0x4000) == 0) {
        uVar3 = _DAT_3ff5a010 >> 8 & 3;
        uVar2 = _DAT_3ff5a010 >> 10 & 3;
        uVar1 = _DAT_3ff5a010 >> 0xc & 3;
      }
      uVar2 = uVar2 << 5;
      uVar3 = (_DAT_3ff5a010 >> 0xe & 1) << 1 | (_DAT_3ff5a010 >> 0xf & 1) << 2 | uVar3 << 3;
    }
  }
  else {
    uVar2 = uVar2 << 5;
    uVar3 = (_DAT_3ff48074 >> 0x1f) << 1 | 1 | (_DAT_3ff48074 >> 0x17 & 1) << 2 | uVar3 << 3;
  }
  return uVar3 | uVar2 | uVar1 << 7;
}

