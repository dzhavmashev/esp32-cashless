// Function : FUN_40171218
// Address  : 0x40171218
// Size     : 16 bytes


void FUN_40171218(int param_1)

{
  if (*(code **)(param_1 + 8) != (code *)0x0) {
    (**(code **)(param_1 + 8))(1,param_1);
  }
  return;
}

