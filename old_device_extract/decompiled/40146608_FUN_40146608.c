// Function : FUN_40146608
// Address  : 0x40146608
// Size     : 231 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40146608(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    FUN_40174130("df: %s\n");
    return 0x102;
  }
  iVar1 = FUN_401464f8(*(undefined4 *)(param_1 + 4));
  if ((iVar1 != 0) || (iVar1 = FUN_4014605c(), iVar1 != 0)) {
    return iVar1;
  }
  if (_DAT_3ffbfc30 == 1) {
    iVar1 = FUN_4014659c();
    if (iVar1 == 0) {
      _DAT_3ffbfc30 = 2;
      memw();
      FUN_401460a4();
      iVar1 = FUN_4014646c(param_1);
      if (iVar1 == 0) {
        puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
        if (puVar2 == (undefined1 *)0x0) {
          iVar1 = 0x101;
        }
        else {
          *puVar2 = 0x26;
          memw();
          puVar2[8] = 0;
          *(undefined4 *)(puVar2 + 4) = 0x4014f350;
          puVar2[9] = 0;
          puVar2[10] = 0;
          memw();
          *(int *)(puVar2 + 0xc) = param_1;
          memw();
          iVar1 = FUN_40150444();
          if (iVar1 == 0) {
            FUN_4014605c();
            _DAT_3ffbfc30 = 3;
            memw();
            FUN_401460a4();
            return 0;
          }
        }
      }
    }
    FUN_40146438();
    FUN_4014605c();
    FUN_401465d4();
    _DAT_3ffbfc30 = 1;
    memw();
    FUN_401460a4();
    return iVar1;
  }
  if (_DAT_3ffbfc30 == 3) {
LAB_40146640:
    FUN_401460a4();
    return 0;
  }
  if (_DAT_3ffbfc30 == 2) {
    FUN_401460a4();
    uVar3 = 0x3f4363fd;
  }
  else {
    if (_DAT_3ffbfc30 != 4) goto LAB_40146640;
    FUN_401460a4();
    uVar3 = 0x3f4363e1;
  }
  FUN_40147fe4(1,2,2,uVar3);
  return 0x3013;
}

