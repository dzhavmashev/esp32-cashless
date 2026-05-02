// Function : FUN_400db5c4
// Address  : 0x400db5c4
// Size     : 41 bytes


undefined2 * FUN_400db5c4(undefined2 *param_1,undefined2 *param_2,undefined2 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0xc) {
    *param_3 = *param_1;
    FUN_400f0d4c(param_3 + 2,param_1 + 2);
    *(undefined4 *)(param_3 + 10) = *(undefined4 *)(param_1 + 10);
    param_3 = param_3 + 0xc;
  }
  return param_3;
}

