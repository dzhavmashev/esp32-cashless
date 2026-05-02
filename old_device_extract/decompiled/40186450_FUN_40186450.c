// Function : FUN_40186450
// Address  : 0x40186450
// Size     : 36 bytes


void FUN_40186450(uint *param_1,uint param_2,char *param_3)

{
  *param_3 = *param_3 - (*param_1 < param_2);
  memw();
  *param_1 = *param_1 - param_2;
  memw();
  return;
}

