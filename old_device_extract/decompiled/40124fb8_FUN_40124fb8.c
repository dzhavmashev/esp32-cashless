// Function : FUN_40124fb8
// Address  : 0x40124fb8
// Size     : 58 bytes


void FUN_40124fb8(undefined4 *param_1)

{
  param_1[0x45] = 0;
  memw();
  (*(code *)&SUB_4008b530)(param_1 + 0x2b,0,0x68);
  FUN_4015a608(0,param_1 + 2,0,0,0);
  param_1[0x46] = 0;
  memw();
  FUN_4018509c(&DAT_40125480,*param_1,param_1);
  return;
}

