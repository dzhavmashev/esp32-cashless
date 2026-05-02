// Function : FUN_4012998c
// Address  : 0x4012998c
// Size     : 26 bytes


void FUN_4012998c(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  while (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)param_1[3];
    FUN_4013ae44(*param_1);
    FUN_4013ae44(param_1);
    param_1 = puVar1;
  }
  return;
}

