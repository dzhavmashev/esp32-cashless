// Function : FUN_4013f798
// Address  : 0x4013f798
// Size     : 41 bytes


void FUN_4013f798(undefined1 *param_1)

{
  undefined1 *puVar1;
  
  if (param_1 != (undefined1 *)0x0) {
    if (*(int *)(param_1 + 0x6c) == 1) {
      FUN_40143664();
    }
    puVar1 = param_1 + 0x70;
    while (param_1 != puVar1) {
      memw();
      *param_1 = 0;
      param_1 = param_1 + 1;
      memw();
    }
  }
  return;
}

