// Function : FUN_40134258
// Address  : 0x40134258
// Size     : 33 bytes


int FUN_40134258(uint *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = -0x3080;
  if (((param_3 != 0) && (param_3 <= *param_1)) &&
     (iVar1 = FUN_4013183c(param_1 + 0xd,param_2,param_3), iVar1 != 0)) {
    iVar1 = iVar1 + -0x3200;
  }
  return iVar1;
}

