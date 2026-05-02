// Function : FUN_401315c4
// Address  : 0x401315c4
// Size     : 64 bytes


undefined4 FUN_401315c4(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    FUN_40131548(param_1);
  }
  else {
    if (param_1[1] != param_2) {
      FUN_40131548(param_1);
      uVar1 = FUN_40131574(param_1,param_2);
      return uVar1;
    }
    (*(code *)&SUB_4008b530)(param_1[2],0,param_1[1] << 2);
    *param_1 = 1;
    memw();
  }
  return 0;
}

