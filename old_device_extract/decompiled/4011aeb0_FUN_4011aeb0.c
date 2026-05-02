// Function : FUN_4011aeb0
// Address  : 0x4011aeb0
// Size     : 41 bytes


char FUN_4011aeb0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 auStack_24 [9];
  
  memw();
  auStack_24[0] = param_2;
  iVar1 = (*(code *)&SUB_4008fab8)(*(undefined4 *)*param_1,auStack_24,0);
  return -(iVar1 != 1);
}

