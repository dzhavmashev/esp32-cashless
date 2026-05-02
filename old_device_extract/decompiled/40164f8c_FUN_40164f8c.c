// Function : FUN_40164f8c
// Address  : 0x40164f8c
// Size     : 30 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40164f8c(uint param_1)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xff) * 4;
  _DAT_3ffc06f0 = _DAT_3ffc06f0 ^ *(uint *)(&DAT_3ffc06e0 + iVar1);
  *(undefined4 *)(&DAT_3ffc06e0 + iVar1) = 0;
  memw();
  return;
}

