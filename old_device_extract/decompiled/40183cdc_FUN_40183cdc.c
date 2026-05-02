// Function : FUN_40183cdc
// Address  : 0x40183cdc
// Size     : 20 bytes


undefined4 FUN_40183cdc(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  if (param_3 != 1) {
    if (param_3 != 2) {
      return 0;
    }
    param_2 = (undefined4 *)*param_2;
  }
  *param_1 = param_2;
  return 0;
}

