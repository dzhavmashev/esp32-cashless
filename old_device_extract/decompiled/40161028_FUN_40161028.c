// Function : FUN_40161028
// Address  : 0x40161028
// Size     : 61 bytes


void FUN_40161028(void)

{
  uint uVar1;
  uint uVar2;
  
  for (uVar1 = FUN_401673e4(1); uVar1 != 0;
      uVar1 = uVar1 & (1 << 0x20 - (0x20 - (uVar2 & 0x1f)) ^ 0xffffffffU)) {
    uVar2 = 0x1f - LZCOUNT(-uVar1 & uVar1);
    FUN_40160fa4(uVar2);
    FUN_40167430(1);
  }
  return;
}

