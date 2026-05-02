// Function : FUN_4012c88c
// Address  : 0x4012c88c
// Size     : 121 bytes


undefined4 FUN_4012c88c(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)&SUB_4008c01c)(param_2);
    if (0xff < uVar1) {
      return 0xffff8f00;
    }
  }
  iVar3 = *(int *)(param_1 + 0xec);
  if (iVar3 != 0) {
    uVar2 = (*(code *)&SUB_4008c01c)(iVar3);
    FUN_4013ae54(iVar3,uVar2);
    FUN_4013ae44(*(undefined4 *)(param_1 + 0xec));
  }
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0xec) = 0;
  }
  else {
    iVar3 = FUN_4013ae30(1,uVar1 + 1);
    *(int *)(param_1 + 0xec) = iVar3;
    if (iVar3 == 0) {
      return 0xffff8100;
    }
    memw();
    (*(code *)&SUB_4008b3d0)(iVar3,param_2,uVar1);
    *(undefined1 *)(*(int *)(param_1 + 0xec) + uVar1) = 0;
    memw();
    memw();
  }
  memw();
  return 0;
}

