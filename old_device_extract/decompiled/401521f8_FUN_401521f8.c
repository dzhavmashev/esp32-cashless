// Function : FUN_401521f8
// Address  : 0x401521f8
// Size     : 152 bytes


void FUN_401521f8(int param_1,int param_2)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);
  if (*(int *)(&DAT_3ffc8930 + (uint)*(byte *)(param_1 + 0x134) * 4) == 0) {
    **(uint **)(param_2 + 0x2c) = **(uint **)(param_2 + 0x2c) & 0xfffffffe;
    *(byte *)(iVar2 + 1) = *(byte *)(iVar2 + 1) & 0xbf;
    memw();
    memw();
    return;
  }
  if (**(int **)(*(int *)(&DAT_3ffc8930 + (uint)*(byte *)(param_1 + 0x134) * 4) + 0xa0) == 3) {
    FUN_4015f1dc(param_2);
  }
  else {
    *(int *)(*(int *)(param_2 + 4) + 4) = iVar2 + 0x20;
    memw();
    puVar1 = (undefined2 *)FUN_40147b98(param_1,param_2);
    *(int *)(*(int *)(param_2 + 4) + 4) = *(int *)(*(int *)(param_2 + 4) + 4) + -0x18;
    *(char *)(*(int *)(param_2 + 0x2c) + 0x10) = (char)*puVar1;
    memw();
    *(uint *)(*(int *)(param_2 + 0x2c) + 0x10) =
         *(uint *)(*(int *)(param_2 + 0x2c) + 0x10) & 0xfffff0ff |
         (**(byte **)(puVar1 + 0x50) & 0xf) << 8;
  }
  *(uint *)(*(int *)(param_2 + 0x2c) + 0x14) = *(uint *)(*(int *)(param_2 + 0x2c) + 0x14) | 4;
  memw();
  return;
}

