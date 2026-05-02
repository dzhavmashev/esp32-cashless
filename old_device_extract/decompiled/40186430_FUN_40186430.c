// Function : FUN_40186430
// Address  : 0x40186430
// Size     : 32 bytes


void FUN_40186430(uint *param_1,uint param_2,char *param_3)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = param_2 + uVar1;
  *param_3 = *param_3 + (param_2 + uVar1 < param_2);
  memw();
  memw();
  return;
}

