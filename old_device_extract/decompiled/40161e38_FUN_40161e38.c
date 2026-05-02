// Function : FUN_40161e38
// Address  : 0x40161e38
// Size     : 56 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161e38(void)

{
  int iVar1;
  
  if (DAT_3ffca2f5 == '\x02') {
    iVar1 = FUN_40163758(1);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
      if (iVar1 == 0) {
        return;
      }
      if (DAT_3ffca1f0 != '\0') {
        return;
      }
    }
    if (_DAT_3ffca2f8 == 0) {
      FUN_40161450();
    }
  }
  return;
}

