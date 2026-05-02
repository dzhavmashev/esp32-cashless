// Function : FUN_40131188
// Address  : 0x40131188
// Size     : 308 bytes


undefined4 FUN_40131188(int *param_1,int param_2,uint param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  
  iVar5 = *param_1;
  param_2 = iVar5 - param_2;
  uVar3 = (undefined1)param_3;
  if (param_3 < 0x80) {
    uVar2 = 0xffffff94;
    if (0 < param_2) {
      *param_1 = iVar5 + -1;
      uVar2 = 1;
      *(undefined1 *)(iVar5 + -1) = uVar3;
      memw();
    }
  }
  else if (param_3 < 0x100) {
    uVar2 = 0xffffff94;
    if (1 < param_2) {
      *param_1 = iVar5 + -1;
      *(undefined1 *)(iVar5 + -1) = uVar3;
      memw();
      iVar5 = *param_1;
      *param_1 = iVar5 + -1;
      *(undefined1 *)(iVar5 + -1) = 0x81;
      memw();
      uVar2 = 2;
      memw();
    }
  }
  else {
    uVar4 = (undefined1)(param_3 >> 8);
    if (param_3 < 0x10000) {
      uVar2 = 0xffffff94;
      if (2 < param_2) {
        *param_1 = iVar5 + -1;
        *(undefined1 *)(iVar5 + -1) = uVar3;
        memw();
        iVar5 = *param_1;
        *param_1 = iVar5 + -1;
        *(undefined1 *)(iVar5 + -1) = uVar4;
        memw();
        iVar5 = *param_1;
        *param_1 = iVar5 + -1;
        *(undefined1 *)(iVar5 + -1) = 0x82;
        memw();
        uVar2 = 3;
        memw();
      }
    }
    else {
      uVar1 = (undefined1)(param_3 >> 0x10);
      if (param_3 < 0x1000000) {
        uVar2 = 0xffffff94;
        if (3 < param_2) {
          *param_1 = iVar5 + -1;
          *(undefined1 *)(iVar5 + -1) = uVar3;
          memw();
          iVar5 = *param_1;
          *param_1 = iVar5 + -1;
          *(undefined1 *)(iVar5 + -1) = uVar4;
          memw();
          iVar5 = *param_1;
          *param_1 = iVar5 + -1;
          *(undefined1 *)(iVar5 + -1) = uVar1;
          memw();
          iVar5 = *param_1;
          *param_1 = iVar5 + -1;
          *(undefined1 *)(iVar5 + -1) = 0x83;
          memw();
          uVar2 = 4;
          memw();
        }
      }
      else {
        uVar2 = 0xffffff94;
        if (4 < param_2) {
          *param_1 = iVar5 + -1;
          *(undefined1 *)(iVar5 + -1) = uVar3;
          memw();
          iVar5 = *param_1;
          *param_1 = iVar5 + -1;
          *(undefined1 *)(iVar5 + -1) = uVar4;
          memw();
          iVar5 = *param_1;
          *param_1 = iVar5 + -1;
          *(undefined1 *)(iVar5 + -1) = uVar1;
          memw();
          iVar5 = *param_1;
          *param_1 = iVar5 + -1;
          *(char *)(iVar5 + -1) = (char)(param_3 >> 0x18);
          memw();
          iVar5 = *param_1;
          *param_1 = iVar5 + -1;
          *(undefined1 *)(iVar5 + -1) = 0x84;
          memw();
          uVar2 = 5;
          memw();
        }
      }
    }
  }
  memw();
  return uVar2;
}

