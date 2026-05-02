// Function : FUN_400fd3c4
// Address  : 0x400fd3c4
// Size     : 71 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fd3c4(void)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  FUN_400fd2a8(0x40083a90,uVar2 >> 0xd & 1);
  FUN_4011e738(0x1a);
  uVar2 = rsr(in_PRID);
  (*(code *)&SUB_4000681c)(uVar2 >> 0xd & 1,0x14,0x1a);
  _DAT_3ffbdd10 = 0;
  memw();
  iVar1 = FUN_4011ef94();
  if (iVar1 != 0) {
    _DAT_3ffbdd14 = 0xe;
  }
  memw();
  FUN_4011e724(0x1a);
  return;
}

