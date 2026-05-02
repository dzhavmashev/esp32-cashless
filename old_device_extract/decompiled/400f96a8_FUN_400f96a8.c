// Function : FUN_400f96a8
// Address  : 0x400f96a8
// Size     : 56 bytes


int FUN_400f96a8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piStack_28;
  undefined4 auStack_24 [9];
  
  FUN_400f9390();
  iVar1 = FUN_400f9350(param_1,&piStack_28);
  if (iVar1 == 0) {
    memw();
    auStack_24[0] = param_3;
    iVar1 = (**(code **)(*piStack_28 + 0x2c))(piStack_28,0x14,param_2,auStack_24,4);
  }
  FUN_400f9378();
  return iVar1;
}

