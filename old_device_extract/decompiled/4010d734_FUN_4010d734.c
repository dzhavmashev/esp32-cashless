// Function : FUN_4010d734
// Address  : 0x4010d734
// Size     : 313 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4010d734(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char cStack_28;
  char cStack_27;
  char cStack_26;
  char cStack_25;
  char cStack_24;
  byte bStack_21;
  
  FUN_4010c96c(&cStack_28);
  if (0xf < bStack_21) {
    if (cStack_28 == '\0') {
      uVar3 = 9;
      if (cStack_25 == '\0') {
        if (cStack_27 == '\0') {
          uVar3 = 6;
          if ((cStack_26 == '\0') && (uVar3 = 5, cStack_24 == '\0')) {
            FUN_4010d520(param_1);
            goto LAB_4010d750;
          }
        }
        else {
          uVar3 = 8;
        }
      }
      FUN_4010d6fc(uVar3);
    }
    else {
      FUN_4010d4ec();
    }
  }
LAB_4010d750:
  FUN_4010c96c(&cStack_28);
  if (bStack_21 < 0x10) {
    iVar1 = FUN_4010b058(2);
    iVar2 = _DAT_3ffc840c;
    if (iVar1 == 0) {
      while (iVar1 = iVar2, iVar1 != 0) {
        iVar2 = *(int *)(iVar1 + 0x34);
        if ((*(ushort *)(iVar1 + 0x46) & 8) != 0) {
          *(ushort *)(iVar1 + 0x46) = *(ushort *)(iVar1 + 0x46) & 0xfff7;
          memw();
          memw();
          FUN_4010caf4();
        }
      }
      FUN_4010d4ec();
      iVar1 = FUN_4010b058(2);
      if (iVar1 == 0) {
        FUN_4010d6fc(9);
        iVar1 = FUN_4010b058(2);
        if (iVar1 == 0) {
          FUN_4010d6fc(8);
          iVar1 = FUN_4010b058(2);
          if (iVar1 == 0) {
            FUN_4010d520(param_1);
            iVar1 = FUN_4010b058(2);
            if (iVar1 == 0) goto LAB_4010d75d;
          }
        }
      }
    }
    (*(code *)&SUB_4008b530)(iVar1,0,0xd0);
    *(undefined1 *)(iVar1 + 0x40) = param_1;
    memw();
    *(undefined2 *)(iVar1 + 0x90) = 0x1680;
    memw();
    *(undefined4 *)(iVar1 + 0x54) = 0x16801680;
    *(undefined1 *)(iVar1 + 0x33) = 0x40;
    *(undefined2 *)(iVar1 + 0x6c) = 6;
    *(undefined2 *)(iVar1 + 0x6a) = 6;
    memw();
    *(undefined4 *)(iVar1 + 0x5c) = 0x218ffff;
    *(undefined4 *)(iVar1 + 0x4c) = _DAT_3ffc8414;
    *(undefined1 *)(iVar1 + 0x4a) = DAT_3ffc6334;
    memw();
    *(undefined4 *)(iVar1 + 0x74) = 0x16800001;
    *(undefined4 *)(iVar1 + 0xb0) = 0x4010da2c;
    *(undefined4 *)(iVar1 + 0xc0) = 7200000;
    *(undefined4 *)(iVar1 + 0xc4) = 75000;
    *(undefined4 *)(iVar1 + 200) = 9;
    memw();
  }
  else {
LAB_4010d75d:
    iVar1 = 0;
  }
  return iVar1;
}

