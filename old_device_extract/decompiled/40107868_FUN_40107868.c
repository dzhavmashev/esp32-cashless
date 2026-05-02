// Function : FUN_40107868
// Address  : 0x40107868
// Size     : 34 bytes


void FUN_40107868(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    (*(code *)&SUB_400902d4)(*param_1);
    if (param_1[1] != 0) {
      (*(code *)&SUB_40094d80)();
    }
    (*(code *)&SUB_40094d80)(param_1);
  }
  return;
}

