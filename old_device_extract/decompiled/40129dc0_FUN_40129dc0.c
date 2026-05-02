// Function : FUN_40129dc0
// Address  : 0x40129dc0
// Size     : 96 bytes


void FUN_40129dc0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  FUN_4012998c(*(undefined4 *)(*(int *)(param_1 + 0x44) + 0x24c));
  iVar2 = *(int *)(param_1 + 0x44);
  *(undefined4 *)(iVar2 + 0x24c) = 0;
  *(undefined4 *)(iVar2 + 0x250) = 0;
  *(undefined4 *)(iVar2 + 600) = *(undefined4 *)(iVar2 + 0x23c);
  *(undefined1 *)(iVar2 + 0x1f8) = 0;
  memw();
  memw();
  FUN_40129da0(param_1);
  FUN_40185804(param_1,0);
  if ((*(int *)(param_1 + 0x80) == 0x16) && (**(char **)(param_1 + 0x78) == '\x14')) {
    uVar1 = 3;
  }
  else {
    uVar1 = 0;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 7) = uVar1;
  memw();
  memw();
  return;
}

