// Function : FUN_4013905c
// Address  : 0x4013905c
// Size     : 179 bytes


undefined4 FUN_4013905c(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_2 == 0) || (param_1 == (int *)0x0)) {
LAB_40139084:
    memw();
    return 0xffffaf00;
  }
  uVar2 = *(uint *)(param_2 + 4);
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  if (uVar2 < 7) {
    if (uVar2 < 5) {
      if (uVar2 == 3) {
        iVar1 = FUN_4013ae30(1,0x58);
        param_1[1] = iVar1;
        if (iVar1 == 0) goto LAB_401390a5;
        FUN_401416d8();
      }
      else {
        if (uVar2 != 4) goto LAB_40139084;
        iVar1 = FUN_4013ae30(1,0x60);
        param_1[1] = iVar1;
        if (iVar1 == 0) goto LAB_401390a5;
        memw();
        FUN_4013ec3c();
      }
    }
    else {
      iVar1 = FUN_4013ae30(1,0x70);
      param_1[1] = iVar1;
      if (iVar1 == 0) goto LAB_401390a5;
      memw();
      FUN_4013f784();
    }
  }
  else {
    if (8 < uVar2) {
      return 0xffffaf00;
    }
    iVar1 = FUN_4013ae30(1,0xd8);
    param_1[1] = iVar1;
    if (iVar1 == 0) goto LAB_401390a5;
    memw();
    FUN_4014098c();
  }
  if (param_3 != 0) {
    iVar1 = FUN_4013ae30(2,*(undefined1 *)(param_2 + 9));
    param_1[2] = iVar1;
    if (iVar1 == 0) {
      memw();
      FUN_40138f78(param_1);
LAB_401390a5:
      memw();
      return 0xffffae80;
    }
  }
  return 0;
}

