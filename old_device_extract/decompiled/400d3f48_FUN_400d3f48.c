// Function : FUN_400d3f48
// Address  : 0x400d3f48
// Size     : 44 bytes


undefined4 FUN_400d3f48(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x24) + 1U < 0x20) || (iVar2 = FUN_400d3f28(param_1), iVar2 == 0)) {
    iVar2 = *(int *)(param_1 + 0x24);
    *(int *)(param_1 + 0x24) = iVar2 + 1;
    *(undefined1 *)(param_1 + iVar2 + 4) = param_2;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

