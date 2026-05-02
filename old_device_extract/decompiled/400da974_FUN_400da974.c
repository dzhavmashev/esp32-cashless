// Function : FUN_400da974
// Address  : 0x400da974
// Size     : 77 bytes


undefined2 * FUN_400da974(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 *puVar2;
  
  if (*(undefined2 **)(param_1 + 4) != param_2 + 0xc) {
    puVar2 = param_2;
    for (iVar1 = ((int)*(undefined2 **)(param_1 + 4) - (int)(param_2 + 0xc) >> 3) * -0x55555555;
        0 < iVar1; iVar1 = iVar1 + -1) {
      *puVar2 = puVar2[0xc];
      FUN_400f0d60(puVar2 + 2,puVar2 + 0xe);
      *(undefined4 *)(puVar2 + 10) = *(undefined4 *)(puVar2 + 0x16);
      puVar2 = puVar2 + 0xc;
    }
  }
  iVar1 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = iVar1 + -0x18;
  FUN_400f0a50(iVar1 + -0x14);
  return param_2;
}

