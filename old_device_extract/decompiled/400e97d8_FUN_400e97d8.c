// Function : FUN_400e97d8
// Address  : 0x400e97d8
// Size     : 75 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e97d8(void)

{
  int iVar1;
  
  FUN_40146d2c(&DAT_3ffc51d4);
  if (_DAT_3ffc51d4 != 0) {
    _DAT_3ffc51d0 = (*(code *)&LAB_40170346_2)((uint)_DAT_3ffc51d4 * 0x50);
    iVar1 = FUN_40146d84(&DAT_3ffc51d4,_DAT_3ffc51d0);
    if (iVar1 != 0) {
      _DAT_3ffc51d4 = 0;
    }
  }
  _DAT_3ffc51d8 = 0;
  FUN_400e815c(0x1000);
  FUN_400e8174(0x800);
  return;
}

