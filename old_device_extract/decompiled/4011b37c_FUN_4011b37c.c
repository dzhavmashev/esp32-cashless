// Function : FUN_4011b37c
// Address  : 0x4011b37c
// Size     : 21 bytes


void FUN_4011b37c(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_4011adc4(param_1);
  if ((param_2 != (undefined4 *)0x0) && (iVar1 != 0)) {
    *param_2 = 1;
  }
  memw();
  return;
}

