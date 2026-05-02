// Function : FUN_400d7378
// Address  : 0x400d7378
// Size     : 48 bytes


void FUN_400d7378(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = param_2 + 3U & 0xfffffffc;
  iVar2 = 0;
  iVar3 = 0;
  if (uVar1 != 0) {
    iVar3 = func_0x40094d68(uVar1);
    iVar2 = 0;
    if (iVar3 != 0) {
      iVar2 = iVar3 + uVar1;
    }
  }
  *(int *)(param_1 + 8) = iVar3;
  *(int *)(param_1 + 0xc) = iVar3;
  *(int *)(param_1 + 0x10) = iVar2;
  *(int *)(param_1 + 0x14) = iVar2;
  *(undefined1 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  return;
}

