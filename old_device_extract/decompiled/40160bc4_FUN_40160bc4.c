// Function : FUN_40160bc4
// Address  : 0x40160bc4
// Size     : 65 bytes


void FUN_40160bc4(void)

{
  uint uVar1;
  uint uVar2;
  
  for (uVar1 = FUN_401673e4(0); uVar1 != 0;
      uVar1 = uVar1 & (1 << 0x20 - (0x20 - (uVar2 & 0x1f)) ^ 0xffffffffU)) {
    uVar2 = 0x1f - LZCOUNT(-uVar1 & uVar1);
    FUN_40166714(uVar2);
    FUN_40160b14(uVar2);
    FUN_40167430(0);
  }
  return;
}

