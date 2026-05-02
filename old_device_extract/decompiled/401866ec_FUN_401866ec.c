// Function : FUN_401866ec
// Address  : 0x401866ec
// Size     : 56 bytes


void FUN_401866ec(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar1 = *(uint *)(param_2 + 4);
  iVar2 = 0;
  uVar1 = (param_3 < uVar1) * param_3 + (param_3 >= uVar1) * uVar1;
  while (iVar2 != uVar1 * 4) {
    puVar3 = (undefined4 *)(*(int *)(param_2 + 8) + iVar2);
    puVar4 = (undefined4 *)(param_1 + iVar2);
    iVar2 = iVar2 + 4;
    *puVar4 = *puVar3;
    memw();
  }
  while (uVar1 < param_3) {
    *(undefined4 *)(uVar1 * 4 + param_1) = 0;
    uVar1 = uVar1 + 1;
    memw();
  }
  return;
}

