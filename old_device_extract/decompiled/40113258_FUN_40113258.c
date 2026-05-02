// Function : FUN_40113258
// Address  : 0x40113258
// Size     : 43 bytes


void FUN_40113258(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (0x3fffffff < param_1) {
    (*(code *)&SUB_40094c54)("s empty",0x13e,"4 msecs","eouts.c");
  }
  iVar1 = FUN_4011b010();
  FUN_401131cc(iVar1 + param_1,param_2,param_3);
  return;
}

