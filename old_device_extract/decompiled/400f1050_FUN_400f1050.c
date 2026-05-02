// Function : FUN_400f1050
// Address  : 0x400f1050
// Size     : 28 bytes


undefined4 FUN_400f1050(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = func_0x4008c024(param_2);
    uVar1 = FUN_400f0f40(param_1,param_2,uVar1);
  }
  return uVar1;
}

