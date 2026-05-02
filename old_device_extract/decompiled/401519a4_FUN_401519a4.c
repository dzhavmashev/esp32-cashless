// Function : FUN_401519a4
// Address  : 0x401519a4
// Size     : 54 bytes


bool FUN_401519a4(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(uint *)(param_1 + 0xc) &
      (uint)(*(int *)(&DAT_3ffc8930 + (uint)*(byte *)(param_1 + 0x134) * 4) != 0)) != 0) {
    bVar1 = **(int **)(*(int *)(&DAT_3ffc8930 + (uint)*(byte *)(param_1 + 0x134) * 4) + 0xa0) == 4;
  }
  return bVar1;
}

