// Function : FUN_4018a978
// Address  : 0x4018a978
// Size     : 28 bytes


void FUN_4018a978(undefined4 param_1,undefined4 param_2,byte *param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_4018baa4(param_1);
  if (iVar1 != 0) {
    FUN_4018a918(*param_3 & 1,(param_4 & 0xff) >> 5 & 1);
  }
  return;
}

