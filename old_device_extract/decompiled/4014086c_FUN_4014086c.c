// Function : FUN_4014086c
// Address  : 0x4014086c
// Size     : 94 bytes


undefined4 FUN_4014086c(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0xd4) == 0) {
    uVar1 = 3;
    if (*(int *)(param_1 + 0xd0) != 0) {
      uVar1 = 2;
    }
    iVar2 = FUN_40143650(uVar1);
    uVar1 = 2;
    if (iVar2 != 0) {
      uVar1 = 1;
    }
    *(undefined4 *)(param_1 + 0xd4) = uVar1;
  }
  if (*(int *)(param_1 + 0xd4) == 1) {
    uVar1 = 3;
    if (*(int *)(param_1 + 0xd0) != 0) {
      uVar1 = 2;
    }
    memw();
    FUN_401436e4(uVar1,param_2);
    uVar1 = 3;
    if (param_3 != 0) {
      if (*(int *)(param_1 + 0xd0) != 0) {
        uVar1 = 2;
      }
      FUN_401436b0(uVar1,param_1 + 0x10);
    }
  }
  else {
    FUN_4013fa98(param_1,param_2,iVar2);
  }
  return 0;
}

