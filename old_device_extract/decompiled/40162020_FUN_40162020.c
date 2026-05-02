// Function : FUN_40162020
// Address  : 0x40162020
// Size     : 87 bytes


void FUN_40162020(char param_1,char param_2,char param_3)

{
  int iVar1;
  
  if ((param_1 != '\0') && ((DAT_3ffc1a44 == '\0' || (param_2 == '\0')))) {
    FUN_40161130();
    FUN_4018b8d8();
  }
  iVar1 = FUN_40163758(1);
  if (iVar1 == 0) {
    if (DAT_3ffca1e5 == '\0') {
      FUN_4016133c();
    }
    else if (DAT_3ffca1d9 == '\x01') {
      FUN_401612fc();
    }
  }
  iVar1 = FUN_4018c018();
  if (iVar1 != 0) {
    if (param_3 != '\0') {
      FUN_40161150();
    }
    if (DAT_3ffca1d9 == '\0') {
      FUN_4018a8a8();
    }
  }
  return;
}

