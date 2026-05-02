// Function : FUN_4013a7f4
// Address  : 0x4013a7f4
// Size     : 206 bytes


int FUN_4013a7f4(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iStack_3c;
  int local_38;
  int iStack_34;
  int iStack_30;
  undefined1 auStack_2c [44];
  
  iStack_30 = 0;
  memw();
  iStack_34 = param_2;
  iVar1 = FUN_40141738(&iStack_34,param_2 + param_3,&local_38,0x30);
  if (iVar1 != 0) {
LAB_4013a810:
    return iVar1 + -0x3d00;
  }
  iVar3 = iStack_34 + local_38;
  iVar1 = FUN_4014180c(&iStack_34,iVar3,&iStack_3c);
  if (iVar1 != 0) goto LAB_4013a810;
  if (iStack_3c != 0) {
    return -0x3d80;
  }
  iVar1 = FUN_4013a414(&iStack_34,iVar3,&iStack_30,auStack_2c);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_40141738(&iStack_34,iVar3,&local_38,4);
  if (iVar1 != 0) goto LAB_4013a810;
  if (local_38 == 0) {
    return -0x3d60;
  }
  iVar1 = FUN_40139b60(iStack_30);
  if (iVar1 == 0) {
    return -0x3c80;
  }
  iVar1 = FUN_40139b8c(param_1,iVar1);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (iStack_30 == 1) {
    uVar2 = FUN_4013a008(*param_1,param_1[1]);
    iVar1 = FUN_4013a498(uVar2,iStack_34,local_38);
  }
  else {
    if (1 < iStack_30 - 2U) {
      return -0x3c80;
    }
    uVar2 = FUN_4013a024(*param_1,param_1[1]);
    iVar1 = FUN_4013a108(auStack_2c,uVar2);
    if (iVar1 != 0) goto LAB_4013a88d;
    uVar2 = FUN_4013a024(*param_1,param_1[1]);
    iVar1 = FUN_4013a628(uVar2,iStack_34,local_38);
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_4013a88d:
  FUN_40139b44(param_1);
  return iVar1;
}

