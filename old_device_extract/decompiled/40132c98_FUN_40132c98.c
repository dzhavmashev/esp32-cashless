// Function : FUN_40132c98
// Address  : 0x40132c98
// Size     : 27 bytes


void FUN_40132c98(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (param_1[0xf] != 0) {
      (**(code **)(*(int *)(*param_1 + 0x1c) + 0x28))();
    }
    FUN_4013ae54(param_1,0x40);
  }
  return;
}

