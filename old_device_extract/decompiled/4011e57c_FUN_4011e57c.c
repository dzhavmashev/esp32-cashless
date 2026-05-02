// Function : FUN_4011e57c
// Address  : 0x4011e57c
// Size     : 62 bytes


void FUN_4011e57c(int param_1,uint param_2)

{
  int iVar1;
  undefined4 auStack_24 [9];
  
  if (param_1 != 0) goto LAB_4011e5b5;
  (*(code *)&SUB_40094c54)("support/hw_random.c",0x46,"andom.c","sed > 0");
  do {
    auStack_24[0] = (*(code *)&SUB_400842fc)();
    iVar1 = (param_2 < 4) * param_2 + (uint)(param_2 >= 4) * 4;
    memw();
    (*(code *)&SUB_4008b3d0)(param_1,auStack_24,iVar1);
    param_1 = param_1 + iVar1;
    param_2 = param_2 - iVar1;
LAB_4011e5b5:
  } while (param_2 != 0);
  return;
}

