// Function : FUN_400f07fc
// Address  : 0x400f07fc
// Size     : 33 bytes


undefined4 FUN_400f07fc(int *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    uVar1 = (**(code **)(*param_1 + 8))(param_1,param_2 & 0xff);
  }
  else {
    uVar1 = FUN_400f0798(param_1,param_2,param_3 & 0xff);
  }
  return uVar1;
}

