// Function : FUN_400eb730
// Address  : 0x400eb730
// Size     : 141 bytes


bool FUN_400eb730(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x680);
  if (iVar2 != 0) {
    iVar3 = iVar2 + 4;
    iVar4 = *(int *)(param_1 + 0x688);
    iVar1 = (*(code *)&LAB_40184497_1)(iVar3);
    if (iVar4 == iVar1) {
      iVar2 = FUN_401844a8(iVar3);
      if (iVar2 == 0xe0) {
        (*(code *)&LAB_40184472_2)(param_1 + 0xb0,7);
        *(undefined1 *)(param_1 + 0x765) = 0;
      }
      iVar2 = FUN_400ebbfc(iVar3);
      if (iVar2 == 0) {
        iVar2 = FUN_401844a8(iVar3);
        if (iVar2 == 0x30) {
          FUN_400ebbd4(iVar3);
        }
        iVar2 = *(int *)(param_1 + 0x680);
        if (iVar2 != 0) {
          *(int *)(param_1 + 0x684) = iVar2;
          *(undefined4 *)(param_1 + 0x680) = *(undefined4 *)(iVar2 + 0x2c);
        }
      }
      else {
        FUN_400eadcc(param_1 + 0x678,*(undefined4 *)(param_1 + 0x684),
                     *(undefined4 *)(param_1 + 0x680));
      }
      iVar2 = *(int *)(param_1 + 0x680);
      *(undefined4 *)(param_1 + 0x688) = 0;
    }
  }
  return iVar2 != 0;
}

