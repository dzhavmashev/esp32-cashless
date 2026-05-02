// Function : FUN_40189cdc
// Address  : 0x40189cdc
// Size     : 30 bytes


void FUN_40189cdc(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  param_1 = param_1 - (int)param_2;
  while( true ) {
    param_3 = param_3 + -1;
    puVar1 = (undefined4 *)((int)param_2 + param_1);
    if (param_3 == -1) break;
    uVar2 = *param_2;
    param_2 = param_2 + 1;
    memw();
    *puVar1 = uVar2;
  }
  memw();
  return;
}

