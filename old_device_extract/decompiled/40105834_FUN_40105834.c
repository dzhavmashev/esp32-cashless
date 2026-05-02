// Function : FUN_40105834
// Address  : 0x40105834
// Size     : 92 bytes


void FUN_40105834(undefined4 param_1,byte *param_2,uint param_3,byte *param_4)

{
  byte *pbVar1;
  
  pbVar1 = param_2 + (param_3 & 0xfffffff0);
  for (; param_2 != pbVar1; param_2 = param_2 + 0x10) {
    FUN_401850c4(param_4,param_2);
    FUN_401021b8(param_1,param_4,param_4);
  }
  if ((param_3 & 0xf) != 0) {
    *param_4 = *pbVar1 ^ *param_4;
    memw();
    memw();
    FUN_401021b8(param_1,param_4,param_4);
  }
  return;
}

