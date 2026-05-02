// Function : FUN_400fc0d8
// Address  : 0x400fc0d8
// Size     : 76 bytes


int FUN_400fc0d8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x1105;
  if ((*(int *)(param_1 + 0x14) != 0) &&
     ((iVar1 = *(int *)(param_1 + 0xc), *(int *)(iVar1 + 0xc) != -0x10 ||
      (iVar2 = FUN_400fb46c(iVar1), iVar2 == 0)))) {
    FUN_40184bd0(param_1 + 0xc,*(undefined4 *)(param_1 + 0xc));
    FUN_40184bac(param_1,iVar1);
    FUN_400fb454(iVar1,*(undefined4 *)(param_1 + 0x24));
    iVar2 = 0;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  }
  memw();
  return iVar2;
}

