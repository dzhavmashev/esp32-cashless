// Function : FUN_40146710
// Address  : 0x40146710
// Size     : 200 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40146710(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4014605c();
  if (iVar1 == 0) {
    if (1 < DAT_3ffc89d9) {
      FUN_401460a4();
      FUN_40147fe4(1,3,1,"memory!");
      return 0x3003;
    }
    if (_DAT_3ffbfc30 != 3) {
      if (_DAT_3ffbfc30 == 1) {
        FUN_401460a4();
        return 0x3001;
      }
      if (_DAT_3ffbfc30 == 2) {
        FUN_401460a4();
        uVar3 = 0x3f4363c5;
      }
      else {
        if (_DAT_3ffbfc30 != 4) {
LAB_401467bc:
          memw();
          FUN_401460a4();
          return 0;
        }
        FUN_401460a4();
        uVar3 = 0x3f4363a7;
      }
      FUN_40147fe4(1,2,2,uVar3);
      return 0x3013;
    }
    _DAT_3ffbfc30 = 4;
    memw();
    FUN_401460a4();
    puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
    if (puVar2 == (undefined1 *)0x0) {
      iVar1 = 0x101;
    }
    else {
      *puVar2 = 0;
      memw();
      *(undefined **)(puVar2 + 4) = &DAT_4014f40c;
      memw();
      iVar1 = FUN_40150444();
      if (iVar1 == 0) {
        FUN_40146438();
        FUN_4014605c();
        FUN_401465d4();
        _DAT_3ffbfc30 = 1;
        goto LAB_401467bc;
      }
    }
    FUN_4014605c();
    _DAT_3ffbfc30 = 3;
    memw();
    FUN_401460a4();
  }
  return iVar1;
}

