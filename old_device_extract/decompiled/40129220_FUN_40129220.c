// Function : FUN_40129220
// Address  : 0x40129220
// Size     : 63 bytes


int FUN_40129220(int param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  (*(code *)&SUB_4008b530)(param_1,0,0xc);
  (*(code *)&SUB_4008b3d0)(param_1,param_2,param_3);
  *(byte *)(param_1 + 4) = *param_4 ^ *(byte *)(param_1 + 4);
  memw();
  memw();
  return param_1 + 5;
}

