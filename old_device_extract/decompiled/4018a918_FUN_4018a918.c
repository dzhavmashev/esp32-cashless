// Function : FUN_4018a918
// Address  : 0x4018a918
// Size     : 93 bytes


void FUN_4018a918(char param_1,char param_2)

{
  int iVar1;
  
  iVar1 = FUN_4018c018();
  if (iVar1 != 0) {
    FUN_40161150();
    if (DAT_3ffca1d9 == '\x01') {
      if (DAT_3ffca1f0 != '\0') {
        if (param_1 == '\0') {
          DAT_3ffca1ea = param_2 != '\0';
          memw();
          memw();
          return;
        }
        if (param_2 != '\0') {
          DAT_3ffca1ea = DAT_3ffca1d9;
          memw();
          memw();
          FUN_4018b360();
          return;
        }
        memw();
        memw();
        DAT_3ffca1ea = param_2;
        FUN_4018b34c();
        FUN_401612fc();
        return;
      }
    }
    else if (DAT_3ffca1d9 == '\0') {
      FUN_4018a8a8();
    }
  }
  return;
}

