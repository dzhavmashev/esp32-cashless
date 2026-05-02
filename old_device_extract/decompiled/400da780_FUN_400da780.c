// Function : FUN_400da780
// Address  : 0x400da780
// Size     : 27 bytes


void FUN_400da780(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(int *)(param_1 + 8) == 0) {
    FUN_40170584(param_1,param_2,param_3);
  }
  (**(code **)(param_1 + 0xc))();
  return;
}

