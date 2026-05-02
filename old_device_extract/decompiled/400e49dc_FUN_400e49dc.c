// Function : FUN_400e49dc
// Address  : 0x400e49dc
// Size     : 102 bytes


void FUN_400e49dc(int param_1)

{
  if (*(int *)(param_1 + 500) != 0) {
    FUN_4016fffc();
  }
  if (*(int **)(param_1 + 0x1bc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x1bc) + 4))();
  }
  (*(code *)&LAB_40183a17_1)(param_1 + 0x1e0);
  (*(code *)&LAB_40183a17_1)(param_1 + 0x1d0);
  (*(code *)&LAB_40183a17_1)(param_1 + 0x1c0);
  FUN_400eea5c(param_1 + 0xfc);
  FUN_400e486c(param_1 + 0x5c);
  FUN_400f0a50(param_1 + 0x3c);
  FUN_400f0a50(param_1 + 0x2c);
  FUN_400f0a50(param_1 + 0x1c);
  FUN_400f0a50(param_1 + 0xc);
  return;
}

