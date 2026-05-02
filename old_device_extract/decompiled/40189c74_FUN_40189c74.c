// Function : FUN_40189c74
// Address  : 0x40189c74
// Size     : 28 bytes


void FUN_40189c74(int param_1,int param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = *(undefined4 *)(*(int *)(param_2 + 8) + 8);
  *(undefined4 *)(*(int *)(param_2 + 8) + 8) = 0;
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_2 + 0x28) = 0;
  memw();
  return;
}

