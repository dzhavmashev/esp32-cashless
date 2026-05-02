// Function : FUN_4010670c
// Address  : 0x4010670c
// Size     : 59 bytes


void FUN_4010670c(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    *param_1 = 0;
    while (puVar1 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar1;
      (*(code *)&SUB_40094d80)();
    }
    memw();
    FUN_401063f0(param_1);
    (*(code *)&SUB_40085a10)(param_1[3]);
    FUN_4011f8dc(param_1[3]);
    (*(code *)&SUB_40094d80)(param_1);
  }
  return;
}

