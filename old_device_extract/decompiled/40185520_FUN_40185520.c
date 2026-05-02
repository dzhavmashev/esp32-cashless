// Function : FUN_40185520
// Address  : 0x40185520
// Size     : 47 bytes


undefined4 * FUN_40185520(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1 == param_2) {
      *param_1 = puVar1[1];
      param_1 = (undefined4 *)0x0;
      puVar1[1] = 0;
    }
    else {
      do {
        param_1 = (undefined4 *)puVar1[1];
        if (param_1 == param_2) {
          param_1 = (undefined4 *)param_2[1];
          puVar1[1] = param_1;
          param_2[1] = 0;
        }
        puVar1 = (undefined4 *)puVar1[1];
      } while (puVar1 != (undefined4 *)0x0);
      memw();
    }
  }
  memw();
  return param_1;
}

