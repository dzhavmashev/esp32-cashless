// Function : FUN_4010bdcc
// Address  : 0x4010bdcc
// Size     : 60 bytes


void FUN_4010bdcc(undefined4 *param_1,ushort param_2)

{
  undefined4 *puVar1;
  
  while ((param_2 != 0 && (param_1 != (undefined4 *)0x0))) {
    if (param_2 < *(ushort *)((int)param_1 + 10)) {
      FUN_4010ba9c(param_1,param_2);
      param_2 = 0;
    }
    else {
      param_2 = param_2 - *(ushort *)((int)param_1 + 10);
      puVar1 = (undefined4 *)*param_1;
      *param_1 = 0;
      memw();
      FUN_4010bb10(param_1);
      param_1 = puVar1;
    }
  }
  return;
}

