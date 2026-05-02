// Function : FUN_4014514c
// Address  : 0x4014514c
// Size     : 44 bytes


undefined4 FUN_4014514c(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 0xffffd800;
  }
  else {
    uVar1 = FUN_40144830(param_1,param_2,param_3,1,0,0);
  }
  return uVar1;
}

