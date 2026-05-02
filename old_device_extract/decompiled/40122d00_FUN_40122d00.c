// Function : FUN_40122d00
// Address  : 0x40122d00
// Size     : 64 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40122d00(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_40121af8(*param_1);
  iVar2 = iVar1;
  if ((iVar1 != 0) && (iVar2 = FUN_40122bfc(param_1), iVar2 == 0)) {
    iVar2 = _DAT_3ffc75cc * 0x70;
    _DAT_3ffc75cc = _DAT_3ffc75cc + 1;
    param_1[1] = iVar2 + 0x20000000;
    param_1[2] = iVar2 + 0x20000070;
    iVar2 = iVar1;
  }
  memw();
  return iVar2;
}

