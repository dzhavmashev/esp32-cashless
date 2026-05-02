// Function : FUN_401850cc
// Address  : 0x401850cc
// Size     : 43 bytes


void FUN_401850cc(uint *param_1,uint *param_2)

{
  *param_1 = *param_1 ^ *param_2;
  param_1[1] = param_1[1] ^ param_2[1];
  param_1[2] = param_1[2] ^ param_2[2];
  param_1[3] = param_1[3] ^ param_2[3];
  memw();
  return;
}

