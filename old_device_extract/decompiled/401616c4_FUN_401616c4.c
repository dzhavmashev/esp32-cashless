// Function : FUN_401616c4
// Address  : 0x401616c4
// Size     : 114 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401616c4(void)

{
  int iVar1;
  
  if ((DAT_3ffca2f5 < 2) && (DAT_3ffca1e5 == '\0')) {
    return;
  }
  if (DAT_3ffca1e6 != '\0') {
    return;
  }
  DAT_3ffca1e6 = 1;
  memw();
  if (DAT_3ffca1e5 == '\0') {
    memw();
    FUN_401615bc();
    return;
  }
  iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
  if ((iVar1 == 0) &&
     (((DAT_3ffca2f4 != '\0' && (DAT_3ffca1eb == '\0')) || (iVar1 = FUN_40163758(1), iVar1 != 0))))
  {
    FUN_401613ec(0);
  }
  DAT_3ffca2f4 = 0;
  memw();
  memw();
  FUN_401615bc();
  FUN_4018a8a8();
  return;
}

