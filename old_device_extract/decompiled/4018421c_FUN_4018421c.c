// Function : FUN_4018421c
// Address  : 0x4018421c
// Size     : 16 bytes


void FUN_4018421c(int param_1)

{
  if (*(code **)(param_1 + 8) != (code *)0x0) {
    (**(code **)(param_1 + 8))(param_1,param_1,3);
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}

