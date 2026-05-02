// Function : FUN_4011acbc
// Address  : 0x4011acbc
// Size     : 32 bytes


char FUN_4011acbc(int *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)&SUB_4008fcc8)(1);
  *param_1 = iVar1;
  memw();
  return -(iVar1 == 0);
}

