// Function : FUN_401636d0
// Address  : 0x401636d0
// Size     : 84 bytes


void FUN_401636d0(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0xffffffff;
  uVar1 = (uint)DAT_3ffc7bd4;
  do {
    iVar2 = FUN_40161270(uVar1);
    if ((iVar2 != 0) && (iVar2 = FUN_401635f4(uVar1), iVar2 != 0)) {
      uVar3 = uVar1;
    }
    uVar1 = uVar1 + 1 & 0xff;
    if (uVar1 == 2) {
      uVar1 = 0;
    }
  } while (DAT_3ffc7bd4 != uVar1);
  if (uVar3 != 0xffffffff) {
    if ((uVar3 + 1 & 0xff) != 2) {
      DAT_3ffc7bd4 = (char)(uVar3 + 1);
      memw();
      memw();
      return;
    }
    DAT_3ffc7bd4 = 0;
    memw();
  }
  memw();
  return;
}

