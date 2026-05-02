// Function : FUN_400f3f80
// Address  : 0x400f3f80
// Size     : 62 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_400f3f80(uint param_1)

{
  uint uVar1;
  
  if ((int)param_1 < 0x20) {
    memw();
    uVar1 = *(uint *)(*_DAT_3ffbdc30 + 0x3c) >> (param_1 & 0x1f);
  }
  else {
    memw();
    memw();
    memw();
    uVar1 = (int)(*(uint *)(*_DAT_3ffbdc30 + 0x40) & 0xff) >> (param_1 & 0x1f);
    memw();
  }
  return uVar1 & 1;
}

