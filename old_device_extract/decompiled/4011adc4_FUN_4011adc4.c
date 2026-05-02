// Function : FUN_4011adc4
// Address  : 0x4011adc4
// Size     : 33 bytes


bool FUN_4011adc4(undefined4 *param_1)

{
  int aiStack_24 [9];
  
  aiStack_24[0] = 0;
  memw();
  (*(code *)&SUB_4008fde8)(*param_1,aiStack_24);
  return aiStack_24[0] == 1;
}

