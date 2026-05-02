// Function : FUN_400e6444
// Address  : 0x400e6444
// Size     : 23 bytes


void FUN_400e6444(int param_1)

{
  if (*(int *)(param_1 + 8) == 0) {
    FUN_40170584(param_1);
  }
  (**(code **)(param_1 + 0xc))();
  return;
}

