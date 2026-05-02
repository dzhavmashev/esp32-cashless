// Function : FUN_4011afb0
// Address  : 0x4011afb0
// Size     : 38 bytes


undefined4
FUN_4011afb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 auStack_24 [9];
  
  memw();
  iVar1 = (*(code *)&SUB_4009092c)(param_2,param_1,param_4,param_3,param_5,auStack_24,0);
  uVar2 = 0;
  if (iVar1 == 1) {
    uVar2 = auStack_24[0];
  }
  return uVar2;
}

