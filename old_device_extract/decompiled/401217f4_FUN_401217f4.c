// Function : FUN_401217f4
// Address  : 0x401217f4
// Size     : 49 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401217f4(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  FUN_4011e738(0x1f);
  (*(code *)&SUB_4000681c)(uVar1,uVar1 + 0x1a,0x1f);
  FUN_4011e724(0x1f);
  if (uVar1 != 0) {
    memw();
    _DAT_3ffc6d84 = 1;
  }
  memw();
  return;
}

