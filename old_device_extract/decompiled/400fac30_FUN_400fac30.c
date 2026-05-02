// Function : FUN_400fac30
// Address  : 0x400fac30
// Size     : 29 bytes


undefined4 FUN_400fac30(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0x102;
  if ((param_4 & 0xf) == 0) {
    uVar1 = FUN_400f90c0(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_4);
  }
  return uVar1;
}

