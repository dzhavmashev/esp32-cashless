// Function : FUN_40139b44
// Address  : 0x40139b44
// Size     : 28 bytes


void FUN_40139b44(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      (**(code **)(*param_1 + 0x28))(param_1[1]);
    }
    FUN_4013ae54(param_1,8);
  }
  return;
}

