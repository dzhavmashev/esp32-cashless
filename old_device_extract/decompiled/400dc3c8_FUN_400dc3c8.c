// Function : FUN_400dc3c8
// Address  : 0x400dc3c8
// Size     : 114 bytes


void FUN_400dc3c8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((*(char *)(param_1 + 0x70) != '\0') && (*(char *)(param_1 + 0x30) != '\0')) {
    iVar1 = FUN_400f1a9c();
    *(undefined1 *)(param_1 + 0x70) = 0;
    *(int *)(param_1 + 0x78) = (*(int *)(param_1 + 0x78) - *(int *)(param_1 + 0x74)) + iVar1;
    *(undefined4 *)(param_1 + 0x74) = 0;
    iVar1 = FUN_400dc350(param_1);
    if ((iVar1 != 0) && (*(int *)(param_1 + 0x48) != 0)) {
      func_0x4009246c(*(int *)(param_1 + 0x48),4,(uint)(iVar1 * 1000000) / 1000,0,0);
      uVar2 = *(undefined4 *)(param_1 + 0x48);
      uVar3 = func_0x40090b58();
      func_0x4009246c(uVar2,1,uVar3,0,0);
    }
    FUN_400f06a4(0x3ffc5490,"ion %s\n",iVar1);
  }
  return;
}

