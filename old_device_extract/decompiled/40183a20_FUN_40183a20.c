// Function : FUN_40183a20
// Address  : 0x40183a20
// Size     : 17 bytes


void FUN_40183a20(int param_1)

{
  if (*(code **)(param_1 + 8) != (code *)0x0) {
    (**(code **)(param_1 + 8))(param_1,param_1,3);
  }
  return;
}

