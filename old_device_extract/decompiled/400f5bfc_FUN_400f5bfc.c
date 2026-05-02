// Function : FUN_400f5bfc
// Address  : 0x400f5bfc
// Size     : 54 bytes


undefined4 FUN_400f5bfc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 * 4 + 0x3ffc5588);
  iVar3 = *(int *)(iVar2 + 0xa4) + 1;
  if (*(int *)(iVar2 + 0xac) <= iVar3) {
    iVar3 = 0;
  }
  uVar1 = 0xffffffff;
  if (*(int *)(iVar2 + 0xa8) != iVar3) {
    uVar1 = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0xb0) + *(int *)(iVar2 + 0xa4) * 4) = param_2;
    *(int *)(iVar2 + 0xa4) = iVar3;
  }
  memw();
  return uVar1;
}

